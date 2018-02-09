/*
 * pll.h
 *
 *  Created on: Jan 24, 2018
 *      Author: Bruno Knopki Nery
 */

#ifndef PLL_H_
#define PLL_H_

#include <stdbool.h>

#define PLL_IN_FREQ_MIN 1000         // Min input frequency in Hz
#define PLL_IN_FREQ_MAX 300000000    // Max input frequency in Hz
#define PLL_OUT_FREQ_MIN 1000        // Min output frequency in Hz
#define PLL_OUT_FREQ_MAX 2000000000  // Max output frequency in Hz
#define PLL_VCO_FREQ_MIN 600000000
#define PLL_VCO_FREQ_MAX 1600000000

struct pllCounters {
	unsigned int M;          // multiplier
	unsigned int N;          // divider
	unsigned int C;          // post-scale divider
};

enum pllError {
	PLL_RETURN_OK = 0,
	PLL_RETURN_FAIL,
	PLL_PARAM_OUTOF_RANGE,
	PLL_MEMORY_ERROR,
	PLL_CALC_ERROR,
	PLL_RECONFIG_ERROR,
	PLL_HW_ERROR
};

enum pllError pllInit(const unsigned int numPlls, const unsigned int* pllAddresses);

enum pllError pllSetInFreq(const unsigned int pllId, const unsigned long inFreq);
enum pllError pllSetOutFreq(const unsigned int pllId, const unsigned long outFreq);

enum pllError pllGetInFreq(const unsigned int pllId, unsigned long* inFreq);
enum pllError pllGetOutFreq(const unsigned int pllId, unsigned long* outFreq);
enum pllError pllGetVcoFreq(const unsigned int pllId, unsigned long* vcoFreq);
enum pllError pllGetCounters(const unsigned int pllId, struct pllCounters* pllCnt);

enum pllError pllReconfigure(const unsigned int pllId);

enum pllError pllIsLocked(const unsigned int pllId, bool* locked);

void pllClose();

#endif /* PLL_H_ */
