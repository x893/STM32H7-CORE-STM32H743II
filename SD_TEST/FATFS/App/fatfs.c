/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file   fatfs.c
  * @brief  Code for fatfs applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
#include "fatfs.h"

uint8_t retSD;    /* Return value for SD */
char SDPath[4];   /* SD logical drive path */
FATFS SDFatFS;    /* File system object for SD logical drive */
FIL SDFile;       /* File object for SD */

/* USER CODE BEGIN Variables */
#include "main.h"
#include "sdmmc.h"
#include "fatfs.h"
#include <stdio.h>

FATFS fs;													/* FatFs文件系统对象 */
FIL file;													/* 文件对象 */
FRESULT f_res;                    /* 文件操作结果 */
UINT fnum;            					  /* 文件成功读写数量 */
BYTE ReadBuffer[1024]={0};        /* 读缓冲区 */
BYTE WriteBuffer[]= "stm32H743 sdmmc2 sdcard read/write test\n";/* 写缓冲区*/  

void printf_fatfs_error(FRESULT fresult);

/* USER CODE END Variables */

void MX_FATFS_Init(void)
{
  /*## FatFS: Link the SD driver ###########################*/
  retSD = FATFS_LinkDriver(&SD_Driver, SDPath);

  /* USER CODE BEGIN Init */
  /* additional user code for init */
  /* USER CODE END Init */
}

/**
  * @brief  Gets Time from RTC
  * @param  None
  * @retval Time in DWORD
  */
DWORD get_fattime(void)
{
  /* USER CODE BEGIN get_fattime */
  return 0;
  /* USER CODE END get_fattime */
}

/* USER CODE BEGIN Application */

void printf_fatfs_error(FRESULT fresult)
{
  switch(fresult)
  {
    case FR_OK:                   //(0)
      printf("》操作成功。\r\n");
    break;
    case FR_DISK_ERR:             //(1)
      printf("！！硬件输入输出驱动出错。\r\n");
    break;
    case FR_INT_ERR:              //(2)
      printf("！！断言错误。\r\n");
    break;
    case FR_NOT_READY:            //(3)
      printf("！！物理设备无法工作。\r\n");
    break;
    case FR_NO_FILE:              //(4)
      printf("！！无法找到文件。\r\n");
    break;
    case FR_NO_PATH:              //(5)
      printf("！！无法找到路径。\r\n");
    break;
    case FR_INVALID_NAME:         //(6)
      printf("！！无效的路径名。\r\n");
    break;
    case FR_DENIED:               //(7)
    case FR_EXIST:                //(8)
      printf("！！拒绝访问。\r\n");
    break;
    case FR_INVALID_OBJECT:       //(9)
      printf("！！无效的文件或路径。\r\n");
    break;
    case FR_WRITE_PROTECTED:      //(10)
      printf("！！逻辑设备写保护。\r\n");
    break;
    case FR_INVALID_DRIVE:        //(11)
      printf("！！无效的逻辑设备。\r\n");
    break;
    case FR_NOT_ENABLED:          //(12)
      printf("！！无效的工作区。\r\n");
    break;
    case FR_NO_FILESYSTEM:        //(13)
      printf("！！无效的文件系统。\r\n");
    break;
    case FR_MKFS_ABORTED:         //(14)
      printf("！！因函数参数问题导致f_mkfs函数操作失败。\r\n");
    break;
    case FR_TIMEOUT:              //(15)
      printf("！！操作超时。\r\n");
    break;
    case FR_LOCKED:               //(16)
      printf("！！文件被保护。\r\n");
    break;
    case FR_NOT_ENOUGH_CORE:      //(17)
      printf("！！长文件名支持获取堆空间失败。\r\n");
    break;
    case FR_TOO_MANY_OPEN_FILES:  //(18)
      printf("！！打开太多文件。\r\n");
    break;
    case FR_INVALID_PARAMETER:    // (19)
      printf("！！参数无效。\r\n");
    break;
  }
}

