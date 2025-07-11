/*
* codrv_canbittiming.c - CAN Bittiming tables 
*
* Copyright (c) 2012-2019 emotas embedded communication GmbH
*-------------------------------------------------------------------
* $Id: codrv_canbittiming.c 33905 2020-11-02 17:07:34Z ro $
*
*
*-------------------------------------------------------------------
*
*
*/

/********************************************************************/
/**
* \brief 
*
* \file 
* \author emotas embedded communication GmbH
*
* This module contains different bittiming tables.
*
*/
/* header of project specific types
---------------------------------------------------------------------------*/
#include <gen_define.h>

#include <co_datatype.h>
#include <co_drv.h>

#ifdef CODRV_BIT_TABLE_EXTERN

/*
* 200 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_200MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
         {   125u, 100u, 0u, 13u, 2u }, /* ! 87.5% */
         {   250u,  50u, 0u, 13u, 2u }, /* ! 87.5% */
         {   500u,  40u, 0u, 8u, 1u },  /* ! 90% */
         {  1000u,  20u, 0u, 8u, 1u }, /*  ! 90% */
         {0u,0u,0u,0u,0u} /* last */
    };
#endif /* CODRV_CANCLOCK_200MHZ */

/*
* 160 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_160MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 1000u, 0u, 13u, 2u }, /* 87.5% */
		{   20u,  500u, 0u, 13u, 2u }, /* 87.5% */
		{   50u,  200u, 0u, 13u, 2u }, /* 87.5% */
		{  100u,  100u, 0u, 13u, 2u }, /* 87.5% */
		{  125u,   80u, 0u, 13u, 2u }, /* 87.5% */
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{  250u,   40u, 0u, 13u, 2u }, /* 87.5% */
		{  500u,   20u, 0u, 13u, 2u }, /* 87.5% */
		{  800u,   25u, 0u,  6u, 1u }, /* 87.5% */
		{ 1000u,   10u, 0u, 13u, 2u }, /* 87.5% */
		{    0u,    0u, 0u,  0u, 0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_160MHZ */

/*
* 120 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_120MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 480u, 0u, 16u, 8u }, /* 68.0% */
		{   20u, 400u, 0u, 12u, 2u }, /* 86.7% */
		{   50u, 160u, 0u, 12u, 2u }, /* 86.7% */
		{  100u,  80u, 0u, 12u, 2u }, /* 86.7% */
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{  125u,  60u, 0u, 13u, 2u }, /* 87.5% */
		{  250u,  30u, 0u, 13u, 2u }, /* 87.5% */
		{  500u,  15u, 0u, 13u, 2u }, /* 87.5% */
		{  800u,  10u, 0u, 12u, 2u }, /* 86.7% */
		{ 1000u,   8u, 0u, 12u, 2u }, /* 86.7% */
		{    0u,   0u, 0u,  0u, 0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_120MHZ */

/*
* 100 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_100MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
         {   125u,  50u, 0u, 13u, 2u }, /* ! 87.5% */
         {   250u,  25u, 0u, 13u, 2u }, /* ! 87.5% */
         {   500u,  20u, 0u, 8u, 1u },  /* ! 90% */
         {  1000u,  10u, 0u, 8u, 1u }, /*  ! 90% */
         {0u,0u,0u,0u,0u} /* last */
    };
#endif /* CODRV_CANCLOCK_100MHZ */



/*
* 90 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_90MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 90MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{    10u, 600u, 0u, 12u, 2u }, /* !! 86.7% */
		{    20u, 300u, 0u, 12u, 2u }, /* !! 86.7% */
		{    50u, 120u, 0u, 12u, 2u }, /* !! 86.7% */
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   125u,  45u, 0u, 13u, 2u }, /* !! 87.5% */
		{   250u,  24u, 0u, 12u, 2u }, /* !! 86.7% */
		{   500u,  12u, 0u, 12u, 2u }, /* !! 86.7% */
		{  1000u,   6u, 0u, 12u, 2u }, /* !! 86.7% */
		{     0u,   0u, 0u,  0u, 0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_90MHZ */

/*
* 80 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_80MHZ

CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 500u, 0u, 13u, 2u }, /* 87.5% */
		{   20u, 250u, 0u, 13u, 2u }, /* 87.5% */
		{   50u, 100u, 0u, 13u, 2u }, /* 87.5% */
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{  100u,  50u, 0u, 13u, 2u }, /* 87.5% */
		{  125u,  40u, 0u, 13u, 2u }, /* 87.5% */
		{  250u,  20u, 0u, 13u, 2u }, /* 87.5% */
		{  500u,  10u, 0u, 13u, 2u }, /* 87.5% */
		{  800u,  10u, 0u,  8u, 1u }, /* 90.0% */
		{ 1000u,   5u, 0u, 13u, 2u }, /* 87.5% */
		{    0u,   0u, 0u,  0u, 0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_80MHZ */

#ifdef CODRV_CANCLOCK_75MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 75MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   20u, 250u, 0u, 12u, 2u }, /* 86.7% */
		{   50u, 100u, 0u, 12u, 2u }, /* 86.7% */
# endif
		{  100u,  50u, 0u, 12u, 2u }, /* 86.7% */
		{  125u,  40u, 0u, 12u, 2u }, /* 86.7% */
		{  250u,  20u, 0u, 12u, 2u }, /* 86.7% */
		{  500u,  10u, 0u, 12u, 2u }, /* 86.7% */
		{ 1000u,   5u, 0u, 12u, 2u }, /* 86.7% */
		{    0u,   0u, 0u,  0u, 0u }  /* last */
	};
#endif

/*
* 72 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_72MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 72MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 450u, 0u, 13u,  2u },
		{   20u, 225u, 0u, 13u,  2u },
		{   50u,  90u, 0u, 13u,  2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{  100u,  45u, 0u, 13u,  2u },
		{  125u,  36u, 0u, 13u,  2u },
		{  250u,  18u, 0u, 13u,  2u },
		{  500u,   9u, 0u, 13u,  2u },
		{  800u,   6u, 0u, 12u,  2u }, /* 86.7% */
		{ 1000u,   9u, 0u,  6u,  1u }, /* 8tq 87.5% */
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_72MHZ */

/*
* 70 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_70MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 70MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   20u, 250u, 3u, 8u, 2u }, /* !! 85,7% */
		{   50u,  70u, 8u, 8u, 3u }, /* !! 85% */
# endif
		{  100u,  35u, 8u, 8u, 3u }, /* !! 85% */
		{  125u,  35u, 5u, 8u, 2u },
		{  250u,  14u, 8u, 8u, 3u }, /* !! 85% */
		{  500u,   7u, 8u, 8u, 3u }, /* !! 85% */
		{ 1000u,   5u, 3u, 8u, 2u }, /* !! 85,7% */
		{    0u,   0u, 0u, 0u, 0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_70MHZ */

/*
* 64 MHz table
*/
#ifdef CODRV_CANCLOCK_64MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 64MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 256u, 0u, 16u,  8u }, /* 68.0% */
		{   20u, 200u, 0u, 13u,  2u },
		{   50u,  80u, 0u, 13u,  2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{  100u,  40u, 0u, 13u,  2u },
		{  125u,  32u, 0u, 13u,  2u },
		{  250u,  16u, 0u, 13u,  2u },
		{  500u,   8u, 0u, 13u,  2u },
		{  800u,   5u, 0u, 13u,  2u },
		{ 1000u,   4u, 0u, 13u,  2u },
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_64MHZ */

/*
* 60 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_60MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 60MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 375u, 0u, 13u,  2u },
		{   20u, 200u, 0u, 12u,  2u }, /* 86.7% */
		{   50u,  75u, 0u, 13u,  2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{  100u,  40u, 0u, 12u,  2u }, /* 86.7% */
		{  125u,  30u, 0u, 13u,  2u },
		{  250u,  15u, 0u, 13u,  2u },
		{  500u,   8u, 0u, 12u,  2u }, /* 86.7% */
		{  800u,   5u, 0u, 12u,  2u }, /* 86.7% */
		{ 1000u,   4u, 0u, 12u,  2u }, /* 86.7% */
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_60MHZ */

/*
* 50 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_50MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 50MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 250u, 0u, 16u,  3u }, /* !! 85% */
		{   20u, 125u, 0u, 16u,  3u }, /* !! 85% */
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   50u,  50u, 0u, 16u,  3u }, /* !! 85% */
		{  100u,  25u, 0u, 16u,  3u }, /* !! 85% */
		{  125u,  25u, 0u, 13u,  2u },
		{  250u,  10u, 0u, 16u,  3u }, /* !! 85% */
		{  500u,   5u, 0u, 16u,  3u }, /* !! */
		{ 1000u,   5u, 0u,  7u,  2u }, /* !! 80% */
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_50MHZ */

/*
* 48 MHz table
*/
#ifdef CODRV_CANCLOCK_48MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 48MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 300u, 0u, 13u,  2u },
		{   20u, 150u, 0u, 13u,  2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   50u,  60u, 0u, 13u,  2u },
		{  100u,  30u, 0u, 13u,  2u },
		{  125u,  24u, 0u, 13u,  2u },
		{  250u,  12u, 0u, 13u,  2u },
		{  500u,   6u, 0u, 13u,  2u },
		{ 1000u,   3u, 0u, 13u,  2u },
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_48MHZ */

/*
* 45 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_45MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 45MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 300u, 0u, 12u,  2u }, /* 86.7% */
		{   20u, 150u, 0u, 12u,  2u }, /* 86.7% */
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   50u,  60u, 0u, 12u,  2u }, /* 86.7% */
		{  100u,  30u, 0u, 12u,  2u }, /* 86.7% */
		{  125u,  24u, 0u, 12u,  2u }, /* 86.7% */
		{  250u,  12u, 0u, 12u,  2u }, /* 86.7% */
		{  500u,   6u, 0u, 12u,  2u }, /* 86.7% */
		{ 1000u,   3u, 0u, 12u,  2u }, /* 86.7% */
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_45MHZ */

/*
* 42 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_42MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 42MHz table, prescaler 10bit (max 1024) */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 280u, 0u, 12u,  2u },
		{   20u, 140u, 0u, 12u,  2u }, /* 86,7% */
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   50u,  56u, 0u, 15u,  2u },
		{  100u,  28u, 0u, 16u,  3u },
		{  125u,  21u, 0u, 13u,  2u },
		{  250u,  12u, 0u, 11u,  2u },
		{  500u,   6u, 0u, 11u,  2u },
		{ 1000u,   3u, 0u, 11u,  2u },
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_42MHZ */

