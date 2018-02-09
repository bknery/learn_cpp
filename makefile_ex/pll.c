/*
 * pll.c
 *
 *  Created on: Jan 24, 2018
 *      Author: Bruno Knopki Nery
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "pll.h"

#include "pll_control.h"

#define PLL_MAX_M 256
#define PLL_MAX_N 256
#define PLL_MAX_C 512

#define PLL_MAX_CONTROLLERS 16

struct pll {
	unsigned long inFreq;
	unsigned long outFreq;
	unsigned long vcoFreq;
	struct pllCounters counters;
	unsigned int controllerAddr;
};

static struct pll* plls_; // array of data structures of the plls
static unsigned int numPllControllers_;

enum pllError pllInit(const unsigned int numPlls, const unsigned int* pllAddresses) {

	if (numPlls > PLL_MAX_CONTROLLERS) {
		return PLL_PARAM_OUTOF_RANGE;
	}
	numPllControllers_ = numPlls;

	// check for null pointer
	if (pllAddresses == NULL) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	// allocate memory for the plls
	plls_ = calloc(numPlls, sizeof(struct pll));
	if (plls_ == NULL) {
		return PLL_MEMORY_ERROR;
	}

	// set pll addresses
	for (int i = 0; i < numPlls; i++) {
		plls_[i].controllerAddr = pllAddresses[i];
	}

	return PLL_RETURN_OK;
}

enum pllError pllSetInFreq(const unsigned int pllId, const unsigned long inFreq) {

	if (pllId > numPllControllers_) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	if ((inFreq < PLL_IN_FREQ_MIN) || (inFreq > PLL_IN_FREQ_MAX)) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	plls_[pllId].inFreq = inFreq;

	return PLL_RETURN_OK;
}

enum pllError pllSetOutFreq(const unsigned int pllId, const unsigned long outFreq) {

	if (pllId > numPllControllers_) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	if ((outFreq < PLL_OUT_FREQ_MIN) || (outFreq > PLL_OUT_FREQ_MAX)) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	plls_[pllId].outFreq = outFreq;

	return PLL_RETURN_OK;
}

enum pllError pllGetInFreq(const unsigned int pllId, unsigned long* inFreq) {

	if (pllId > numPllControllers_) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	*inFreq = plls_[pllId].inFreq;

	return PLL_RETURN_OK;
}

enum pllError pllGetOutFreq(const unsigned int pllId, unsigned long* outFreq) {

	if (pllId > numPllControllers_) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	*outFreq = plls_[pllId].outFreq;

	return PLL_RETURN_OK;
}

enum pllError pllGetVcoFreq(const unsigned int pllId, unsigned long* vcoFreq) {

	if (pllId > numPllControllers_) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	*vcoFreq = plls_[pllId].vcoFreq;

	return PLL_RETURN_OK;
}

enum pllError pllGetCounters(const unsigned int pllId, struct pllCounters* pllCnt) {

	if (pllId > numPllControllers_) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	pllCnt->C = plls_[pllId].counters.C;
	pllCnt->M = plls_[pllId].counters.M;
	pllCnt->N = plls_[pllId].counters.N;

	return PLL_RETURN_OK;
}

static enum pllError pllCalcSettings(const unsigned int pllId) {

	unsigned int m, n, c;
	unsigned long calcOut = 0;
	unsigned long vcoFreq = 0;
	unsigned int calcCycles = 0;
	unsigned long inFreq = plls_[pllId].inFreq;
	unsigned long outFreq = plls_[pllId].outFreq;

	for (c = 1; c < PLL_MAX_C; c++) {
		for (n = 1; n < PLL_MAX_N; n++) {
			for (m = 1; m < PLL_MAX_M; m++) {
				// calc output frequency
				calcOut = (inFreq * m) / (n * c);
				calcCycles++;
				if (calcOut == outFreq) {
					// Ok: calculated frequency = output frequency
					// Now calculate Vco frequency
					vcoFreq = (inFreq / n) * m;
					//printf("VCO freq = %d\n", vcoFreq);
					// check if vco frequency is within range
					if ((vcoFreq >= PLL_VCO_FREQ_MIN) && (vcoFreq <= PLL_VCO_FREQ_MAX)) {
						// calculation successful. Fill up counters values
						plls_[pllId].counters.M = m;
						plls_[pllId].counters.N = n;
						plls_[pllId].counters.C = c;
						plls_[pllId].vcoFreq = vcoFreq;
						//printf("Calculation cycles = %d\n", calcCycles);
						return PLL_RETURN_OK;
					}
				}
			}
		}
	}

	// calculation failed
	plls_[pllId].counters.M = 1;
	plls_[pllId].counters.N = 1;
	plls_[pllId].counters.C = 1;
	plls_[pllId].vcoFreq = 0;
	return PLL_CALC_ERROR;
}

enum pllError pllReconfigure(const unsigned int pllId) {

	if (pllId > numPllControllers_) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	if ((plls_[pllId].inFreq < PLL_IN_FREQ_MIN) || (plls_[pllId].inFreq > PLL_IN_FREQ_MAX)) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	if ((plls_[pllId].outFreq < PLL_OUT_FREQ_MIN) || (plls_[pllId].outFreq > PLL_OUT_FREQ_MAX)) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	// calculate pll counters and vco frequency
	if (pllCalcSettings(pllId) != PLL_RETURN_OK) {
		return PLL_CALC_ERROR;
	}

	// pll counters calculation successful
	// set pll controller registers
	if (pllControlReconfig(plls_[pllId].controllerAddr, plls_[pllId].counters.N, plls_[pllId].counters.M, plls_[pllId].counters.C) != 0) {
		return PLL_RECONFIG_ERROR;
	}

	return PLL_RETURN_OK;
}

enum pllError pllIsLocked(const unsigned int pllId, bool* locked) {

	if (pllId > numPllControllers_) {
		return PLL_PARAM_OUTOF_RANGE;
	}

	if (pllControlIsLocked(plls_[pllId].controllerAddr, locked) != 0) {
		return PLL_HW_ERROR;
	}

	return PLL_RETURN_OK;
}

void pllClose() {

	// free memory
	free(plls_);
}
