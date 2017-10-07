/**********************************************************/
/* Copyright (C) 2017 Caizhou.All rights reserved.        */
/*                                                        */
/* FILE NAME             : linklist.h                     */
/* AUTHOR                : Caizhou                        */
/* LANGUAGE              : C                              */
/**********************************************************/


#ifndef _LINKLIST_H_
#define _LINKLIST_H_
typedef struct DataNode
{
	char *cmd;
	char *info;
	int (*handler)();
	struct DataNode *next;
}tDataNode;
tDataNode *FindCmd(tDataNode *head,char *cmd);
int ShowAllCmd(tDataNode);
#endif


