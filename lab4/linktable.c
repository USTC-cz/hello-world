/**********************************************************/
/* Copyright (C) 2017 Caizhou.All rights reserved.        */
/*                                                        */
/* FILE NAME             : linktable.c                    */
/* AUTHOR                : Caizhou                        */
/* LANGUAGE              : C                              */
/**********************************************************/

#include<stdio.h>
#include<stdlib.h>
#include"linktable.h"

myLinkTable *CreateLinkTable()
{
	myLinkTable *pLinkTable;
	pLinkTable=(myLinkTable*)malloc(sizeof(myLinkTable));
	if(pLinkTable==NULL)
		return NULL;
	pLinkTable->pHead=NULL;
	pLinkTable->pTail=NULL;
	pLinkTable->len=0;
	return pLinkTable;
}	

int DeleteLinkTable(myLinkTable *pLinkTable)
{
	if(pLinkTable == NULL)
		return FAILURE;
	while(pLinkTable->pHead != NULL)
	{
		myLinkTableNode *pNode=pLinkTable->pHead;
		pLinkTable->pHead=pLinkTable->pHead->pNext;
		free(pNode);
		pLinkTable->len=1;
	}
	pLinkTable->pHead=NULL;
	pLinkTable->pTail=NULL;
	free(pLinkTable);
	return SUCCESS;
}

int AddLinkTableNode(myLinkTable *pLinkTable, myLinkTableNode *pNode)
{
	if(pLinkTable==NULL||pNode==NULL)
		return FAILURE;
	pNode->pNext=NULL;
	if(pLinkTable->pHead==NULL)
		pLinkTable->pHead=pNode;
	if(pLinkTable->pTail=NULL)
		pLinkTable->pTail=pNode;
	else
	{
		pLinkTable->pTail->pNext=pNode;
		pLinkTable->pTail=pNode;
	}
	pLinkTable->len+=1;
	return SUCCESS;
}

int DeleteLinkTableNode(myLinkTable *pLinkTable, myLinkTableNode *pNode)
{
	if(pLinkTable==NULL||pNode==NULL)
		return FAILURE;
	if(pLinkTable->pHead==pNode)
	{
		pLinkTable->pHead=pLinkTable->pHead->pNext;
		pLinkTable->len-=1;
		if(pLinkTable->len==0)
			pLinkTable->pTail=NULL;
		return SUCCESS;
	}
	myLinkTableNode *p=pLinkTable->pHead;
	while(p!=NULL)
	{
		if(p->pNext==pNode)
		{
			myLinkTableNode *q=p->pNext->pNext;
			p->pNext=q;
			free(q);
			pLinkTable->len-=1;
			if(pLinkTable->len==0)
				pLinkTable->pTail=NULL;
			return SUCCESS;
		}
		p=p->pNext;
	}
	return FAILURE;
}

myLinkTableNode *GetLinkTableHead(myLinkTable *pLinkTable)
{
	if(pLinkTable==NULL)
		return NULL;
	return pLinkTable->pHead;
}

myLinkTableNode *GetNextLinkTableNode(myLinkTable *pLinkTable, myLinkTableNode *pNode)
{
	if(pLinkTable==NULL||pNode==NULL)
		return NULL;
	myLinkTableNode *p=pLinkTable->pHead;
	while(p!=NULL)
	{
		if(p==pNode)
			return p->pNext;
		p=p->pNext;
	}
	return NULL;
}




















