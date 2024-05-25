/*-------------------------------------------------------------------------
 *
 * matview.h
 *	  prototypes for matview.c.
 *
 *
 * Portions Copyright (c) 1996-2024, PostgreSQL Global Development Group
 * Portions Copyright (c) 1994, Regents of the University of California
 *
 * src/include/commands/matview.h
 *
 *-------------------------------------------------------------------------
 */
#ifndef MATVIEW_H
#define MATVIEW_H

#include "catalog/objectaddress.h"
#include "nodes/params.h"
#include "nodes/parsenodes.h"
#include "tcop/dest.h"
#include "utils/relcache.h"


extern void SetMatViewPopulatedState(Relation relation, bool newstate);

extern ObjectAddress ExecRefreshMatView(RefreshMatViewStmt *stmt, const char *queryString,
										ParamListInfo params, QueryCompletion *qc);
extern ObjectAddress RefreshMatViewByOid(Oid matviewOid, bool skipData, bool concurrent,
										 const char *queryString, ParamListInfo params,
										 QueryCompletion *qc);

extern DestReceiver *CreateTransientRelDestReceiver(Oid transientoid);

extern bool MatViewIncrementalMaintenanceIsEnabled(void);

extern uint64 refresh_matview_datafill(DestReceiver *dest, Query *query,
									   const char *queryString);

extern void refresh_by_heap_swap(Oid matviewOid, Oid OIDNewHeap,
								 char relpersistence);

#endif							/* MATVIEW_H */
