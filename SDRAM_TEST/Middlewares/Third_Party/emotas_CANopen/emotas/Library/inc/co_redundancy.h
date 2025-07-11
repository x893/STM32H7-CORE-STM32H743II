/*
* co_redundancy.h - contains defines for redundancy
*
* Copyright (c) 2022-2022 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_redundancy.h 44611 2023-02-01 08:58:37Z boe $
*-------------------------------------------------------------------
*
*
*
*/

/**
* \brief defines for redundancy services
*
* \file co_redundancy.h - contains defines for redundancy services
*
*/

#ifndef CO_REDUNDANCY_H
#define CO_REDUNDANCY_H 1

#include <co_datatype.h>

#define LINE0	0
#define LINE1	1

typedef enum {
	REDUNDANCY_INFO_BUS_OFF,
	REDUNDANCY_INFO_BUS_ON,
	REDUNDANCY_INFO_TRANSMIT_TIMEOUT,
	REDUNDANCY_INFO_RECEIVE_TIMEOUT,
	REDUNDANCY_INFO_BUFFER_OVERRUN,
} REDUNDANCY_INFO_T;

/** \brief function pointer to redundancy indication
 * \param canLine - CAN line 0 or 1
 * \param redundancyInfo - redundancy information
 * \param para - redundancy parameter depending on redundancy information
 * 
 */
typedef void (* CO_EVENT_REDUNDANCY_T)(UNSIGNED8, REDUNDANCY_INFO_T, UNSIGNED16); /*lint !e960 customer specific parameter names */


/* redundancy functions */
#define CO_COMM_STATE_EVENT				coRedcyCommStateEvent
#define CO_QUEUE_GET_NEXT_TRANSMIT_MSG	coRedcyQueueGetNextTransmitMessage
#define CO_QUEUE_TRANSMITTED			coRedcyQueueMsgTransmitted
#define CO_QUEUE_GET_RECEIVE_BUFFER		coRedcyQueueGetReceiveBuffer
#define CO_QUEUE_RECEIVE_BUFFER_FILLED	coRedcyQueueReceiveBufferIsFilled
#define CODRV_CAN_DRIVER_HANDLER		codrvRedcyCanDriverHandler
#define CODRV_CAN_SET_FILTER			codrvRedcyCanSetFilter

/* driver used functions */
CO_CAN_TR_MSG_T *coRedcyQueueGetNextTransmitMessage(void);
void coRedcyQueueMsgTransmitted(UNSIGNED8 canLine, const CO_CAN_TR_MSG_T *pBuf);
void coRedcyCommStateEvent(CO_COMM_STATE_EVENT_T newEvent);
UNSIGNED8 *coRedcyQueueGetReceiveBuffer(
			UNSIGNED32 canId, UNSIGNED8 dataLen, UNSIGNED8 flags
# ifdef CO_CAN_TIMESTAMP_SUPPORTED
			, CO_CAN_TIMESTAMP_T	timestamp
# endif /* CO_CAN_TIMESTAMP_SUPPORTED */
			);
void	coRedcyQueueReceiveBufferIsFilled(void);

/* public functions */
EXTERN_DECL RET_T codrvRedcyCanStartTransmission(void);
EXTERN_DECL RET_T codrvRedcyCanFdInit(UNSIGNED16 bitRate, UNSIGNED16 dataBitRate);
EXTERN_DECL RET_T codrvRedcyCanEnable(void);
EXTERN_DECL RET_T codrvRedcyCanDisable(void);
EXTERN_DECL void codrvRedcyCanDriverHandler(void);
EXTERN_DECL RET_T codrvRedcyCanSetFilter(CO_CAN_COB_T * pCanCob);

EXTERN_DECL RET_T coEventRegister_REDUNDANCY(CO_EVENT_REDUNDANCY_T pFunction);

#endif /* CO_REDUNDANCY_H */
