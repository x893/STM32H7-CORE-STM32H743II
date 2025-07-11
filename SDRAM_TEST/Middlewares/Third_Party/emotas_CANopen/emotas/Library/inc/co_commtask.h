/*
* co_commtask.h - contains defines for communication services
*
* Copyright (c) 2012-2022 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_commtask.h 44216 2023-01-03 11:44:07Z boe $
*-------------------------------------------------------------------
*
*
*
*/

/**
* \brief defines for communication services
*
* \file co_commtask.h - contains defines for communication services
* of the CANopen/J1939/rawcan library
*
*/

#ifndef CO_COM_TASK_H
#define CO_COM_TASK_H 1

#include <co_datatype.h>


/* datatypes */


/**
* CAN states
*/
typedef enum {
	CO_CAN_STATE_BUS_OFF,			/**< CAN bus state is bus off */
	CO_CAN_STATE_BUS_ON,			/**< CAN bus state is bus on */
	CO_CAN_STATE_PASSIVE,			/**< CAN bus state is passive */
	CO_CAN_STATE_UNCHANGED			/**< CAN bus state is unchanged */
} CO_CAN_STATE_T;

/**
* Communication state events
*/
typedef enum {
	CO_COMM_STATE_EVENT_NONE,				/**< no event */
	CO_COMM_STATE_EVENT_BUS_OFF,			/**< bus off (only used internal) */
	CO_COMM_STATE_EVENT_BUS_OFF_RECOVERY,	/**< recvovery from bus off (only used internal) */
	CO_COMM_STATE_EVENT_BUS_ON,				/**< bus on (only used internal) */
	CO_COMM_STATE_EVENT_PASSIVE,			/**< can passive (only used internal) */
	CO_COMM_STATE_EVENT_ACTIVE,				/**< can active (only used internal) */
	CO_COMM_STATE_EVENT_CAN_OVERRUN,		/**< can overrun */
	CO_COMM_STATE_EVENT_REC_QUEUE_FULL,		/**< receice queue full */
	CO_COMM_STATE_EVENT_REC_QUEUE_OVERFLOW,	/**< receive queue overflow */
	CO_COMM_STATE_EVENT_REC_QUEUE_EMPTY,	/**< receice queue empty */
	CO_COMM_STATE_EVENT_TR_QUEUE_FULL,		/**< transmit queue full */
	CO_COMM_STATE_EVENT_TR_QUEUE_OVERFLOW,	/**< transmit queue overflow */
	CO_COMM_STATE_EVENT_TR_QUEUE_EMPTY,		/**< transmit queue emty */
	CO_COMM_STATE_EVENT_DRV_ERROR			/**< generic driver error */
} CO_COMM_STATE_EVENT_T;


/**
* Communication task events
*/
typedef enum {
	CO_COMMTASK_EVENT_TIMER,
	CO_COMMTASK_EVENT_MSG_AVAIL,
	CO_COMMTASK_EVENT_NEW_EVENT
} CO_COMMTASK_EVENT_T;


/** \brief function pointer to CAN state indication function 
 * \param canState - new CAN state
 * 
 * Provides a new CAN controller state like Bus on, Bus off, error passive
 *
 */
typedef void (* CO_EVENT_CAN_STATE_T)(CO_CAN_STATE_T);	/*lint !e960 Function pointer without parameter names */


/** \brief function pointer to Communication state event indication function 
 * \param commState - new communication state
 * 
 * Provides new communication states like buffer state, CAN working state
 *	CO_COMM_STATE_EVENT_REC_QUEUE_FULL
 *	CO_COMM_STATE_EVENT_REC_QUEUE_OVERFLOW
 *	CO_COMM_STATE_EVENT_REC_QUEUE_EMPTY
 *	CO_COMM_STATE_EVENT_TR_QUEUE_FULL
 *	CO_COMM_STATE_EVENT_TR_QUEUE_OVERFLOW
 *	CO_COMM_STATE_EVENT_TR_QUEUE_EMPTY
 *	CO_COMM_STATE_EVENT_CAN_OVERRUN
 * CAN controller states are only signaled by CO_EVENT_CAN_STATE_T
 *
 */
typedef void (* CO_EVENT_COMM_T)(CO_COMM_STATE_EVENT_T);  /*lint !e960 Function pointer without parameter names */


/* function prototypes */
EXTERN_DECL BOOL_T coCommTask(void);
EXTERN_DECL BOOL_T coCommTaskCheck(void);
#ifdef CO_REDUNDANCY
EXTERN_DECL void coCommStateEvent(CO_COMM_STATE_EVENT_T newEvent);
#else /* CO_REDUNDANCY */
EXTERN_DECL void coCommStateEvent(CO_COMM_STATE_EVENT_T newEvent);
#endif /* CO_REDUNDANCY */
EXTERN_DECL RET_T coEventRegister_COMM_EVENT(CO_EVENT_COMM_T pFunction);
EXTERN_DECL RET_T coEventRegister_CAN_STATE(CO_EVENT_CAN_STATE_T pFunction);
EXTERN_DECL CO_INLINE void coCommTaskSet(CO_COMMTASK_EVENT_T event);
EXTERN_DECL void coQueueInit(void);
EXTERN_DECL UNSIGNED32 coQueueGetTransBufFillState(void);

#endif /* CO_COM_TASK_H */

