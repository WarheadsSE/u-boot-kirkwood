/*
 * Copyright (C) 2012  Peter Schildmann <linux@schildmann.info>
 *
 * Based on guruplug.h originally written by
 * Siddarth Gore <gores@marvell.com>
 * (C) Copyright 2009
 * Marvell Semiconductor <www.marvell.com>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

#ifndef _CONFIG_NSA320_H
#define _CONFIG_NSA320_H

/*
 * Version number information
 */
#define CONFIG_IDENT_STRING	"\nZyXEL NSA320 2-Bay Power Media Server"

/*
 * High Level Configuration Options (easy to change)
 */
#define CONFIG_FEROCEON_88FR131	1	/* CPU Core subversion */
#define CONFIG_KIRKWOOD		1	/* SOC Family Name */
#define CONFIG_KW88F6281	1	/* SOC Name */
#define CONFIG_MACH_NSA320		/* Machine type */
#define CONFIG_MACH_TYPE	MACH_TYPE_NSA320
#define CONFIG_SKIP_LOWLEVEL_INIT	/* disable board lowlevel_init */

/*
 * Misc Configuration Options
 */
#define CONFIG_SHOW_BOOT_PROGRESS 1	/* boot progess display (LED's) */
#define CONFIG_KIRKWOOD_GPIO 1		/* enable GPIO framework */

/*
 * Commands configuration
 */
#define CONFIG_SYS_NO_FLASH		/* Declare no flash (NOR/SPI) */
#include <config_cmd_default.h>
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_ENV
#define CONFIG_CMD_FAT
#define CONFIG_CMD_MII
#define CONFIG_CMD_NAND
#define CONFIG_CMD_PING
#define CONFIG_CMD_USB
#define CONFIG_CMD_IDE

/*
 * mv-common.h should be defined after CMD configs since it used them
 * to enable certain macros
 */
#include "mv-common.h"

#undef CONFIG_SYS_PROMPT	/* previously defined in mv-common.h */
#define CONFIG_SYS_PROMPT	"NSA320> "	/* Command Prompt */

/*
 *  Environment variables configurations
 */
#ifdef CONFIG_CMD_NAND
#define CONFIG_ENV_IS_IN_NAND		1
#define CONFIG_ENV_SECT_SIZE		0x20000		/* 128K */
#else
#define CONFIG_ENV_IS_NOWHERE		1		/* if env in SDRAM */
#endif
/*
 * max 4k env size is enough, but in case of nand
 * it has to be rounded to sector size
 */
#define CONFIG_ENV_SIZE			0x20000		/* 128k */
#define CONFIG_ENV_ADDR			0x120000
#define CONFIG_ENV_OFFSET		0x120000	/* env starts here */

/* ###################################################################### */

/*
 * Default environment variables
 */
/*
#define CONFIG_BOOTCOMMAND \
	"setenv bootargs ${console} ${mtdparts} ${bootargs_root}; "	\
	"ubi part root; " \
	"ubifsmount root; " \
	"ubifsload 0x800000 ${kernel}; " \
	"ubifsload 0x1100000 ${initrd}; " \
	"bootm 0x800000 0x1100000"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"console=console=ttyS0,115200\0" \
	"kernel=/boot/uImage\0" \
	"initrd=/boot/uInitrd\0" \
	"bootargs_root=ubi.mtd=1 root=ubi0:root rootfstype=ubifs ro\0"
*/

#define MTDIDS_DEFAULT			"nand0=kw_nand"
#define MTDPARTS_DEFAULT \
	"mtdparts=kw_nand:" \
	"1m(uboot)," \
	"512k(uboot_env)," \
	"512k(key_store)," \
	"512k(info)," \
	"10m(etc)," \
	"10m(kernel_1)," \
	"0x2fc0000(rootfs_1)," \
	"10m(kernel_2)," \
	"0x2fc0000(rootfs_2)"

/* ###################################################################### */

/*
 * Ethernet Driver configuration
 */
#ifdef CONFIG_CMD_NET
#define CONFIG_MVGBE_PORTS		{1, 0}	/* enable port 0 only */
#define CONFIG_PHY_BASE_ADR		0x1
#define CONFIG_PHY_GIGE
#define CONFIG_NETCONSOLE
#endif /* CONFIG_CMD_NET */

/*
 * SATA Driver configuration
 */
#ifdef CONFIG_MVSATA_IDE
#define CONFIG_SYS_ATA_IDE0_OFFSET      MV_SATA_PORT0_OFFSET
#define CONFIG_SYS_ATA_IDE1_OFFSET      MV_SATA_PORT1_OFFSET
#endif /* CONFIG_MVSATA_IDE */

/*
 * File system
 */
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_FAT
#define CONFIG_CMD_JFFS2
/* #define CONFIG_CMD_UBI */
/* #define CONFIG_CMD_UBIFS */
/* #define CONFIG_RBTREE */

#define CONFIG_MTD_DEVICE               /* needed for mtdparts commands */
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_MTDPARTS
#define CONFIG_LZO

#define CONFIG_OF_LIBFDT		/* enable passing a flattened device tree */

#endif /* _CONFIG_NSA320_H */
