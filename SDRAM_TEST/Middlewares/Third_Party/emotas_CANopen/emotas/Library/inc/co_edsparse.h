/*
* co_edsparse.h - contains defines for eds parser services
*
* Copyright (c) 2016-2022 emotas embedded communication GmbH
*
*-------------------------------------------------------------------
* $Id: co_edsparse.h 43757 2022-11-30 11:29:14Z boe $
*-------------------------------------------------------------------
*
*
*
*/

/**
* \brief defines for eds parser services
*
* \file co_edsparse.h - contains defines for eds parser services
*/

#ifndef CO_EDSPARSER_H
#define CO_EDSPARSER_H 1

#include <co_datatype.h>


/* datatypes */
typedef struct {
	UNSIGNED16	index;
	UNSIGNED8	subIndex;
	UNSIGNED8	dataType;
} CO_EDS_MAP_ENTRY_T;


typedef struct {
	UNSIGNED16	nodeId;
	UNSIGNED16	pdoNr;
	UNSIGNED8	nrOfSubs;
	UNSIGNED8	nrOfMappedObj;
	CO_EDS_MAP_ENTRY_T	mapEntry[8];
	BOOL_T		writable;
} CO_EDS_MAP_TABLE_T;


/** \brief function pointer to detect slave finish indication
 * \param nodeId		-	node id
 * \param pEdsFileName	-	EDS file name fitting the node
 * 
 */
typedef void (* CO_DETECT_SLAVE_FCT_T)(UNSIGNED8 nodeId, char *pEdsFileName);

RET_T	coEdsparseAddEdsToRepository(const char *edsFilePath);
RET_T	coEdsparseDetectSlaveEds(UNSIGNED8 nodeId,
			UNSIGNED8 sdoClientNr, CO_DETECT_SLAVE_FCT_T finishFct);
RET_T	coEdsparseReadEdsMapping(UNSIGNED8 nodeId,
			const char *edsFileName);
CO_EDS_MAP_TABLE_T *coEdsparseGetRPdoMapEntry(UNSIGNED16 mapIdx);
CO_EDS_MAP_TABLE_T *coEdsparseGetTPdoMapEntry(UNSIGNED16 mapIdx);
UNSIGNED16 coEdsparseGetSupportedObjCnt(const char *edsFileName, const char *section);
RET_T	coEdsparseGetObjectDesc(const char *edsFileName,
			UNSIGNED16 index, UNSIGNED8 subIndex,
			UNSIGNED16 *pDataType, UNSIGNED16 *pAttr, char *pDefaultVal);
RET_T	coEdsparseGetIndexDesc(const char *edsFileName, const char *pSection,
			UNSIGNED16 edsIdx, UNSIGNED16 *pIndex, UNSIGNED8 *pNrOfSubs);

#endif /* CO_EDSPARSER_H */
