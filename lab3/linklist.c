/**********************************************************/
/* Copyright (C) 2017 Caizhou.All rights reserved.        */
/*                                                        */
/* FILE NAME             : linklist.c                     */
/* AUTHOR                : Caizhou                        */
/* LANGUAGE              : C                              */
/**********************************************************/

#include"linklist.h"
#include<stdio.h>
#include<string.h>
tDataNode *FindCmd(tDataNode *head,char *cmd)
{
	if (head==NULL || cmd==NULL)
		return NULL;
	tDataNode *p=head;
	while (*p!=NULL)
	{
		if (strcmp(p->cmd,cmd)==0)
			return p;
		p=p->next;
	}
	return NULL;
}

int ShowAllCmd(tDataNode *head)
{
	printf("Menu List:\n");
	tDataNode *q=head;
	while(q!=NULL)
	{
		printf("\t%s - %s\n",q->cmd,q->info);
		p=p->next;
	}
	return 0;
}