/*
* 40 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_40MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 40MHz table, prescaler 10bit (max 1024) */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 250u, 0u, 13u,  2u },
		{   20u, 125u, 0u, 13u,  2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   50u,  50u, 0u, 13u,  2u },
		{  100u,  25u, 0u, 13u,  2u },
		{  125u,  20u, 0u, 13u,  2u },
		{  250u,  10u, 0u, 13u,  2u },
		{  500u,   5u, 0u, 13u,  2u },
		{ 1000u,   5u, 0u,  6u,  1u },
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_40MHZ */

/*
* 36 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_36MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 36MHz table, prescaler 10bit (max 1024) */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 225u, 0u, 13u,  2u },
		{   20u, 120u, 0u, 12u,  2u }, /* 86,7% */
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   50u,  45u, 0u, 13u,  2u }, /* 85% */
		{  100u,  18u, 0u, 16u,  3u }, /* 85% */
		{  125u,  18u, 0u, 13u,  2u },
		{  250u,   9u, 0u, 13u,  2u },
		{  500u,   9u, 0u,  6u,  1u }, /* only 8tq */
		{  800u,   3u, 0u, 12u,  2u },
		{ 1000u,   2u, 0u, 14u,  3u }, /* 83.3% */
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_36MHZ */

/*
* 35 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_35MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 35MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u,175u, 8u, 8u, 3u }, /* 85% */
		{   20u,125u, 3u, 8u, 2u }, /* 85,7% */
