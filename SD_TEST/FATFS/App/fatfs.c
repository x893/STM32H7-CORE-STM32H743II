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

FATFS fs;													/* FatFs�ļ�ϵͳ���� */
FIL file;													/* �ļ����� */
FRESULT f_res;                    /* �ļ�������� */
UINT fnum;            					  /* �ļ��ɹ���д���� */
BYTE ReadBuffer[1024]={0};        /* �������� */
BYTE WriteBuffer[]= "stm32H743 sdmmc2 sdcard read/write test\n";/* д������*/  

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
      printf("�������ɹ���\r\n");
    break;
    case FR_DISK_ERR:             //(1)
      printf("����Ӳ�����������������\r\n");
    break;
    case FR_INT_ERR:              //(2)
      printf("�������Դ���\r\n");
    break;
    case FR_NOT_READY:            //(3)
      printf("���������豸�޷�������\r\n");
    break;
    case FR_NO_FILE:              //(4)
      printf("�����޷��ҵ��ļ���\r\n");
    break;
    case FR_NO_PATH:              //(5)
      printf("�����޷��ҵ�·����\r\n");
    break;
    case FR_INVALID_NAME:         //(6)
      printf("������Ч��·������\r\n");
    break;
    case FR_DENIED:               //(7)
    case FR_EXIST:                //(8)
      printf("�����ܾ����ʡ�\r\n");
    break;
    case FR_INVALID_OBJECT:       //(9)
      printf("������Ч���ļ���·����\r\n");
    break;
    case FR_WRITE_PROTECTED:      //(10)
      printf("�����߼��豸д������\r\n");
    break;
    case FR_INVALID_DRIVE:        //(11)
      printf("������Ч���߼��豸��\r\n");
    break;
    case FR_NOT_ENABLED:          //(12)
      printf("������Ч�Ĺ�������\r\n");
    break;
    case FR_NO_FILESYSTEM:        //(13)
      printf("������Ч���ļ�ϵͳ��\r\n");
    break;
    case FR_MKFS_ABORTED:         //(14)
      printf("���������������⵼��f_mkfs��������ʧ�ܡ�\r\n");
    break;
    case FR_TIMEOUT:              //(15)
      printf("����������ʱ��\r\n");
    break;
    case FR_LOCKED:               //(16)
      printf("�����ļ���������\r\n");
    break;
    case FR_NOT_ENOUGH_CORE:      //(17)
      printf("�������ļ���֧�ֻ�ȡ�ѿռ�ʧ�ܡ�\r\n");
    break;
    case FR_TOO_MANY_OPEN_FILES:  //(18)
      printf("������̫���ļ���\r\n");
    break;
    case FR_INVALID_PARAMETER:    // (19)
      printf("����������Ч��\r\n");
    break;
  }
}

void sd_card_test()
{
	printf("****** �������в���... ******\r\n");	
	printf("retSD:%d\r\n",retSD);
	if(retSD == 0)
  {
	//��SD�������ļ�ϵͳ���ļ�ϵͳ����ʱ���SD����ʼ��
	f_res = f_mount(&fs,(TCHAR const*)SDPath,1);
	printf_fatfs_error(f_res);
    /*----------------------- ��ʽ������ ---------------------------*/  
    /* ���û���ļ�ϵͳ�͸�ʽ�����������ļ�ϵͳ */
    if(f_res == FR_NO_FILESYSTEM)
    {
      printf("��SD����û���ļ�ϵͳ���������и�ʽ��...\r\n");
      /* ��ʽ�� */
      f_res=f_mkfs((TCHAR const*)SDPath,0,0,0,0);							
      
      if(f_res == FR_OK)
      {
        printf("��SD���ѳɹ���ʽ���ļ�ϵͳ��\r\n");
        /* ��ʽ������ȡ������ */
        f_res = f_mount(NULL,(TCHAR const*)SDPath,1);			
        /* ���¹���	*/			
        f_res = f_mount(&fs,(TCHAR const*)SDPath,1);
      }
      else
      {
        printf("������ʽ��ʧ�ܡ�����\r\n");
        while(1);
      }
    }
    else if(f_res!=FR_OK)
    {
      printf("����SD�������ļ�ϵͳʧ�ܡ�(%d)\r\n",f_res);
      printf_fatfs_error(f_res);
      while(1);
    }
    else
    {
      printf("���ļ�ϵͳ���سɹ������Խ��ж�д����\r\n");
    }
    
    /*----------------------- �ļ�ϵͳ���ԣ�д���� -----------------------------*/
    /* ���ļ�������ļ��������򴴽��� */
    printf("****** ���������ļ�д�����... ******\r\n");	
    f_res = f_open(&file, "FatFs.txt",FA_CREATE_ALWAYS | FA_WRITE );
    if ( f_res == FR_OK )
    {
      printf("����/����FatFs��д�����ļ�.txt�ļ��ɹ������ļ�д�����ݡ�\r\n");
      /* ��ָ���洢������д�뵽�ļ��� */
      f_res=f_write(&file,WriteBuffer,sizeof(WriteBuffer),&fnum);
      if(f_res==FR_OK)
      {
        printf("���ļ�д��ɹ���д���ֽ����ݣ�%d\r\n",fnum);
        printf("�����ļ�д�������Ϊ��\r\n%s\r\n",WriteBuffer);
      }
      else
      {
        printf("�����ļ�д��ʧ�ܣ�(%d)\r\n",f_res);
      }    
      /* ���ٶ�д���ر��ļ� */
      f_close(&file);
    }
    else
    {	
      printf("������/�����ļ�ʧ�ܡ�\r\n");
    }
    
    /*------------------- �ļ�ϵͳ���ԣ������� ------------------------------------*/
    printf("****** ���������ļ���ȡ����... ******\r\n");
    f_res = f_open(&file, "FatFs.txt", FA_OPEN_EXISTING | FA_READ); 	 
    if(f_res == FR_OK)
    {
      printf("�����ļ��ɹ���\r\n");
      f_res = f_read(&file, ReadBuffer, sizeof(ReadBuffer), &fnum); 
      if(f_res==FR_OK)
      {
        printf("���ļ���ȡ�ɹ�,�����ֽ����ݣ�%d\r\n",fnum);
        printf("����ȡ�õ��ļ�����Ϊ��\r\n%s \r\n", ReadBuffer);	
      }
      else
      {
        printf("�����ļ���ȡʧ�ܣ�(%d)\r\n",f_res);
      }		
    }
    else
    {
      printf("�������ļ�ʧ�ܡ�\r\n");
    }
    /* ���ٶ�д���ر��ļ� */
    f_close(&file);
    
    /* ����ʹ�ã�ȡ������ */
    f_res = f_mount(NULL,(TCHAR const*)SDPath,1);	
  
  /* ע��һ��FatFS�豸��SD�� */
    FATFS_UnLinkDriver(SDPath);
	}
	
}

/* USER CODE END Application */
