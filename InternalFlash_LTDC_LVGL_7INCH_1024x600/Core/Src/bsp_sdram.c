#include "bsp_sdram.h"  
static FMC_SDRAM_CommandTypeDef Command;
extern SDRAM_HandleTypeDef hsdram1;
#define sdramHandle hsdram1
/**
  * @brief  延迟一段时间
  * @param  延迟的时间长度
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
  * @brief  对SDRAM芯片进行初始化配置
  * @param  None. 
  * @retval None.
  */
void SDRAM_InitSequence(void)
{
  uint32_t tmpr = 0;
  
/* Step 3 --------------------------------------------------------------------*/
  /* 配置命令：开启提供给SDRAM的时钟 */
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
  /* 配置命令：对所有的bank预充电 */ 
  Command.CommandMode = FMC_SDRAM_CMD_PALL;
  Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
  Command.AutoRefreshNumber = 1;
  Command.ModeRegisterDefinition = 0;
/* Send the command */
  HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);   
  
/* Step 6 --------------------------------------------------------------------*/
  /* 配置命令：自动刷新 */   
  Command.CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
  Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
  Command.AutoRefreshNumber = 4;
  Command.ModeRegisterDefinition = 0;
 /* Send the command */
  HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);
  
/* Step 7 --------------------------------------------------------------------*/
  /* 设置sdram寄存器配置 */
  tmpr = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_2          |
                   SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
                   SDRAM_MODEREG_CAS_LATENCY_3           |
                   SDRAM_MODEREG_OPERATING_MODE_STANDARD |
                   SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;
  
  /* 配置命令：设置SDRAM寄存器 */
  Command.CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
  Command.CommandTarget = FMC_COMMAND_TARGET_BANK;
  Command.AutoRefreshNumber = 1;
  Command.ModeRegisterDefinition = tmpr;
  /* Send the command */
  HAL_SDRAM_SendCommand(&sdramHandle, &Command, SDRAM_TIMEOUT);
  
/* Step 8 --------------------------------------------------------------------*/

  /* 设置刷新计数器 */
  /* (7.8125 us x Freq) - 20 */
	/* Step 6: Set the refresh rate counter */
  /* Set the device refresh rate */
  HAL_SDRAM_ProgramRefreshRate(&sdramHandle, 824); 

}
