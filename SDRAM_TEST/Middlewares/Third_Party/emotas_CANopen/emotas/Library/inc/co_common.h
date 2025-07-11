/*
* co_common.h - contains common defines
*
* Copyright (c) 2021-2023 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_common.h 47441 2023-06-27 11:05:15Z boe $
*-------------------------------------------------------------------
*
*
*/

/**
* \brief common defines
*
* \file co_common.h - contains common defines for all services
*
* This header inludes defines for all services of the CAN library.
* It can be included instead of header files of each service.
*
*/

#ifndef CO_COMMON_H
#define CO_COMMON_H 1

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#include <co_datatype.h>
#include <co_commtask.h>
#include <co_drv.h>
#include <co_timer.h>
#ifdef CO_USER_EXTENSION_SUPPORTED
# include <co_user.h>
#endif /* CO_USER_EXTENSION_SUPPORTED */


#define CORE_STACK_VERSION	0x010005ul


#ifndef CO_HANDLE_WATCHDOG
# define CO_HANDLE_WATCHDOG
#endif /* CO_HANDLE_WATCHDOG */

/* protocol types  */
typedef UNSIGNED16	MP_PROTOCOL_TYPE_T;
#define MP_PROT_TYPE_UNKNOWN		(MP_PROTOCOL_TYPE_T)0x0000
#define MP_PROT_TYPE_J1939			(MP_PROTOCOL_TYPE_T)0x0001
#define MP_PROT_TYPE_RAWCAN			(MP_PROTOCOL_TYPE_T)0x0002
#define MP_PROT_TYPE_CANOPEN		(MP_PROTOCOL_TYPE_T)0x0004
#define MP_PROT_TYPE_UDS			(MP_PROTOCOL_TYPE_T)0x0008


/**
* common line parameter definition 
*
* defines number of line parameter for services 
*/

#define CO_COMMON_INIT_STRUCT_VERSION	0x0001u

typedef struct  {
	UNSIGNED16		structVersion;
	UNSIGNED16		recBufferCnt[1];
	UNSIGNED16		trBufferCnt[1];
	UNSIGNED16		cobCnt[1];
	MP_PROTOCOL_TYPE_T	protocolType[1];
#ifdef ISOTP_SUPPORTED
	UNSIGNED16		isotpClientCnt[1];
	UNSIGNED16		isotpServerCnt[1];
#endif /* ISOTP_SUPPORTED */
} CO_COMMON_INIT_VAL_T;

 


/* function prototypes */

RET_T commonStackInit(const CO_COMMON_INIT_VAL_T *pCommonInitVals);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* CO_COMMON_H */
