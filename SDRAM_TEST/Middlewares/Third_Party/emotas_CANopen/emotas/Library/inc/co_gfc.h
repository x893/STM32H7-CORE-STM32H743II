/*
* co_gfc.h - contains the public API for the GFC modul
*
* Copyright (c) 2015-2022 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_gfc.h 43757 2022-11-30 11:29:14Z boe $
*-------------------------------------------------------------------
*
* Changelog:
*
*
*/

/**
* \brief defines and the public API for the GFC modul.
*
* \file co_gfc.h - contains defines for gfc services
*
*/

#ifndef CO_GFC_H
#define CO_GFC_H 1

#include <co_datatype.h>

/** \brief function pointer to gfc function 
 *
 * \return void
 */
typedef void (* CO_EVENT_GFC_T)(void);


/* function prototypes */
EXTERN_DECL RET_T coGfcWriteReq(void);
EXTERN_DECL RET_T coGfcInit(BOOL_T producer, BOOL_T consumer);
EXTERN_DECL RET_T coEventRegister_GFC(CO_EVENT_GFC_T pFunction);

#endif /* CO_GFC_H */
