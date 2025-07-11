/**
 ******************************************************************************
 * @file    emotas.I-CUBE-CANOPEN.1.3.0
 * @brief   The CANOPEN Application
 ******************************************************************************
 * @attention
 *
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
 *
 ******************************************************************************
 */

/********************************************************************/
/**
* \file
* \brief simple CANopen slave application
*
* This module provides a simple CANopen slave application for evaluation purposes.
* It contains of the CANopen stack initialization
* as well as cyclic CANopen process calls.
*
* Note: Adapt this initialization according to your requirements!
*       Keep the CANopen evaluation library limitations in mind!
*
* \author emotas embedded communication GmbH
*
*/

/* header of standard C - libraries
---------------------------------------------------------------------------*/
/* USER CODE BEGIN standard C - libraries */
#include <stddef.h>
/* USER CODE END standard C - libraries */

/* header of project specific types
---------------------------------------------------------------------------*/
#include <gen_define.h>
#include <co_canopen.h>

#include "stm32h7xx.h"

/* USER CODE BEGIN project headers */

/* USER CODE END project headers */

/* constant definitions
---------------------------------------------------------------------------*/
/* USER CODE BEGIN constant definitions */

/* USER CODE END constant definitions */

/* local defined data types
---------------------------------------------------------------------------*/
/* USER CODE BEGIN local data types */

/* USER CODE END local data types */

/* list of external used functions, if not in headers
---------------------------------------------------------------------------*/
extern void HAL_SYSTICK_IRQHandler(void);
/* USER CODE BEGIN external functions */

/* USER CODE END external functions */

/* list of global defined functions
---------------------------------------------------------------------------*/
/* USER CODE BEGIN global functions */

/* USER CODE END global functions */

/* list of local defined functions
---------------------------------------------------------------------------*/
static RET_T nmtInd(BOOL_T	execute, CO_NMT_STATE_T newState);
static void hbState(UNSIGNED8 nodeId, CO_ERRCTRL_T state,
			CO_NMT_STATE_T nmtState);
static RET_T sdoServerReadInd(BOOL_T execute, UNSIGNED8 sdoNr,
			UNSIGNED16 index, UNSIGNED8 subIndex);
static RET_T sdoServerCheckWriteInd(BOOL_T execute, UNSIGNED8 node,
			UNSIGNED16 index, UNSIGNED8	subIndex, const UNSIGNED8 *pData);
static RET_T sdoServerWriteInd(BOOL_T execute, UNSIGNED8 sdoNr,
			UNSIGNED16 index, UNSIGNED8	subIndex);
static void pdoInd(UNSIGNED16);
static void pdoRecEvent(UNSIGNED16);
static void canInd(CO_CAN_STATE_T);
static void commInd(CO_COMM_STATE_EVENT_T);
static void ledGreenInd(BOOL_T);
static void ledRedInd(BOOL_T);
static void errorHandler(int errorNr);
/* USER CODE BEGIN local functions */

/* USER CODE END local functions */

/* external variables
---------------------------------------------------------------------------*/
extern __IO uint32_t uwTick;
/* USER CODE BEGIN external variables */

/* USER CODE END external variables */

/* global variables
---------------------------------------------------------------------------*/
/* USER CODE BEGIN global variables */

/* USER CODE END global variables */

/* local defined variables
---------------------------------------------------------------------------*/
/* USER CODE BEGIN local variables */

/* USER CODE END local variables */

