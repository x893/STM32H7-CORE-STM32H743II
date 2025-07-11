/*
* co_drv.h - contains defines for driver
*
* Copyright (c) 2012-2022 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_drv.h 43757 2022-11-30 11:29:14Z boe $
*
*-------------------------------------------------------------------
*
*
*
*/

/**
* \brief defines for driver
*
* \file co_drv.h - contains defines for driver
*
*/

#ifndef CO_DRV_H
#define CO_DRV_H 1

# define CO_CAN_MAX_DATA_LEN	8u


typedef	void *		LIBDRV_HANDLE_T;

#ifndef CO_CAN_TIMESTAMP_T
# define CO_CAN_TIMESTAMP_T UNSIGNED32
#endif /* CO_CAN_TIMESTAMP_T */


/** flags for CAN Messages from/to driver */
#define	CO_COBFLAG_NONE			((UNSIGNED8)(0u))		/**< none */
#define	CO_COBFLAG_ENABLED		((UNSIGNED8)(1u))		/**< cob enabled/disabled */
#define CO_COBFLAG_EXTENDED		((UNSIGNED8)(1u << 1))	/**< extended id  */
#define	CO_COBFLAG_FD			((UNSIGNED8)(1u << 2))	/**< fd frame */
#define	CO_COBFLAG_RTR			((UNSIGNED8)(1u << 3))	/**< rtr */
#define CO_COBFLAG_IND			((UNSIGNED8)(1u << 4))	/**< msg creates a indication, only valid for TX */


/* datatypes 
-----------------------------------------------------------*/
/** CAN cob structure */
typedef struct {
	UNSIGNED32			canId;			/**< can identifier */
	UNSIGNED32			ignore;			/**< ignore mask for id */
	UNSIGNED16			canChan;		/**< reserved for driver */
	UNSIGNED8			flags;			/**< flags (rtr, extended, enabled, ... */
} CO_CAN_COB_T;


/** CAN receive message structure */
typedef struct {
	UNSIGNED32			canId;			/**< can identifier */
#ifdef CO_CAN_TIMESTAMP_SUPPORTED
	CO_CAN_TIMESTAMP_T	timestamp;		/**< timestamp */
#endif /* CO_CAN_TIMESTAMP_SUPPORTED */
	UNSIGNED8			flags;			/**< flags (rtr, extended, enabled, ... */
	UNSIGNED8			len;			/**< msg len */
	UNSIGNED8			data[CO_CAN_MAX_DATA_LEN];	/**< data */
} CO_CAN_REC_MSG_T;


/** CAN transmit message structure */
typedef struct {
	LIBDRV_HANDLE_T		handle;			/**< library internal handle */
	UNSIGNED32			canId;			/**< can identifier */
	UNSIGNED16			canChan;		/**< reserved for driver */
	UNSIGNED8			flags;			/**< flags (rtr, extended, enabled, ... */
	UNSIGNED8			len;			/**< msg len */
	UNSIGNED8			data[CO_CAN_MAX_DATA_LEN];	/**< data */
} CO_CAN_TR_MSG_T;


/** bittiming table entries */
typedef struct {
	UNSIGNED16 bitRate; 	/**< bitrate in kbit/s */
	UNSIGNED16 pre; 		/**< prescaler */
	UNSIGNED8 prop;			/**< propagation segment */
	UNSIGNED8 seg1; 		/**< segment 1 */
	UNSIGNED8 seg2; 		/**< segment 2 */
} CO_NV_STORAGE CODRV_BTR_T;



/* function prototypes */

EXTERN_DECL void codrvWaitForEvent(UNSIGNED32	msecTimeout);
EXTERN_DECL void codrvWaitForCanEvent(UNSIGNED32	waitTimeOut);
EXTERN_DECL void codrvHardwareInit(void);

/* CAN
-----------------------------------------------------------*/
EXTERN_DECL RET_T	codrvCanInit(UNSIGNED16 bitRate);
EXTERN_DECL RET_T	codrvCanInitWithDev(const char *devName,
						UNSIGNED16 bitRate);
EXTERN_DECL RET_T	codrvCanReInit(UNSIGNED16	bitRate);
EXTERN_DECL RET_T	codrvCanSetBitRate(UNSIGNED16	bitRate);
EXTERN_DECL RET_T	codrvCanStartTransmission(void);
EXTERN_DECL void	codrvCanDriverHandler(void);
EXTERN_DECL RET_T	codrvCanEnable(void);
EXTERN_DECL RET_T	codrvCanDisable(void);
EXTERN_DECL RET_T	codrvCanDeinit(void);
EXTERN_DECL int		codrvGetCanFd(void);


/* QUEUE
-----------------------------------------------------------*/
EXTERN_DECL UNSIGNED8 *coQueueGetReceiveBuffer(
			UNSIGNED32 canId, UNSIGNED8 dataLen, UNSIGNED8 flags
#ifdef CO_CAN_TIMESTAMP_SUPPORTED
			, CO_CAN_TIMESTAMP_T	timestamp
#endif /* CO_CAN_TIMESTAMP_SUPPORTED */
			);
EXTERN_DECL void	coQueueReceiveBufferIsFilled(void);
EXTERN_DECL BOOL_T	coQueueReceiveMessageAvailable(void);
EXTERN_DECL CO_CAN_TR_MSG_T *coQueueGetNextTransmitMessage(void);
EXTERN_DECL void	coQueueMsgTransmitted(const CO_CAN_TR_MSG_T *pBuf);
EXTERN_DECL RET_T	CUSTOMER_TRANSMIT_MESSAGES_CALLBACK(
						UNSIGNED32 canId, UNSIGNED8 len, UNSIGNED8 *buffer);
#ifdef OLD_FIXED_BUFFER
EXTERN_DECL BOOL_T	CUSTOMER_RECEIVE_MESSAGES_CALLBACK(const CO_CAN_REC_MSG_T *pMsg);
#else /* OLD_FIXED_BUFFER */
EXTERN_DECL BOOL_T	CUSTOMER_RECEIVE_MESSAGES_CALLBACK(const CO_CAN_REC_MSG_T *pMsg);
#endif /* OLD_FIXED_BUFFER */

/* GATEWAY
-----------------------------------------------------------*/
EXTERN_DECL void coGatewayTransmitMessage(const CO_CAN_TR_MSG_T *pMsg);
EXTERN_DECL void coQueueRecMsgFromGw(CO_CAN_REC_MSG_T *pMsg);

/* CAN IRQ
-----------------------------------------------------------*/
EXTERN_DECL void codrvCanEnableInterrupt(void);
EXTERN_DECL void codrvCanDisableInterrupt(void);

/* CAN - FullCAN functionality (Acceptance filter)
-----------------------------------------------------------*/
EXTERN_DECL RET_T codrvCanSetFilter(CO_CAN_COB_T *pCanCob);

/* timer
-----------------------------------------------------------*/
EXTERN_DECL RET_T codrvTimerSetup(UNSIGNED32 timerInterval);
EXTERN_DECL RET_T codrvTimerStop(void);

#endif /* CO_DRV_H */

