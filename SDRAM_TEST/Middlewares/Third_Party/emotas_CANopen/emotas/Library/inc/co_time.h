/*
* co_time.h - contains defines for time services
*
* Copyright (c) 2012-2022 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_time.h 43757 2022-11-30 11:29:14Z boe $
*-------------------------------------------------------------------
*
* Changelog:
*
*
*/

/**
* \brief defines for time services
*
* \file co_time.h - contains defines for time services
*
*/

#ifndef CO_TIME_H
#define CO_TIME_H 1

#include <co_datatype.h>


/* constant */
#define CO_TIME_PRODUCER_BIT	0x40000000ul
#define CO_TIME_CONSUMER_BIT	0x80000000ul


/**
* TIME_OF_DAY structure
*/
typedef struct {
	UNSIGNED32	msec;			/**< milliseconds after midnight */
	UNSIGNED16	days;			/**< days after 1st january of 1984 */
} CO_TIME_T;


/** \brief function pointer to time function 
 *
 * \param pTime - time of day structure
 * 
 * \return void
 */
typedef void (* CO_EVENT_TIME_T)(CO_TIME_T *pTime);


/* function prototypes */
EXTERN_DECL RET_T coTimeWriteReq(const CO_TIME_T *pTimeData);
EXTERN_DECL RET_T coTimeInit(BOOL_T producer, BOOL_T consumer);
EXTERN_DECL RET_T coEventRegister_TIME(CO_EVENT_TIME_T pFunction);

#endif /* CO_TIME_H */
