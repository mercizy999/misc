/*
 * (C) Copyright 2012 Michal Simek <monstr@monstr.eu>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef __CONFIG_ZYNQ_H
#define __CONFIG_ZYNQ_H

#define CONFIG_ARMV7 /* This is an ARM V7 CPU core */
#define CONFIG_ZYNQ

/* CPU clock */
#define CONFIG_CPU_FREQ_HZ	800000000
#define CONFIG_SYS_HZ		1000

/* Ram */
#define CONFIG_NR_DRAM_BANKS		1

/* hao, changed this accroding to the address where the image is loaded. 
 * Use "info roms" in qemu to see the address */
#define CONFIG_SYS_TEXT_BASE		0x10000
#define CONFIG_SYS_SDRAM_BASE		0
#define CONFIG_SYS_SDRAM_SIZE		0x40000000
#define CONFIG_SYS_MEMTEST_START	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_MEMTEST_END		(CONFIG_SYS_SDRAM_BASE + 0x1000)

/* The following table includes the supported baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE  \
	{300, 600, 1200, 2400, 4800, 9600, 19200, 38400, 57600, 115200, 230400}

#define CONFIG_BAUDRATE		115200

/* XPSS Serial driver */
#define CONFIG_ZYNQ_SERIAL
#define CONFIG_ZYNQ_SERIAL_BASEADDR0	0xE0000000
#define CONFIG_ZYNQ_SERIAL_BAUDRATE0	CONFIG_BAUDRATE
#define CONFIG_ZYNQ_SERIAL_CLOCK0	50000000

/* Ethernet driver */
#define CONFIG_NET_MULTI
#define CONFIG_ZYNQ_GEM
#define CONFIG_ZYNQ_GEM0
#define CONFIG_ZYNQ_GEM_PHY_ADDR0	7

#define CONFIG_ZYNQ_SDHCI
#define CONFIG_ZYNQ_SDHCI0

/* MMC */
#if defined(CONFIG_ZYNQ_SDHCI0) || defined(CONFIG_ZYNQ_SDHCI1)
# define CONFIG_MMC
# define CONFIG_GENERIC_MMC
# define CONFIG_SDHCI
# define CONFIG_ZYNQ_SDHCI
# define CONFIG_CMD_MMC
# define CONFIG_CMD_FAT
# define CONFIG_SUPPORT_VFAT
# define CONFIG_CMD_EXT2
# define CONFIG_DOS_PARTITION
#endif

#define CONFIG_ZYNQ_I2C0

/* I2C */
#if defined(CONFIG_ZYNQ_I2C0) || defined(CONFIG_ZYNQ_I2C1)
# define CONFIG_CMD_I2C
# define CONFIG_ZYNQ_I2C
# define CONFIG_HARD_I2C
# define CONFIG_SYS_I2C_SPEED		100000
# define CONFIG_SYS_I2C_SLAVE		1
#endif

#if defined(CONFIG_ZYNQ_DCC)
# define CONFIG_ARM_DCC
# define CONFIG_CPU_V6 /* Required by CONFIG_ARM_DCC */
#endif

#define CONFIG_ZYNQ_SPI

/* SPI */
#ifdef CONFIG_ZYNQ_SPI
# define CONFIG_SPI_FLASH
# define CONFIG_SPI_FLASH_SST
# define CONFIG_CMD_SF
#endif

/* Enable the PL to be downloaded */
#define CONFIG_FPGA
#define CONFIG_FPGA_XILINX
#define CONFIG_FPGA_ZYNQPL
#define CONFIG_CMD_FPGA

#define CONFIG_BOOTP_SERVERIP
#define CONFIG_BOOTP_BOOTPATH
#define CONFIG_BOOTP_GATEWAY
#define CONFIG_BOOTP_HOSTNAME
#define CONFIG_BOOTP_MAY_FAIL

/* MII and Phylib */
#define CONFIG_MII
#define CONFIG_SYS_FAULT_ECHO_LINK_DOWN
#define CONFIG_PHYLIB
#define CONFIG_PHY_MARVELL

/* Environment */
#define CONFIG_ENV_IS_NOWHERE
#define CONFIG_ENV_SIZE 0x10000

#define CONFIG_SYS_NO_FLASH

#define CONFIG_SYS_MALLOC_LEN		0x400000
#define CONFIG_SYS_INIT_RAM_ADDR	CONFIG_SYS_SDRAM_BASE
#define CONFIG_SYS_INIT_RAM_SIZE	CONFIG_SYS_MALLOC_LEN
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_INIT_RAM_ADDR + \
						CONFIG_SYS_INIT_RAM_SIZE - \
						GENERATED_GBL_DATA_SIZE)

#define CONFIG_SYS_PROMPT	"U-Boot> "
#define CONFIG_SYS_CBSIZE	256 /* Console I/O Buffer Size */
#define CONFIG_SYS_PBSIZE	(CONFIG_SYS_CBSIZE + \
					sizeof(CONFIG_SYS_PROMPT) + 16)

#define CONFIG_SYS_LOAD_ADDR	0
#define CONFIG_SYS_MAXARGS	15 /* max number of command args */
#define CONFIG_SYS_LONGHELP
#define CONFIG_AUTO_COMPLETE
#define CONFIG_CMDLINE_EDITING

#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "

/* boot argument */
#define CONFIG_ETHADDR 00:e0:0c:bc:e5:61
#define CONFIG_IPADDR 192.168.2.102
#define CONFIG_NETMASK 255.255.255.0
#define CONFIG_SERVERIP 192.168.2.100
#define CONFIG_GATEWAYIP 192.168.2.100

#define CONFIG_RAMBOOT_COMMAND \
	"tftp $loadaddr $loadfile;" \
	"tftp $ramdiskaddr $ramdiskfile;" \
	"tftp $dtbaddr $dtbfile;" \
	"bootm $loadaddr $ramdiskaddr $dtbaddr"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"netdev=eth0\0" \
	"loadaddr=3d000000\0" \
	"bootfile=uImage\0" \
	"ramdiskaddr=3e000000\0" \
	"ramdiskfile=uRamDisk\0" \
	"dtbaddr=3f000000\0" \
	"dtbfile=zynq.dtb" \

#define CONFIG_BOOTCOMMAND CONFIG_RAMBOOT_COMMAND
#define CONFIG_BOOTDELAY		1
#define CONFIG_ZERO_BOOTDELAY_CHECK

/* OF */
#define CONFIG_FIT
#define CONFIG_OF_LIBFDT

/* Commands */
#include <config_cmd_default.h>

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MII

#endif /* __CONFIG_ZYNQ_H */