# endif
		{   50u, 35u, 8u, 8u, 3u }, /* 85% */
		{  100u, 25u, 3u, 8u, 2u }, /* 85,7% */
		{  125u, 14u, 8u, 8u, 3u }, /* 85% */
		{  250u,  7u, 8u, 8u, 3u }, /* 85% */
		{  500u,  5u, 3u, 8u, 2u }, /* 85,7% */
		{     0u, 0u, 0u, 0u, 0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_35MHZ */

/*
* 32 MHz table
*/
#ifdef CODRV_CANCLOCK_32MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 32MHz table, prescaler 10bit (max 1024) */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u,200u, 0, 13u, 2u },
		{   20u,100u, 0, 13u, 2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   50u, 40u, 0, 13u, 2u },
		{  100u, 20u, 0, 13u, 2u },
		{  125u, 16u, 0, 13u, 2u },
		{  250u,  8u, 0, 13u, 2u },
		{  500u,  4u, 0, 13u, 2u },
		{  800u,  5u, 0,  6u, 1u },
		{ 1000u,  2u, 0, 13u, 2u },
		{    0u,  0u, 0u, 0u, 0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_32MHZ */

/*
* 30 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_30MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 30MHz table, prescaler 10bit (max 1024) */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u,200u, 0u, 12u, 2u },
		{   20u,100u, 0u, 12u, 2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   50u, 40u, 0u, 12u, 2u },
		{  100u, 20u, 0u, 12u, 2u },
		{  125u, 16u, 0u, 12u, 2u },
		{  250u,  8u, 0u, 12u, 2u },
		{  500u,  4u, 0u, 12u, 2u },
		{ 1000u,  2u, 0u, 12u, 2u },
		{    0u,  0u, 0u,  0u, 0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_30MHZ */

/*
* 25 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_25MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 25MHz table, prescaler 10bit (max 1024) */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 125u, 0u, 16u,  3u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   20u,  50u, 0u, 16u,  8u },
		{   50u,  25u, 0u, 16u,  3u },
		{  100u,  10u, 0u, 16u,  8u },
		{  125u,  10u, 0u, 16u,  3u },
		{  250u,   5u, 0u, 16u,  3u },
		{  500u,   2u, 0u, 16u,  8u },
		{ 1000u,   1u, 0u, 16u,  8u },
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_25MHZ */

#ifdef CODRV_CANCLOCK_24MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* e.g. 24MHz table, prescaler 10bit (max 1024)
		 * own values you can find on www.bittiming.can-wiki.info
		 */
		/* brate, pre, prop, seg1, seg2 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 150u, 0u, 13u, 2u },
		{   20u,  75u, 0u, 13u, 2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   50u,  30u, 0u, 13u, 2u },
		{  100u,  15u, 0u, 13u, 2u },
		{  125u,  12u, 0u, 13u, 2u },
		{  250u,   6u, 0u, 13u, 2u },
		{  500u,   3u, 0u, 13u, 2u },
		{ 1000u,   2u, 0u,  9u, 2u },
		{    0u,   0u, 0u, 0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_24MHZ */

/*
* 20 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_20MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 20MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 125u, 0u, 13u,  2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   20u,  50u, 0u, 16u,  3u }, /* !! 85% */
		{   50u,  25u, 0u, 13u,  2u },
		{  100u,  10u, 0u, 16u,  3u }, /* !! 85% */
		{  125u,  10u, 0u, 13u,  2u },
		{  250u,   5u, 0u, 13u,  2u },
		{  500u,   2u, 0u, 16u,  3u }, /* !! 85% */
		{ 1000u,   1u, 0u, 16u,  3u }, /* !! 85% */
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_20MHZ */

/*
* 18 MHz table
*
* Samplepoint is not on 87.5%.
*/
#ifdef CODRV_CANCLOCK_18MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 18MHz table, prescaler 10bit (max 1024) */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u, 100u, 0u, 15u,  2u }, /* 88.9% */
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   20u,  50u, 0u, 15u,  2u }, /* 88.9% */
		{   50u,  18u, 0u, 16u,  3u }, /* 85.0% */
		{  100u,  12u, 0u, 12u,  2u }, /* 86.7% */
		{  125u,   9u, 0u, 13u,  2u },
		{  250u,   4u, 0u, 15u,  2u }, /* 88.9% */
		{  500u,   2u, 0u, 15u,  2u }, /* 88.9% */
		{ 1000u,   1u, 0u, 15u,  2u }, /* 88.9% */
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_18MHZ */