/***************************************************************************/
/**
* \brief canopen main entry
*
* \param
*	nothing
* \results
*	nothing
*/
void MX_CANopen_Init(void)
{
UNSIGNED8	emcyData[5] = { 1, 2, 3, 4, 5 };
UNSIGNED16 bitRate = 250u;

	/* hardware initialization */
	/* this is function is empty
	 * since STM32CubeMX generated CPU clock and GPIO initialization code */
	codrvHardwareInit();

	/* USER CODE BEGIN INIT BITRATE */
	bitRate = 250u;
	/* USER CODE END INIT BITRATE */

	/* setup the CAN controller setting */
	if (codrvCanInit(bitRate) != RET_OK)  {
		errorHandler(1);
	}

	/* configure SYSTICK to given interval */
	if (codrvTimerSetup(CO_TIMER_INTERVAL) != RET_OK)  {
		errorHandler(2);
	}

	/* CANopen Initialization */
	if (coCanOpenStackInit(NULL) != RET_OK)  {
		printf("error init library\n");
		errorHandler(1);
	}

	/* USER CODE BEGIN INIT INDICATIONS */
	/* register indication functions */
	if (coEventRegister_NMT(nmtInd) != RET_OK)  {
		errorHandler(3);
	}
	if (coEventRegister_ERRCTRL(hbState) != RET_OK)  {
		errorHandler(4);
	}
	if (coEventRegister_SDO_SERVER_READ(sdoServerReadInd) != RET_OK)  {
		errorHandler(5);
	}
	if (coEventRegister_SDO_SERVER_CHECK_WRITE(sdoServerCheckWriteInd) != RET_OK)  {
		errorHandler(6);
	}
	if (coEventRegister_SDO_SERVER_WRITE(sdoServerWriteInd) != RET_OK)  {
		errorHandler(7);
	}
	if (coEventRegister_PDO(pdoInd) != RET_OK)  {
		errorHandler(8);
	}
	if (coEventRegister_PDO_REC_EVENT(pdoRecEvent) != RET_OK)  {
		errorHandler(9);
	}
	if (coEventRegister_LED_GREEN(ledGreenInd) != RET_OK)  {
		errorHandler(10);
	}
	if (coEventRegister_LED_RED(ledRedInd) != RET_OK)  {
		errorHandler(11);
	}
	if (coEventRegister_CAN_STATE(canInd) != RET_OK)  {
		errorHandler(12);
	}
	if (coEventRegister_COMM_EVENT(commInd) != RET_OK)  {
		errorHandler(13);
	}
	/* USER CODE END INIT INDICATIONS */

	/* enable CAN communication */
	if (codrvCanEnable() != RET_OK)  {
		errorHandler(14);
	}

	/* USER CODE BEGIN INIT END */
	/* send emcy message only if we have a valid node-id */
	if (coNmtGetNodeId() != 255) {
		if (coEmcyWriteReq(0x1234, &emcyData[0]) != RET_OK)  {
			errorHandler(15);
		}
	}
	/* USER CODE END INIT END */
}

void MX_CANopen_Process(void)
{
	/* USER CODE BEGIN WHILE 1 */

	/* USER CODE END WHILE 1 */
	while (coCommTask() == CO_TRUE)  {
		/* more CAN messages to process
		 * coCommTask() is called again */
	}
	/* USER CODE BEGIN WHILE 2 */

	/* USER CODE END WHILE 2 */
}

/*********************************************************************/
void HAL_IncTick(void)
{
	/* ST HAL implementation */
	uwTick += HAL_GetTickFreq();

	/* increament counter for timeout calculation */
	coTimerTick();
}

/*********************************************************************/
static RET_T nmtInd(
		BOOL_T	execute,
		CO_NMT_STATE_T	newState
	)
{
	/* USER CODE BEGIN nmtInd */
	printf("nmtInd: New Nmt state %d - execute %d\n", newState, execute);

	return(RET_OK);
	/* USER CODE END nmtInd */
}

/*********************************************************************/
static void pdoInd(
		UNSIGNED16	pdoNr
	)
{
	/* USER CODE BEGIN pdoInd */
	printf("pdoInd: pdo %d received\n", pdoNr);
	/* USER CODE END pdoInd */
}

/*********************************************************************/
static void pdoRecEvent(
		UNSIGNED16	pdoNr
	)
{
	/* USER CODE BEGIN pdoRecEvent */
	printf("pdoRecEvent: pdo %d time out\n", pdoNr);
	/* USER CODE END pdoRecEvent */
}

/*********************************************************************/
static void hbState(
		UNSIGNED8	nodeId,
		CO_ERRCTRL_T state,
		CO_NMT_STATE_T	nmtState
	)
{
	/* USER CODE BEGIN hbState */
	printf("hbInd: HB Event %d node %d nmtState: %d\n", state, nodeId, nmtState);

	return;
	/* USER CODE END hbState */
}

