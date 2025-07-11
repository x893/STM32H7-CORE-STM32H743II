/*
* co_memcpy.h - contains defines for common memcpy
*
* Copyright (c) 2012-2023 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_memcpy.h 45790 2023-03-09 13:11:34Z boe $
*
*-------------------------------------------------------------------
*
*
*
*/

/**
* \brief defines for common memcpy
*
* \file co_memcpy.h - contains defines for common memcpy
*/

#ifndef CO_MEMCPY_H
#define CO_MEMCPY_H 1

#include <string.h>
#include <co_datatype.h>


/* datatypes */

#ifndef MEMCMP
# define MEMCMP	memcmp
#endif

#ifndef MEMCPY
# define MEMCPY	memcpy
#endif

#ifndef MEMSET
# define MEMSET	memset
#endif

/* function prototypes */

EXTERN_DECL BOOL_T coreMemcpyPack(void *pDest, CO_CONST void *pSrc,
				UNSIGNED32 size, UNSIGNED32	dstOffset,
				CORE_DATA_TYPE_T dType,	UNSIGNED8 bigEndianProtocol);
EXTERN_DECL void coreMemcpyUnpack(void *pDest, CO_CONST void *pSrc,
				UNSIGNED32 size, UNSIGNED32	srcOffs,
				CORE_DATA_TYPE_T dType,	UNSIGNED8 bigEndianProtocol);
EXTERN_DECL BOOL_T coreMemcpy(void *pDest, CO_CONST void *pSrc,
				UNSIGNED32 size, UNSIGNED16 numeric);
EXTERN_DECL INTEGER16 coreMemcmp(CO_CONST void *pDest, CO_CONST void *pSrc,
				UNSIGNED32 size, UNSIGNED16 numeric);

EXTERN_DECL UNSIGNED32 coreMemDataExchange32(UNSIGNED32 src);
EXTERN_DECL UNSIGNED16 coreMemDataExchange16(UNSIGNED16 src);

#endif /* CO_MEMCPY_H */