/*
* 16 MHz table
*/
#ifdef CODRV_CANCLOCK_16MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 16MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
		{   10u,100u, 0u, 13u, 2u },
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   20u,  50u, 0u,  13u, 2u },
		{   50u,  20u, 0u,  13u, 2u },
		{  100u,  10u, 0u,  13u, 2u },
		{  125u,   8u, 0u,  13u, 2u },
		{  250u,   4u, 0u,  13u, 2u },
		{  500u,   2u, 0u,  13u, 2u },
		{  800u,   1u, 0u,  16u, 3u },
		{ 1000u,   1u, 0u,  13u, 2u },
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_16MHZ */

/*
* 12 MHz table
*/
#ifdef CODRV_CANCLOCK_12MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 12MHz table, prescaler 7bit (max 127) + BRPE 4bit == 1024 */
# ifdef CODRV_CANCLOCK_PRE_10BIT
# endif /* CODRV_CANCLOCK_PRE_10BIT */
		{   10u,  75u, 0u,  13u, 2u },
		{   20u,  40u, 0u,  12u, 2u }, /* 86.7% */
		{   50u,  15u, 0u,  13u, 2u },
		{  100u,   8u, 0u,  12u, 2u }, /* 86.7% */
		{  125u,   6u, 0u,  13u, 2u },
		{  250u,   3u, 0u,  13u, 2u },
		{  500u,   2u, 0u,   9u, 2u }, /* 83.3% */
		{  800u,   1u, 0u,  12u, 2u }, /* 86.7% */
		{ 1000u,   1u, 0u,   9u, 2u }, /* 83.3% */
		{    0u,   0u, 0u,  0u,  0u }  /* last */
	};
