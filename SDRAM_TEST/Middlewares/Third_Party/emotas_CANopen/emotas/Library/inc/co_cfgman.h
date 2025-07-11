/*
* co_cfgman.h - contains defines for configuration manager services
*
* Copyright (c) 2014-2022 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_cfgman.h 41920 2022-09-01 10:38:32Z boe $
*-------------------------------------------------------------------
*
*
*
*/

/**
* \brief defines for config manager services
*
* \file co_cfgman.h - contains defines for cfgman services
*
*/

#ifndef CO_CFG_MAN_H
#define CO_CFG_MAN_H 1

#include <co_datatype.h>


/* constant */


/**
* CO_CFG_TRANSFER_T state
*/
typedef enum {
	CO_CFG_TRANSFER_FINISHED,	/**< transfer finished ok */
	CO_CFG_TRANSFER_ABORT,		/**< transfer abort by SDO server */
	CO_CFG_TRANSFER_ERROR		/**< transfer error by start SDO client */
} CO_CFG_TRANSFER_T;


/** \brief function pointer to configuration manager
 * \param type - result type
 * \param sdoNr - sdo number
 * \param index - object index
 * \param subindex - object subindex
 * \param reason - error reason
 * 
 */
typedef void (* CO_EVENT_CFG_MANAGER_T)(CO_CFG_TRANSFER_T, UNSIGNED8, UNSIGNED16, UNSIGNED8, UNSIGNED32); /*lint !e960 customer specific parameter names */



/* function prototypes */
EXTERN_DECL RET_T	coCfgStart(
			UNSIGNED8 sdoNr, UNSIGNED8	srvNodeId,
			UNSIGNED8 *pBuf, UNSIGNED32	bufLen, UNSIGNED32	sdoTimeOut);
EXTERN_DECL RET_T	coCfgConvToConcise(char *pDcfData,
			UNSIGNED8 *pConsBuf, UNSIGNED32 *pConsBufLen);
EXTERN_DECL RET_T	coEventRegister_CFG_MANAGER(CO_EVENT_CFG_MANAGER_T pFct);

#endif /* CO_CFG_MAN_H */

