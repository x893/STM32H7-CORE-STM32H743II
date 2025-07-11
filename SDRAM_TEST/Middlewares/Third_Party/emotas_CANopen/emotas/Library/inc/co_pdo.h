/*
* co_pdo.h - contains defines for pdo services
*
* Copyright (c) 2012-2023 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_pdo.h 47431 2023-06-27 09:35:24Z boe $
*
*-------------------------------------------------------------------
*
*
*
*/

/**
* \brief defines for pdo service
*
* \file co_pdo.h - contains defines for pdo service
*/

#ifndef CO_PDO_H
#define CO_PDO_H 1

# if defined(CO_PDO_TRANSMIT_CNT) || defined(CO_PDO_RECEIVE_CNT)


#include <co_datatype.h>


#ifndef CO_MAX_MAP_ENTRIES
# define	CO_MAX_MAP_ENTRIES	1
#endif /* CO_MAX_MAP_ENTRIES */

/**
* PDO transmit mapping entry (one mapping entry)
*/
typedef struct {
	CO_CONST void	*pVar;	/**< pointer to variable */
	UNSIGNED8	len;		/**< number of bytes for variable */
	BOOL_T		numeric;	/**< numeric flag for byte swapping */
	UNSIGNED32	val;		/**< OD value */
} PDO_TR_MAP_ENTRY_T;

/**
* PDO receive mapping entry (one mapping entry)
*/
typedef struct {
	void		*pVar;		/**< pointer to variable */
	UNSIGNED8	len;		/**< number of bytes for variable */
	BOOL_T		numeric;	/**< numeric flag for byte swapping */
	UNSIGNED32	val;		/**< OD value */
#ifdef CO_NETWORK_ROUTING_CNT
	UNSIGNED16	routePdo[1];	/**< route to other network */
#endif /* CO_NETWORK_ROUTING_CNT */
} PDO_REC_MAP_ENTRY_T;

/**
* PDO mapping table (mapping entries for one transmit PDO) */
typedef struct {
	UNSIGNED8		mapCnt;		/**< number of mapping entries */
	PDO_TR_MAP_ENTRY_T	mapEntry[CO_MAX_MAP_ENTRIES]; /**< Mapping entries */
} PDO_TR_MAP_TABLE_T;

/**
* PDO mapping table (mapping entries for one receive PDO) */
typedef struct {
	UNSIGNED8		mapCnt;		/**< number of mapping entries */
	PDO_REC_MAP_ENTRY_T	mapEntry[CO_MAX_MAP_ENTRIES]; /**< Mapping entries */
} PDO_REC_MAP_TABLE_T;


/** \brief function pointer to PDO indication
 * \param pdoNr - PDO number
 * 
 */
typedef void (* CO_EVENT_PDO_T)(UNSIGNED16); /*lint !e960 customer specific parameter names */


/** \brief function pointer to PDO update indication
 * \param index 
 * \param subindex
 * 
 */
typedef void (* CO_EVENT_PDO_UPDATE_T)(UNSIGNED16, UNSIGNED8);


/** \brief function pointer to MPDO indication
 * \param pdoNr - PDO number
 * \param index - Index
 * \param subIndex - subIndex
 * 
 */
typedef void (* CO_EVENT_MPDO_T)(UNSIGNED16, UNSIGNED16, UNSIGNED8); /*lint !e960 customer specific parameter names */



/* function prototypes */
EXTERN_DECL RET_T coPdoTransmitInit(UNSIGNED16 pdoNr,
				UNSIGNED8	transType, UNSIGNED16 inhibit,
				UNSIGNED16	eventTime, UNSIGNED8 syncStartVal,
				CO_CONST PDO_TR_MAP_TABLE_T *mapTable);
EXTERN_DECL RET_T coPdoReceiveInit(UNSIGNED16 pdoNr,
				UNSIGNED8 transType, UNSIGNED16 inhibit, UNSIGNED16 eventTime,
				CO_CONST PDO_REC_MAP_TABLE_T *mapTable);
EXTERN_DECL RET_T coPdoNetworkRouting(void);

EXTERN_DECL RET_T coPdoReqNr(UNSIGNED16 pdoNr, UNSIGNED8 flags);
EXTERN_DECL RET_T coPdoReqObj(UNSIGNED16 index,
				UNSIGNED8 subIndex, UNSIGNED8 flags);

EXTERN_DECL BOOL_T coPdoObjIsMapped(UNSIGNED16 pdoNr,
				UNSIGNED16 index, UNSIGNED8 subIndex);
EXTERN_DECL UNSIGNED16 coPdoTrObjIsMapped(UNSIGNED16 index, UNSIGNED8 subIndex,
				UNSIGNED16 *pMapList, UNSIGNED16 mapListlen);

EXTERN_DECL RET_T coMPdoReq(UNSIGNED16 pdoNr, UNSIGNED8 dstNode,
				UNSIGNED16 index, UNSIGNED8 subIndex, UNSIGNED8 flags);

EXTERN_DECL RET_T coMPdoGetSamInfo(UNSIGNED16 *pRIndex,
				UNSIGNED8 *pRSubIndex, UNSIGNED8 *pRNodeId);

#ifdef CO_CAN_TIMESTAMP_SUPPORTED
EXTERN_DECL CO_CAN_TIMESTAMP_T coPdoGetTimestamp(UNSIGNED16 pdoNr);
#endif /* CO_CAN_TIMESTAMP_SUPPORTED */
EXTERN_DECL RET_T coEventRegister_PDO(CO_EVENT_PDO_T pFunction);
EXTERN_DECL RET_T coEventRegister_PDO_SYNC(CO_EVENT_PDO_T pFunction);
EXTERN_DECL RET_T coEventRegister_PDO_REC_EVENT(CO_EVENT_PDO_T pFunction);
EXTERN_DECL RET_T coEventRegister_MPDO(CO_EVENT_MPDO_T pFunction);
EXTERN_DECL RET_T coEventRegister_PDO_UPDATE(CO_EVENT_PDO_UPDATE_T pFunction);

# endif /* defined(CO_PDO_TRANSMIT_CNT) || defined(CO_PDO_RECEIVE_CNT) */
#endif /* CO_PDO_H */