#endif /* CODRV_CANCLOCK_12MHZ */

#ifdef CODRV_CANCLOCK_8MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 8MHz table, prescaler 6bit (max 64) + BRPE 4bit == 1024 */
		{    10u, 50u, 0u, 13u, 2u },
		{    20u, 25u, 0u, 13u, 2u },
		{    50u, 10u, 0u, 13u, 2u },
		{   100u,  5u, 0u, 13u, 2u },
		{   125u,  4u, 0u, 13u, 2u },
		{   250u,  2u, 0u, 13u, 2u },
		{   500u,  1u, 0u, 13u, 2u },
		{   800u,  1u, 3u,  4u, 2u }, /* 80% */
		{  1000u,  1u, 3u,  2u, 1u }, /* 75% */
		{     0u,  0u, 0u,  0u, 0u }  /* last */
	};
#endif

#ifdef CODRV_CANCLOCK_4MHZ
CO_CONST CODRV_BTR_T codrvCanBittimingTable[] = {
		/* 4MHz table */
		{    10u, 20u, 0u, 16u, 3u },
		{    20u, 10u, 0u, 16u, 3u },
		{    50u,  4u, 0u, 16u, 3u },
		{   100u,  2u, 0u, 16u, 3u },
		{   125u,  2u, 0u, 13u, 2u },
		{   250u,  1u, 0u, 13u, 2u },
		{     0u,  0u, 0u,  0u, 0u }  /* last */
	};
#endif

#endif /* CODRV_BIT_TABLE_EXTERN */
