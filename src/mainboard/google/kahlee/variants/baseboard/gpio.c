/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2017 Advanced Micro Devices, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <agesawrapper.h>
#include <baseboard/variants.h>
#include <soc/gpio.h>
#include <soc/smi.h>
#include <soc/southbridge.h>
#include <stdlib.h>

/*
 * These settings were generated by a spreadsheet. If they need to be updated,
 * update the spreadsheet shared with the Grunt development team.
 */
static const GPIO_CONTROL agesa_board_gpios[] = {

	/* GPIO_0 - EC_PCH_PWR_BTN_ODL */
	{ GPIO_0, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_1 - SYS_RST_ODL */
	{ GPIO_1, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_2 - WLAN_PCIE_WAKE_3V3_ODL */
	{ GPIO_2, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_3 - TOUCHSCREEN_INT_3V3_ODL, SCI */
	{ GPIO_3, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_4 - EN_PP3300_WLAN */
	{ GPIO_4, Function0, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_5 - PCH_TRACKPAD_INT_3V3_ODL, SCI */
	{ GPIO_5, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_6 - APU_RST_L / EC_SMI_ODL, SMI */
	{ GPIO_6, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_7 - APU_PWROK_OD */
	{ GPIO_7, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_8 - DDR_ALERT_3V3_L, SCI */
	{ GPIO_8, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_9 - PCH_INT_ODL, SCI */
	{ GPIO_9, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_10 - SLP_S0_L */
	{ GPIO_10, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_11 - Unused (R166) */
	{ GPIO_11, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_12 - Unused (TP126) */
	{ GPIO_12, Function2, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_13 - APU_PEN_PDCT_ODL, SCI */
	{ GPIO_13, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_14 - APU_HP_INT_ODL, SCI */
	{ GPIO_14, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_15 - EC_IN_RW_OD */
	{ GPIO_15, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_16 - USB_C0_OC_L */
	{ GPIO_16, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_17 - USB_C1_OC_L */
	{ GPIO_17, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_18 - USB_A0_OC_ODL */
	{ GPIO_18, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_19 - APU_I2C_SCL3 (Touchscreen) */
	{ GPIO_19, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_20 - APU_I2C_SDA3 (Touchscreen) */
	{ GPIO_20, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_21 - APU_PEN_INT_ODL, SCI */
	{ GPIO_21, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_22 - EC_SCI_ODL */
	{ GPIO_22, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_23 - ACOK_OD */
	/* GPIO_24 - USB_A1_OC_ODL */
	{ GPIO_24, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_25 - SD_CD */
	{ GPIO_25, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_26 - APU_PCIE_RST_L */
	{ GPIO_26, Function0, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_40 - Unused */
	{ GPIO_40, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_42 - S5_MUX_CTRL */
	{ GPIO_42, Function0, FCH_GPIO_OUTPUT_VALUE | FCH_GPIO_OUTPUT_ENABLE },

	/* GPIO_67 - PEN_RESET */
	{ GPIO_67, Function0, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_70 - WLAN_PE_RST */
	{ GPIO_70, Function0, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_74 - LPC_CLK0_EC_R */
	{ GPIO_74, Function0, FCH_GPIO_PULL_DOWN_ENABLE },

	/* GPIO_75 - LPC_CLK1 */
	{ GPIO_75, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_76 - EN_PP3300_TOUCHSCREEN */
	{ GPIO_76, Function0, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_84 - HUB_RST */
	{ GPIO_84, Function1, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_85 - TOUCHSCREEN_RST_1V8 */
	{ GPIO_85, Function1, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_86 - Unused (TP109) */
	{ GPIO_86, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_87 - LPC_SERIRQ */
	{ GPIO_87, Function0,  },

	/* GPIO_88 - LPC_CLKRUN_L */
	{ GPIO_88, Function0,  },

	/* GPIO_90 - EN_PP3300_CAMERA */
	{ GPIO_90, Function0, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_91 - EN_PP3300_TRACKPAD */
	{ GPIO_91, Function1, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_92 - WLAN_PCIE_CLKREQ_3V3_ODL */
	{ GPIO_92, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_93 - Unused (TP129) */
	{ GPIO_93, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_95 - SD_CLK */
	/* GPIO_96 - SD_CMD */
	/* GPIO_97 - SD_D0 */
	/* GPIO_98 - SD_D1 */
	/* GPIO_99 - SD_D2 */
	/* GPIO_100 - SD_D3 */

	/* GPIO_101 - SD_WP_L */
	{ GPIO_101, Function0, FCH_GPIO_PULL_DOWN_ENABLE },

	/* GPIO_102 - EN_SD_SOCKET_PWR */
	{ GPIO_102, Function0, FCH_GPIO_PULL_DOWN_ENABLE },

	/* GPIO_113 - APU_I2C_SCL2 (Pen & Trackpad) */
	{ GPIO_113, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_114 - APU_I2C_SDA2 (Pen & Trackpad) */
	{ GPIO_114, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_115 - Unused (TP127) */
	{ GPIO_115, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_116 - PCIE_EMMC_CLKREQ_L */
	{ GPIO_116, Function0,  },

	/* GPIO_117 - PCH_SPI_CLK_R */

	/* GPIO_118 - PCH_SPI_CS0_L */
	{ GPIO_118, Function0,  },

	/* GPIO_119 - SPK_PA_EN */
	{ GPIO_119, Function2, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_120 - PCH_SPI_MISO */
	/* GPIO_121 - PCH_SPI_MOSI */

	/* GPIO_122 - APU_BIOS_FLASH_WP */
	{ GPIO_122, Function1,  },

	/* GPIO_126 - DMIC_CLK2_EN */
	{ GPIO_126, Function1, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_129 - APU_KBRST_L */
	{ GPIO_129, Function0, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_130 - Unused, SCI */
	{ GPIO_130, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_131 - CONFIG_STRAP3 */
	{ GPIO_131, Function3,  },

	/* GPIO_132 - CONFIG_STRAP4 */
	{ GPIO_132, Function2,  },

	/* GPIO_133 - APU_EDP_BKLTEN (backlight enable) */
	{ GPIO_133, Function1, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_135 - Unused (TP128) */
	{ GPIO_135, Function1, FCH_GPIO_PULL_UP_ENABLE },

	/* GPIO_136 - UART_PCH_RX_DEBUG_TX */
	{ GPIO_136, Function0,  },

	/* GPIO_137 - AUDIO_CLK_EN */
	{ GPIO_137, Function1, FCH_GPIO_OUTPUT_VALUE },

	/* GPIO_138 - UART_PCH_TX_DEBUG_RX */
	{ GPIO_138, Function0,  },

	/* GPIO_139 - CONFIG_STRAP1 */
	{ GPIO_139, Function1,  },

	/* GPIO_140 - I2S_BCLK_R */
	{ GPIO_140, Function0,  },

	/* GPIO_141 - I2S2_DATA_MIC2 */
	{ GPIO_141, Function0,  },

	/* GPIO_142 - CONFIG_STRAP2 */
	{ GPIO_142, Function1,  },

	/* GPIO_143 - I2S2_DATA */
	{ GPIO_143, Function0,  },

	/* GPIO_144 - I2S_LR_R */
	{ GPIO_144, Function0,  },

	/* GPIO_145 - PCH_I2C_AUDIO_SCL */
	{ GPIO_145, Function0,  },

	/* GPIO_146 - PCH_I2C_AUDIO_SDA */
	{ GPIO_146, Function0,  },

	/* GPIO_147 - PCH_I2C_HUB_SCL */
	{ GPIO_147, Function0,  },

	/* GPIO_148 - PCH_I2C_HUB_SDA */
	{ GPIO_148, Function0,  },

	{-1}
};

const __attribute__((weak)) GPIO_CONTROL *get_gpio_table(void)
{
	return agesa_board_gpios;
}

/*
 * GPE setup table must match ACPI GPE ASL
 *  { gevent, gpe, direction, level }
 */
static const struct sci_source gpe_table[] = {

	/* TOUCHSCREEN_INT_3V3_ODL */
	{
		.scimap = 2,
		.gpe = 2,
		.direction = SMI_SCI_LVL_HIGH,
		.level = SMI_SCI_EDG,
	},

	/* PCH_TRACKPAD_INT_3V3_ODL */
	{
		.scimap = 7,
		.gpe = 7,
		.direction = SMI_SCI_LVL_LOW,
		.level = SMI_SCI_EDG,
	},

	/* DDR_ALERT_3V3_L */
	{
		.scimap = 23,
		.gpe = 23,
		.direction = SMI_SCI_LVL_LOW,
		.level = SMI_SCI_LVL,
	},

	/* PCH_INT_ODL */
	{
		.scimap = 22,
		.gpe = 22,
		.direction = SMI_SCI_LVL_LOW,
		.level = SMI_SCI_LVL,
	},

	/* APU_PEN_PDCT_ODL */
	{
		.scimap = 21,
		.gpe = 21,
		.direction = SMI_SCI_LVL_LOW,
		.level = SMI_SCI_LVL,
	},

	/* APU_HP_INT_ODL */
	{
		.scimap = 6,
		.gpe = 6,
		.direction = SMI_SCI_LVL_LOW,
		.level = SMI_SCI_LVL,
	},

	/* APU_PEN_INT_ODL */
	{
		.scimap = 5,
		.gpe = 5,
		.direction = SMI_SCI_LVL_HIGH,
		.level = SMI_SCI_EDG,
	},
};

const __attribute__((weak)) struct sci_source *get_gpe_table(size_t *num)
{
	*num = ARRAY_SIZE(gpe_table);
	return gpe_table;
}

int __attribute__((weak)) variant_get_xhci_oc_map(uint16_t *map)
{
	*map =  USB_OC0 << OC_PORT0_SHIFT; /* USB-C Port0 = OC0 */
	*map |= USB_OC1 << OC_PORT1_SHIFT; /* USB-C Port1 = OC1 */
	*map |= USB_OC_DISABLE << OC_PORT2_SHIFT;
	*map |= USB_OC_DISABLE << OC_PORT3_SHIFT;
	return 0;
}

int __attribute__((weak)) variant_get_ehci_oc_map(uint16_t *map)
{
	*map =  USB_OC2 << OC_PORT0_SHIFT; /* USB-A Port0 = OC2 */
	*map |= USB_OC3 << OC_PORT1_SHIFT; /* USB-A Port1 = OC3 */
	*map |= USB_OC_DISABLE << OC_PORT2_SHIFT;
	*map |= USB_OC_DISABLE << OC_PORT3_SHIFT;
	return 0;
}