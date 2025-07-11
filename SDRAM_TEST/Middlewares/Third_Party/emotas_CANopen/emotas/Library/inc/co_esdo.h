/*
* co_esdo.h - contains defines for sdo services
*
* Copyright (c) 2018-2019 emotas GmbH
*
*-------------------------------------------------------------------
* $Id: co_esdo.h 29114 2019-08-30 15:38:11Z phi $
*
*-------------------------------------------------------------------
*
*
*
*/

/**
* \brief defines for sdo service
*
* \file co_esdo.h - contains defines for esdo service
*/

#ifndef CO_ESDO_H
#define CO_ESDO_H 1

#include <co_datatype.h>

/* datatypes */

/** \brief function pointer to ESDO server event
 * \param execute - execute or test only
 * \param client - nodeId of the client
 * \param index - object index
 * \param subindex - object subindex
 * 
 * \return RET_T
 */
typedef	RET_T (* CO_EVENT_ESDO_SERVER_T)(BOOL_T, UNSIGNED8, UNSIGNED16, UNSIGNED8); /*lint !e960 customer specific parameter names */


/** \brief function pointer to ESDO server write check event
 * \param execute - execute or test only
 * \param client - nodeId of the client
 * \param index - object index
 * \param subindex - object subindex
 * \param pData - pointer to receive buffer
 * 
 * \return RET_T
 */
typedef RET_T (* CO_EVENT_ESDO_SERVER_CHECK_WRITE_T)(BOOL_T, UNSIGNED8, UNSIGNED16, UNSIGNED8, const UNSIGNED8 *); /*lint !e960 customer specific parameter names */

/** \brief function pointer to ESDO server write domain event
 * \param index - object index
 * \param subindex - object subindex
 * \param domainBufSize - actual size at domain buffer
 * \param transferSize - actual transfered size
 * 
 * \return RET_T
 */
typedef RET_T (* CO_EVENT_ESDO_SERVER_DOMAIN_WRITE_T)(UNSIGNED16, UNSIGNED8, UNSIGNED32, UNSIGNED32);

/** \brief function pointer to ESDO server read domain event
* \param index - object index
* \param subindex - object subindex
* \param domainBufSize - actual size at domain buffer
* \param transferSize - actual transfered size
*
* \return RET_T
*/
typedef void(*CO_EVENT_ESDO_SERVER_DOMAIN_READ_T)(UNSIGNED16, UNSIGNED8, UNSIGNED32, UNSIGNED32);

/** \brief function pointer to ESDO client read event
 * \param client - nodeId of the client
 * \param index - object index
 * \param subindex - object subindex
 * \param size - size of received data
 * \param result - result of transfer
 * 
 */
typedef	void (* CO_EVENT_ESDO_CLIENT_READ_T)(UNSIGNED8, UNSIGNED16, UNSIGNED8, UNSIGNED32, UNSIGNED32); /*lint !e960 customer specific parameter names */


/** \brief function pointer to ESDO client write event
 * \param client - nodeId of the client
 * \param index - object index
 * \param subindex - object subindex
 * \param result - result of transfer
 * 
 */
typedef	void (* CO_EVENT_ESDO_CLIENT_WRITE_T)(UNSIGNED8, UNSIGNED16, UNSIGNED8, UNSIGNED32); /*lint !e960 customer specific parameter names */


/** \brief function pointer to ESDO client domain write event
 * \param client - nodeId of the client
 * \param index - object index
 * \param subindex - object subindex
 * \param transfered - bytes transfered
 * \param pointer - pointer to application data
 *
 * \return RET_T
 */
typedef RET_T (*CO_EVENT_SDO_CLIENT_DOMAIN_WRITE_T)(UNSIGNED8, UNSIGNED16, UNSIGNED8, UNSIGNED32, void*); /*lint !e960 customer specific parameter names */


/* \brief function pointer to ESDO queue indication function
 * \param pData - pointer to data
 * \param result - result of sdo transfer
 */
typedef void (* CO_SDO_QUEUE_IND_T)(void *pData, UNSIGNED32 result);

