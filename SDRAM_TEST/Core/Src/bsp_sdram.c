#include "bsp_sdram.h"

extern SDRAM_HandleTypeDef hsdram1;

#define sdramHandle hsdram1

/**
  * @brief  Delay for a while
  * @param  Length of delay
  * @retval None
  */
static void SDRAM_delay(__IO uint32_t nCount)
{
	__IO uint32_t index = 0; 
	for(index = (100000 * nCount); index != 0; index--)
	{
	}
}

/**
  * @brief  Initialize the configuration of the SDRAM chip
  * @param  None.
  * @retval None.
  */
void SDRAM_InitSequence(void)
{
	FMC_SDRAM_CommandTypeDef Command;
	uint32_t tmpr = 0;
  
	/* Step 3 --------------------------------------------------------------------*/
	/* Configuration command: Enable the clock provided to SDRAM */
	Command.CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = 0;
	/* Send the command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);

	/* Step 2: Insert 100 us minimum delay */ 
	/* Inserted delay is equal to 1 ms due to systick time base unit (ms) */
	SDRAM_delay(1);
    
	/* Step 5 --------------------------------------------------------------------*/
	/* Configuration command: Precharge all banks */
	Command.CommandMode = FMC_SDRAM_CMD_PALL;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = 0;
	/* Send the command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);   

	/* Step 6 --------------------------------------------------------------------*/
	/* Configuration command: auto refresh */
	Command.CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 4;
	Command.ModeRegisterDefinition = 0;
	/* Send the command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);
  
	/* Step 7 --------------------------------------------------------------------*/
	/* Set the SDRAM register configuration */
	tmpr = (uint32_t)(0
			| SDRAM_MODEREG_BURST_LENGTH_2
			| SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL
			| SDRAM_MODEREG_CAS_LATENCY_3
			| SDRAM_MODEREG_OPERATING_MODE_STANDARD
			| SDRAM_MODEREG_WRITEBURST_MODE_SINGLE
			);

	/* Configuration Commands: Set SDRAM Registers */
	Command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
	Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
	Command.AutoRefreshNumber = 1;
	Command.ModeRegisterDefinition = tmpr;
	/* Send the command */
	HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);

	/* Step 8 --------------------------------------------------------------------*/
	/* Set the refresh counter */
	/* (7.8125 us x Freq) - 20 */
	/* Step 6: Set the refresh rate counter */
	/* Set the device refresh rate */
	HAL_SDRAM_ProgramRefreshRate(&sdramHandle, 824); 
}
