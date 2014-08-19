/*
 * (C) Copyright 2003
 * David Mueller ELSOFT AG Switzerland. d.mueller@elsoft.ch
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

/************************************************
 * NAME	    : exynos4.h
 * Version  : 31.3.2003
 *
 * Based on EXYNOS4 User's manual Rev x.x
 ************************************************/

#ifndef __EXYNOS4_H__
#define __EXYNOS4_H__

#define EXYNOS4_ECCSIZE     512
#define EXYNOS4_ECCBYTES    3

enum exynos4_uarts_nr {
    EXYNOS4_UART0,
    EXYNOS4_UART1,
    EXYNOS4_UART2
};

/* EXYNOS4 device base addresses */
#define EXYNOS4_MEMCTL_BASE     0x48000000
#define EXYNOS4_USB_HOST_BASE       0x49000000
#define EXYNOS4_INTERRUPT_BASE      0x4A000000
#define EXYNOS4_DMA_BASE        0x4B000000
#define EXYNOS4_CLOCK_POWER_BASE    0x4C000000
#define EXYNOS4_LCD_BASE        0x4D000000
#define EXYNOS4_NAND_BASE       0x4E000000
#define EXYNOS4_TIMER_BASE      0x51000000
#define EXYNOS4_USB_DEVICE_BASE     0x52000140
#define EXYNOS4_GPIO_BASE       0x56000000
#define EXYNOS4_RTC_BASE        0x57000000
#define EXYNOS4_SDI_BASE        0x5A000000


static inline struct exynos4_memctl *exynos4_get_base_memctl(void)
{
	return (struct exynos4_memctl *)EXYNOS4_MEMCTL_BASE;
}

static inline struct exynos4_usb_host *exynos4_get_base_usb_host(void)
{
	return (struct exynos4_usb_host *)EXYNOS4_USB_HOST_BASE;
}

static inline struct exynos4_interrupt *exynos4_get_base_interrupt(void)
{
	return (struct exynos4_interrupt *)EXYNOS4_INTERRUPT_BASE;
}

static inline struct exynos4_dmas *exynos4_get_base_dmas(void)
{
	return (struct exynos4_dmas *)EXYNOS4_DMA_BASE;
}

static inline struct exynos4_clock_power *exynos4_get_base_clock_power(void)
{
	return (struct exynos4_clock_power *)EXYNOS4_CLOCK_POWER_BASE;
}

static inline struct exynos4_lcd *exynos4_get_base_lcd(void)
{
	return (struct exynos4_lcd *)EXYNOS4_LCD_BASE;
}

static inline struct exynos4_nand *exynos4_get_base_nand(void)
{
	return (struct exynos4_nand *)EXYNOS4_NAND_BASE;
}

static inline struct exynos4_uart
	*exynos4_get_base_uart(enum exynos4_uarts_nr n)
{
	return (struct exynos4_uart *)(EXYNOS4_UART_BASE + (n * 0x4000));
}

static inline struct exynos4_timers *exynos4_get_base_timers(void)
{
	return (struct exynos4_timers *)EXYNOS4_TIMER_BASE;
}

static inline struct exynos4_usb_device *exynos4_get_base_usb_device(void)
{
	return (struct exynos4_usb_device *)EXYNOS4_USB_DEVICE_BASE;
}

static inline struct exynos4_watchdog *exynos4_get_base_watchdog(void)
{
	return (struct exynos4_watchdog *)EXYNOS4_WATCHDOG_BASE;
}

static inline struct exynos4_i2c *exynos4_get_base_i2c(void)
{
	return (struct exynos4_i2c *)EXYNOS4_I2C_BASE;
}

static inline struct exynos4_i2s *exynos4_get_base_i2s(void)
{
	return (struct exynos4_i2s *)EXYNOS4_I2S_BASE;
}

static inline struct exynos4_gpio *exynos4_get_base_gpio(void)
{
	return (struct exynos4_gpio *)EXYNOS4_GPIO_BASE;
}

static inline struct exynos4_rtc *exynos4_get_base_rtc(void)
{
	return (struct exynos4_rtc *)EXYNOS4_RTC_BASE;
}

static inline struct exynos4_adc *exynos4_get_base_adc(void)
{
	return (struct exynos4_adc *)EXYNOS4_ADC_BASE;
}

static inline struct exynos4_spi *exynos4_get_base_spi(void)
{
	return (struct exynos4_spi *)EXYNOS4_SPI_BASE;
}

static inline struct exynos4_sdi *exynos4_get_base_sdi(void)
{
	return (struct exynos4_sdi *)EXYNOS4_SDI_BASE;
}

#endif /*__EXYNOS4_H__*/