/* function prototypes */
EXTERN_DECL RET_T coEsdoServerInit(void);
EXTERN_DECL RET_T coEventRegister_ESDO_SERVER_READ(CO_EVENT_ESDO_SERVER_T pFunction);
EXTERN_DECL RET_T coEventRegister_ESDO_SERVER_WRITE(CO_EVENT_ESDO_SERVER_T pFunction);
EXTERN_DECL RET_T coEventRegister_ESDO_SERVER_CHECK_WRITE(CO_EVENT_ESDO_SERVER_CHECK_WRITE_T pFunction);
EXTERN_DECL RET_T coEventRegister_ESDO_SERVER_DOMAIN_WRITE(CO_EVENT_ESDO_SERVER_DOMAIN_WRITE_T pFunction);

EXTERN_DECL RET_T coEsdoClientInit(void);
EXTERN_DECL RET_T coEsdoRead(UNSIGNED8 sdoNr, UNSIGNED16 index,
				UNSIGNED8 subIndex, UNSIGNED8 *pData, UNSIGNED32 dataLen,
				UNSIGNED16 numeric, UNSIGNED32 timeout);
EXTERN_DECL RET_T coEsdoWrite(UNSIGNED8 sdoNr, UNSIGNED16 index,
				UNSIGNED8 subIndex, UNSIGNED8 *pData, UNSIGNED32 dataLen,
				UNSIGNED16 numeric, UNSIGNED32 timeout);
EXTERN_DECL RET_T coEsdoDomainWrite(UNSIGNED8 sdoNr,
				UNSIGNED16 index, UNSIGNED8 subIndex,
				UNSIGNED8 *pData, UNSIGNED32 dataLen,
				UNSIGNED32 timeout, UNSIGNED32 nbrMsg,
				CO_EVENT_SDO_CLIENT_DOMAIN_WRITE_T pFunction, void* pFctPara);
EXTERN_DECL RET_T coEsdoQueueAddTransfer(BOOL_T write,
				UNSIGNED8 sdoNr, UNSIGNED16 index, UNSIGNED8 subIndex,
				UNSIGNED8 *pData, UNSIGNED32 dataLen,
				CO_SDO_QUEUE_IND_T	pFct, void *pFctPara, UNSIGNED32 timeOut);
EXTERN_DECL RET_T coEsdoQueueAddOdTransfer(BOOL_T write,
				UNSIGNED8 sdoNr,
				UNSIGNED16 remoteIndex, UNSIGNED8 remoteSubIndex,
				UNSIGNED16 localIndex, UNSIGNED8 localSubIndex,
				CO_SDO_QUEUE_IND_T pFct, void *pFctPara, UNSIGNED32 timeOut);

#ifdef CO_SDO_BLOCK
EXTERN_DECL RET_T coEsdoReadSeg(UNSIGNED8 sdoNr, UNSIGNED16 index,
				UNSIGNED8 subIndex, UNSIGNED8 *pData, UNSIGNED32 dataLen,
				UNSIGNED16 numeric, UNSIGNED32 timeout);
EXTERN_DECL RET_T coEsdoWriteSeg(UNSIGNED8 sdoNr, UNSIGNED16 index,
				UNSIGNED8 subIndex, UNSIGNED8 *pData, UNSIGNED32 dataLen,
				UNSIGNED16 numeric, UNSIGNED32 timeout);
#endif /* CO_SDO_BLOCK */

EXTERN_DECL RET_T coEsdoClientAbortTransfer(UNSIGNED8 sdoNr,
				RET_T errorReason);
				
EXTERN_DECL RET_T coEventRegister_ESDO_CLIENT_READ(CO_EVENT_ESDO_CLIENT_READ_T pFunction);
EXTERN_DECL RET_T coEventRegister_ESDO_CLIENT_WRITE(CO_EVENT_ESDO_CLIENT_WRITE_T pFunction);

EXTERN_DECL RET_T coEventUnregister_ESDO_CLIENT_READ(CO_EVENT_ESDO_CLIENT_READ_T pFunction);
EXTERN_DECL RET_T coEventUnregister_ESDO_CLIENT_WRITE(CO_EVENT_ESDO_CLIENT_WRITE_T pFunction);


EXTERN_DECL RET_T coEsdoServerReadIndCont(UNSIGNED8 sdoNr,
				RET_T result);
EXTERN_DECL RET_T coEsdoServerWriteIndCont(UNSIGNED8 sdoNr,
				RET_T result);


#endif /* CO_ESDO_H */

