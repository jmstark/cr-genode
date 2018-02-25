/*
 * \brief  CPU state
 * \author Norman Feske
 * \author Stefan Kalkowski
 * \author Martin Stein
 * \date   2011-05-06
 */

/*
 * Copyright (C) 2011-2013 Genode Labs GmbH
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#ifndef _INCLUDE__SPEC__ARM__CPU__CPU_STATE_H_
#define _INCLUDE__SPEC__ARM__CPU__CPU_STATE_H_

/* Genode includes */
#include <base/stdint.h>

namespace Genode {

	struct Cpu_state;
	struct Cpu_state_modes;
}


/**
 * Basic CPU state
 */
struct Genode::Cpu_state
{
	/**
	 * Native exception types
	 */
	enum Cpu_exception {
		RESET                  = 1,
		UNDEFINED_INSTRUCTION  = 2,
		SUPERVISOR_CALL        = 3,
		PREFETCH_ABORT         = 4,
		DATA_ABORT             = 5,
		INTERRUPT_REQUEST      = 6,
		FAST_INTERRUPT_REQUEST = 7,
	};

	/**
	 * Registers
	 */
	addr_t r0, r1, r2, r3, r4, r5, r6,
	       r7, r8, r9, r10, r11, r12; /* general purpose register 0..12 */
	addr_t sp;                        /* stack pointer */
	addr_t lr;                        /* link register */
	addr_t ip;                        /* instruction pointer */
	addr_t cpsr;                      /* current program status register */
	addr_t cpu_exception;             /* last hardware exception */


	/**
	 * Read a general purpose register
	 *
	 * \param id  ID of the targeted register
	 * \param r   Holds register value if this returns 1
	 */
	bool get_gpr(unsigned id, unsigned & r) const
	{
		switch (id) {
		case 0: r = r0; return 1;
		case 1: r = r1; return 1;
		case 2: r = r2; return 1;
		case 3: r = r3; return 1;
		case 4: r = r4; return 1;
		case 5: r = r5; return 1;
		case 6: r = r6; return 1;
		case 7: r = r7; return 1;
		case 8: r = r8; return 1;
		case 9: r = r9; return 1;
		case 10: r = r10; return 1;
		case 11: r = r11; return 1;
		case 12: r = r12; return 1;
		case 13: r = sp; return 1;
		case 14: r = lr; return 1;
		case 15: r = ip; return 1;
		}
		return 0;
	}

	/**
	 * Override a general purpose register
	 *
	 * \param id  ID of the targeted register
	 * \param r   Has been written to register if this returns 1
	 */
	bool set_gpr(unsigned id, unsigned const r)
	{
		switch (id) {
		case 0:  r0  = r; return 1;
		case 1:  r1  = r; return 1;
		case 2:  r2  = r; return 1;
		case 3:  r3  = r; return 1;
		case 4:  r4  = r; return 1;
		case 5:  r5  = r; return 1;
		case 6:  r6  = r; return 1;
		case 7:  r7  = r; return 1;
		case 8:  r8  = r; return 1;
		case 9:  r9  = r; return 1;
		case 10: r10 = r; return 1;
		case 11: r11 = r; return 1;
		case 12: r12 = r; return 1;
		case 13: sp = r; return 1;
		case 14: lr = r; return 1;
		case 15: ip = r; return 1;
		}
		return 0;
	}

};


/**
 * Extend CPU state by banked registers
 */
struct Genode::Cpu_state_modes : Cpu_state
{
	/**
	 * Common banked registers for exception modes
	 */
	struct Mode_state {

		enum Mode {
			UND,   /* Undefined      */
			SVC,   /* Supervisor     */
			ABORT, /* Abort          */
			IRQ,   /* Interrupt      */
			FIQ,   /* Fast Interrupt */
			MAX
		};

		addr_t spsr; /* saved program status register */
		addr_t sp;   /* banked stack pointer */
		addr_t lr;   /* banked link register */
	};

	Mode_state mode[Mode_state::MAX]; /* exception mode registers   */
	addr_t     fiq_r[5];              /* fast-interrupt mode r8-r12 */
};

#endif /* _INCLUDE__SPEC__ARM__CPU__CPU_STATE_H_ */
