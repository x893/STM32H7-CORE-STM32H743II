/*
* co_candebug.h - contains defines for can debug
*
* Copyright (c) 2012-2022 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_candebug.h 43757 2022-11-30 11:29:14Z boe $
*-------------------------------------------------------------------
*
*
*/

/**
* \brief defines for can debug
*
* \file co_candebug.h - contains defines for can debug services
*
*/

#ifndef CO_CAN_DEBUG_H
#define CO_CAN_DEBUG_H 1

#include <co_datatype.h>


/* constant */

/* function prototypes */
EXTERN_DECL RET_T coCanDebugPrint(UNSIGNED32 canId,
			UNSIGNED8 dataLen, const UNSIGNED8 *pData);


#endif /* CO_CAN_DEBUG_H */
