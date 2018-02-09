//--pll_control_regs.h----------------------------------------------------------------------------------------------------------------------
#ifndef PLL_CONTROL_REGS_H_
#define PLL_CONTROL_REGS_H_

//--PLL Control Regs and Mask------------------------------------------------------------------------------------------------------------------
#define PLL_MODE_REG			0x00
#define PLL_STATUS_REG			0x01
#define PLL_START_REG			0x02
#define PLL_COUNTER_N_REG		0x03
#define PLL_COUNTER_M_REG		0x04
#define PLL_COUNTER_C_REG		0x05
#define PLL_PHASE_SHIFT_REG		0x06
#define PLL_M_COUNT_FRAC_REG	0x07
#define PLL_BANDWITH_REG		0x08
#define PLL_CHARGE_PUMP_REG		0x09

//--Control Reg-----R/W--
#define	PLL_CONTROL_WAIT_MODE		0
#define PLL_CONTROL_POLLING_MODE	1

//--Status Reg-----R--
#define PLL_STATUS_BUSY				0
#define PLL_STATUS_READY			1

//--Start Reg-----W--
#define PLL_START_RECONF			1

//--Counter C Reg-----R/W--
#define PLL_C_LOW_COUNT_MASK		0xFF
#define PLL_C_LOW_COUNT_SHIFT		0

#define PLL_C_HIGH_COUNT_MASK		0xFF
#define PLL_C_HIGH_COUNT_SHIFT		8

#define PLL_C_BYPASS_MASK			0x01
#define PLL_C_BYPASS_SHIFT			16

#define PLL_C_ODD_DIV_MASK			0x01
#define PLL_C_ODD_DIV_SHIFT			17

#define PLL_C_COUNTER_MASK			0x1F
#define PLL_C_COUNTER_SHIFT			18

#define PLL_C0_COUNTER				0x00
#define PLL_C1_COUNTER				0x01

#endif /*PLL_CONTROL_REGS_H_*/

