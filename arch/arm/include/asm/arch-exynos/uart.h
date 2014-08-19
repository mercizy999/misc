/*
 * (C) Copyright 2009 Samsung Electronics
 * Minkyu Kang <mk7.kang@samsung.com>
 * Heungjun Kim <riverful.kim@samsung.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __ASM_ARCH_UART_H_
#define __ASM_ARCH_UART_H_

#ifndef __ASSEMBLY__

/* baudrate rest value */
union br_rest {
	unsigned short	slot;		/* udivslot */
	unsigned char	value;		/* ufracval */
};

struct exynos4_uart {
	unsigned int	ulcon;
	unsigned int	ucon;
	unsigned int	ufcon;
	unsigned int	umcon;
	unsigned int	utrstat;
	unsigned int	uerstat;
	unsigned int	ufstat;
	unsigned int	umstat;
	unsigned char	utxh;
	unsigned char	res1[3];
	unsigned char	urxh;
	unsigned char	res2[3];
	unsigned int	ubrdiv;
	union br_rest	rest;
	unsigned char	res3[0xffd0];
};

static inline int exynos4_uart_divslot(void)
{
	return 0;
}

#endif	/* __ASSEMBLY__ */

#endif