/*********************************************************************/
static RET_T sdoServerReadInd(
		BOOL_T		execute,
		UNSIGNED8	sdoNr,
		UNSIGNED16	index,
		UNSIGNED8	subIndex
	)
{
	/* USER CODE BEGIN sdoServerReadInd */
	printf("sdo server read ind: exec: %d, sdoNr %d, index %x:%d\n",
		execute, sdoNr, index, subIndex);

	// return(RET_INVALID_PARAMETER);
	return(RET_OK);
	/* USER CODE END sdoServerReadInd */
}

/*********************************************************************/
static RET_T sdoServerCheckWriteInd(
		BOOL_T		execute,
		UNSIGNED8	sdoNr,
		UNSIGNED16	index,
		UNSIGNED8	subIndex,
		const UNSIGNED8	*pData
	)
{
	/* USER CODE BEGIN sdoServerCheckWriteInd */
	printf("sdo server check write ind: exec: %d, sdoNr %d, index %x:%d\n",
		execute, sdoNr, index, subIndex);

	// return(RET_INVALID_PARAMETER);
	return(RET_OK);
	/* USER CODE END sdoServerCheckWriteInd */
}

/*********************************************************************/
static RET_T sdoServerWriteInd(
		BOOL_T		execute,
		UNSIGNED8	sdoNr,
		UNSIGNED16	index,
		UNSIGNED8	subIndex
	)
{
	/* USER CODE BEGIN sdoServerWriteInd */
	printf("sdo server write ind: exec: %d, sdoNr %d, index %x:%d\n",
		execute, sdoNr, index, subIndex);

	// return(RET_INVALID_PARAMETER);
	return(RET_OK);
	/* USER CODE END sdoServerWriteInd */
}

/*********************************************************************/
static void canInd(
	CO_CAN_STATE_T	canState
	)
{
	/* USER CODE BEGIN canInd */
	switch (canState)  {
		case CO_CAN_STATE_BUS_OFF:
			printf("CAN: Bus Off\n");
			break;
		case CO_CAN_STATE_BUS_ON:
			printf("CAN: Bus On\n");
			break;
		case CO_CAN_STATE_PASSIVE:
			printf("CAN: Passive\n");
			break;
		default:
			break;
	}
	/* USER CODE END canInd */
}

/*********************************************************************/
static void commInd(
		CO_COMM_STATE_EVENT_T	commEvent
	)
{
	/* USER CODE BEGIN commInd */
	switch (commEvent)  {
		case CO_COMM_STATE_EVENT_CAN_OVERRUN:
			printf("COMM-Event: CAN Overrun\n");
			break;
		case CO_COMM_STATE_EVENT_REC_QUEUE_FULL:
			printf("COMM-Event: Rec Queue Full\n");
			break;
		case CO_COMM_STATE_EVENT_REC_QUEUE_OVERFLOW:
			printf("COMM-Event: Rec Queue Overflow\n");
			break;
		case CO_COMM_STATE_EVENT_REC_QUEUE_EMPTY:
			printf("COMM-Event: Rec Queue Empty\n");
			break;
		case CO_COMM_STATE_EVENT_TR_QUEUE_FULL:
			printf("COMM-Event: Tr Queue Full\n");
			break;
		case CO_COMM_STATE_EVENT_TR_QUEUE_OVERFLOW:
			printf("COMM-Event: Tr Queue Overflow\n");
			break;
		case CO_COMM_STATE_EVENT_TR_QUEUE_EMPTY:
			printf("COMM-Event: Tr Queue Empty\n");
			break;
		default:
			printf("COMM-Event: %d\n", commEvent);
			break;
	}
	/* USER CODE END commInd */
}

/*********************************************************************/
static void ledGreenInd(
		BOOL_T	on
	)
{
	printf("GREEN: %d\n", on);
}

/*********************************************************************/
static void ledRedInd(
		BOOL_T	on
	)
{
	printf("RED: %d\n", on);
}

/*********************************************************************/
static void errorHandler(int errorNr)
{
	// dummy error handler */
	while (1) {};
}

/* USER CODE BEGIN APPLICATION */

/* USER CODE END APPLICATION */

/************************ (C) COPYRIGHT emotas embedded communication GmbH *****END OF FILE****/
