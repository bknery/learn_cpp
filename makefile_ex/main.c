/*
 * main.c
 *
 *  Created on: Jan 24, 2018
 *      Author: Bruno Knopki Nery
 */

#include <stdio.h>
#include <stdbool.h>
#include "pll.h"

#define MODULE_NUM_INTEL_PLLS 8
#define PLLRECONFIG_0_BASE 101
#define PLLRECONFIG_1_BASE 102
#define PLLRECONFIG_2_BASE 103
#define PLLRECONFIG_3_BASE 104
#define PLLRECONFIG_4_BASE 105
#define PLLRECONFIG_5_BASE 106
#define PLLRECONFIG_6_BASE 107
#define PLLRECONFIG_7_BASE 108

static const unsigned int pllAddresses[MODULE_NUM_INTEL_PLLS] = {
		PLLRECONFIG_0_BASE,
		PLLRECONFIG_1_BASE,
		PLLRECONFIG_2_BASE,
		PLLRECONFIG_3_BASE,
		PLLRECONFIG_4_BASE,
		PLLRECONFIG_5_BASE,
		PLLRECONFIG_6_BASE,
		PLLRECONFIG_7_BASE
};

static const unsigned long pllInFreqs[MODULE_NUM_INTEL_PLLS] = {
		100000000,
		100000000,
		200000000,
		200000000,
		200000000,
		200000000,
		200000000,
		200000000
};

static const unsigned long pllOutFreqs[MODULE_NUM_INTEL_PLLS] = {
		38400000,
		24000000,
		12000000,
		4800000,
		9600000,
		19200000,
		48000000,
		76800000
};

int main() {

	enum pllError result = PLL_RETURN_OK;
	unsigned long inFreq = 0;
	unsigned long outFreq = 0;
	unsigned long vcoFreq = 0;
	bool locked = false;
	struct pllCounters pllCnt;

	result = pllInit(MODULE_NUM_INTEL_PLLS, pllAddresses);
	if (result != PLL_RETURN_OK) {
		printf("ERROR initializing PLLs. Error code = %d\n", result);
	}

	for (int i = 0; i < MODULE_NUM_INTEL_PLLS; i++) {
		// set input and output frequencies
		result = pllSetInFreq(i, pllInFreqs[i]);
		if (result != PLL_RETURN_OK) {
			printf("ERROR Setting pll %d input frequency. Error code = %d\n", i, result);
		}
		result = pllSetOutFreq(i, pllOutFreqs[i]);
		if (result != PLL_RETURN_OK) {
			printf("ERROR Setting pll %d output frequency. Error code = %d\n", i, result);
		}

		// reconfigure plls
		result = pllReconfigure(i);
		if (result != PLL_RETURN_OK) {
			printf("ERROR Reconfiguring pll %d. Error code = %d\n", i, result);
		}

		// check plls lock
		result = pllIsLocked(i, &locked);
		if (result != PLL_RETURN_OK) {
			printf("ERROR Checking pll %d lock. Error code = %d\n", i, result);
		}

		if (locked == true) {
			printf("PLL %d locked.\n", i);
		} else {
			printf("PLL %d NOT locked.\n", i);
		}

		printf("PLL %d:\n", i);
		pllGetInFreq(i, &inFreq);
		printf(" input frequency = %d Hz\n", (unsigned int)inFreq);
		pllGetOutFreq(i, &outFreq);
		printf(" output frequency = %d Hz\n", (unsigned int)outFreq);
		pllGetCounters(i, &pllCnt);
		printf(" M = %d\n", pllCnt.M);
		printf(" N = %d\n", pllCnt.N);
		printf(" C = %d\n", pllCnt.C);
		pllGetVcoFreq(i, &vcoFreq);
		printf(" VCO frequency = %d\n", (unsigned int)vcoFreq);
		printf("\n");
	}

	pllClose();

	return 0;
}
