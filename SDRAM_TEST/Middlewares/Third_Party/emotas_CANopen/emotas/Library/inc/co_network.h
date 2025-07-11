/*
* co_network.h - contains defines for network routing services
*
* Copyright (c) 2012-2022 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_network.h 43828 2022-12-06 13:06:52Z boe $
*-------------------------------------------------------------------
*
*
*
*/

/**
* \brief defines for network services
*
* \file co_network.h - contains defines for network services
*
*/

#ifndef CO_NETWORK_H
#define CO_NETWORK_H 1

#include <co_datatype.h>


/* datatypes */

/** \brief function pointer to get sdo channel number
 * 
 * \param network - target network
 * \param node - target nodeid
 * \param pCobClSrv - pointer for cob-id client->server (0 - use default)
 * 					  (contains cob-id's from server at function call)
 * \param pCobSrvCl - pointer for cob-id server->client (0 - use default)
 * 					  (contains cob-id's from server at function call)
 *
 * \return SDO channel
 */
typedef UNSIGNED8 (* CO_EVENT_GW_SDOCLIENT_FCT_T)(UNSIGNED16 network, UNSIGNED8 node, UNSIGNED32 *pCobClSrv, UNSIGNED32 *pCobSrvCl); /*lint !e960 customer specific parameter names */


/* function prototypes */
EXTERN_DECL RET_T coNetworkGet(UNSIGNED16	network,
					UNSIGNED8 *pNetworkIf, UNSIGNED8 *pRouterNode);
EXTERN_DECL RET_T coEventRegister_GW_SDOCLIENT(CO_EVENT_GW_SDOCLIENT_FCT_T);

#endif /* CO_NETWORK_H */
