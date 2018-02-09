/*
 * pll_control.c
 *
 *  Created on: Jan 26, 2018
 *      Author: Bruno Knopki Nery
 */

//#include <io.h>
#include "pll_control.h"
#include "pll_control_regs.h"

static inline void pllControlSetReg(const unsigned int pllControlBase, const unsigned int regAddr, const unsigned int newVal) {
	//IOWR(pllControlBase, regAddr, newVal);
}

static inline unsigned int pllControlGetReg(const unsigned int pllControlBase, const unsigned int regAddr) {
	//return IORD(pllControlBase, regAddr);
	return 1;
}

static unsigned int pllControlCalcCountReg(const unsigned int count) {
	unsigned int writeVal = 0;
	unsigned int highCount, lowCount;
	// Find out if it is even of odd division
	if (count % 2) {
		// odd division
		highCount = (count / 2) + 1;
		lowCount = count / 2;
		writeVal = (PLL_C_ODD_DIV_MASK << PLL_C_ODD_DIV_SHIFT) | (highCount << PLL_C_HIGH_COUNT_SHIFT) | lowCount;
	} else {
		// even division
		highCount = count / 2;
		lowCount = highCount;
		writeVal = (highCount << PLL_C_HIGH_COUNT_SHIFT) | lowCount;
	}
	return writeVal;
}

enum pllControlError pllControlReconfig(const unsigned int controllerAddr, const unsigned int N, const unsigned int M, const unsigned int C) {

	unsigned int writeVal = 0;
	unsigned int reconStatus = PLL_STATUS_BUSY;
	unsigned long timeOut = 0;

	// Set Mode Register for polling mode
	pllControlSetReg(controllerAddr, PLL_MODE_REG, PLL_CONTROL_POLLING_MODE);

	// Calculate M counter register
	writeVal = pllControlCalcCountReg(M);
	// Set M register
	pllControlSetReg(controllerAddr, PLL_COUNTER_M_REG, writeVal);

	// Calculate N counter register
	writeVal = pllControlCalcCountReg(N);
	// Set N register
	pllControlSetReg(controllerAddr, PLL_COUNTER_N_REG, writeVal);

	// Calculate C counter register
	writeVal = pllControlCalcCountReg(C);
	// Set C register
	pllControlSetReg(controllerAddr, PLL_COUNTER_C_REG, writeVal);

	// Start reconfiguration
	pllControlSetReg(controllerAddr, PLL_START_REG, PLL_START_RECONF);

	// Wait for reconfiguration to finish
	timeOut = 0;
	while (reconStatus == PLL_STATUS_BUSY) {
		reconStatus = pllControlGetReg(controllerAddr, PLL_STATUS_REG);
		if (timeOut > PLL_CONTROL_RECON_TIMEOUT) {
			return PLL_CONTROLLER_RECONFIG_ERROR;
		}
		timeOut++;
	}

	return PLL_CONTROLLER_RETURN_OK;
}


enum pllControlError pllControlIsLocked(const unsigned int controllerAddr, bool* locked) {

	// read pll status register
	if (pllControlGetReg(controllerAddr, PLL_STATUS_REG) == PLL_STATUS_READY) {
		*locked = true;
	} else {
		*locked = false;
	}
	return PLL_CONTROLLER_RETURN_OK;
}
