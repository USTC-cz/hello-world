/**********************************************************/
/* Copyright (C) 2017 Caizhou.All rights reserved.        */
/*                                                        */
/* FILE NAME             : linktable.h                    */
/* AUTHOR                : Caizhou                        */
/* LANGUAGE              : C                              */
/**********************************************************/

#ifndef _LINKTABLE_H_
#define _LINKTABLE_H_
#define SUCCESS 0
#define FAILURE -1

typedef struct LinkTableNode
{
	struct LinkTableNode *pNext;
}myLinkTableNode;

typedef struct LinkTable
{
	myLinkTableNode *pHead;
	myLinkTableNode *pTail;
	int len;
}myLinkTable;

//构建LinkTable
myLinkTable *CreateLinkTable();
//删除LinkTable
int DeleteLinkTable(myLinkTable *pLinkTable);
//增加LinkTable结点
int AddLinkTableNode(myLinkTable *pLinkTable, myLinkTableNode *pNode);
//删除LinkTable结点
int DeleteLinkTableNode(myLinkTable *pLinkTable, myLinkTableNode *pNode);
//获取头结点
myLinkTableNode *GetLinkTableHead(myLinkTable *pLinkTable);
//获取下一结点
myLinkTableNode *GetNextLinkTableNode(myLinkTable *pLinkTable, myLinkTableNode *pNode);

#endif

