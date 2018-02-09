/*
 * pll_control.h
 *
 *  Created on: Jan 26, 2018
 *      Author: Bruno Knopki Nery
 */

#ifndef PLL_CONTROL_H_
#define PLL_CONTROL_H_

#include <stdbool.h>

#define PLL_CONTROL_RECON_TIMEOUT 3000000000  // max number of read cycles of status register

enum pllControlError {
	PLL_CONTROLLER_RETURN_OK = 0,
	PLL_CONTROLLER_RETURN_FAIL,
	PLL_CONTROLLER_RECONFIG_ERROR
};

enum pllControlError pllControlReconfig(const unsigned int controllerAddr, const unsigned int N, const unsigned int M, const unsigned int C);
enum pllControlError pllControlIsLocked(const unsigned int controllerAddr, bool* locked);

#endif /* PLL_CONTROL_H_ */
