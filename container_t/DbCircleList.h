/*
 * =====================================================================================
 *
 *       Filename:  DbCircleList.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/25/2014 08:49:13 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kevin (###), kevin101@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef _DBCIRCLELIST_H
#define _DBCIRCLELIST_H

typedef void DbCircleList;
typedef void DbCircleListNode;
typedef void DbCircleListNodeData;

extern DbCircleList *DbCircleList_Create();

extern void DbCircleList_Destroy(DbCircleList *list);

extern void DbCircleList_Clear(DbCircleList *list);

extern int DbCircleList_Length(DbCircleList *list);

extern int DbCircleList_Insert(DbCircleList *list, 
			DbCircleListNode *node, DbCircleListNodeData *data, int pos);

extern DbCircleListNode *DbCircleList_Get(DbCircleList *list, int pos);

extern DbCircleListNode *DbCircleList_Delete(DbCircleList *list, int pos);

extern void DbCircleList_Reverse(DbCircleList *list);

extern DbCircleListNodeData *DbCircleList_GetNodeData(DbCircleListNode *node);

#endif