void sd_card_test()
{
	printf("****** 即将进行测试... ******\r\n");	
	printf("retSD:%d\r\n",retSD);
	if(retSD == 0)
  {
	//在SD卡挂载文件系统，文件系统挂载时会对SD卡初始化
	f_res = f_mount(&fs,(TCHAR const*)SDPath,1);
	printf_fatfs_error(f_res);
    /*----------------------- 格式化测试 ---------------------------*/  
    /* 如果没有文件系统就格式化创建创建文件系统 */
    if(f_res == FR_NO_FILESYSTEM)
    {
      printf("》SD卡还没有文件系统，即将进行格式化...\r\n");
      /* 格式化 */
      f_res=f_mkfs((TCHAR const*)SDPath,0,0,0,0);							
      
      if(f_res == FR_OK)
      {
        printf("》SD卡已成功格式化文件系统。\r\n");
        /* 格式化后，先取消挂载 */
        f_res = f_mount(NULL,(TCHAR const*)SDPath,1);			
        /* 重新挂载	*/			
        f_res = f_mount(&fs,(TCHAR const*)SDPath,1);
      }
      else
      {
        printf("《《格式化失败。》》\r\n");
        while(1);
      }
    }
    else if(f_res!=FR_OK)
    {
      printf("！！SD卡挂载文件系统失败。(%d)\r\n",f_res);
      printf_fatfs_error(f_res);
      while(1);
    }
    else
    {
      printf("》文件系统挂载成功，可以进行读写测试\r\n");
    }
    
    /*----------------------- 文件系统测试：写测试 -----------------------------*/
    /* 打开文件，如果文件不存在则创建它 */
    printf("****** 即将进行文件写入测试... ******\r\n");	
    f_res = f_open(&file, "FatFs.txt",FA_CREATE_ALWAYS | FA_WRITE );
    if ( f_res == FR_OK )
    {
      printf("》打开/创建FatFs读写测试文件.txt文件成功，向文件写入数据。\r\n");
      /* 将指定存储区内容写入到文件内 */
      f_res=f_write(&file,WriteBuffer,sizeof(WriteBuffer),&fnum);
      if(f_res==FR_OK)
      {
        printf("》文件写入成功，写入字节数据：%d\r\n",fnum);
        printf("》向文件写入的数据为：\r\n%s\r\n",WriteBuffer);
      }
      else
      {
        printf("！！文件写入失败：(%d)\r\n",f_res);
      }    
      /* 不再读写，关闭文件 */
      f_close(&file);
    }
    else
    {	
      printf("！！打开/创建文件失败。\r\n");
    }
    
    /*------------------- 文件系统测试：读测试 ------------------------------------*/
    printf("****** 即将进行文件读取测试... ******\r\n");
    f_res = f_open(&file, "FatFs.txt", FA_OPEN_EXISTING | FA_READ); 	 
    if(f_res == FR_OK)
    {
      printf("》打开文件成功。\r\n");
      f_res = f_read(&file, ReadBuffer, sizeof(ReadBuffer), &fnum); 
      if(f_res==FR_OK)
      {
        printf("》文件读取成功,读到字节数据：%d\r\n",fnum);
        printf("》读取得的文件数据为：\r\n%s \r\n", ReadBuffer);	
      }
      else
      {
        printf("！！文件读取失败：(%d)\r\n",f_res);
      }		
    }
    else
    {
      printf("！！打开文件失败。\r\n");
    }
    /* 不再读写，关闭文件 */
    f_close(&file);
    
    /* 不再使用，取消挂载 */
    f_res = f_mount(NULL,(TCHAR const*)SDPath,1);	
  
  /* 注销一个FatFS设备：SD卡 */
    FATFS_UnLinkDriver(SDPath);
	}
	
}

/* USER CODE END Application */
