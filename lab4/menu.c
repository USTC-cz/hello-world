/**********************************************************/
/* Copyright (C) 2017 Caizhou.All rights reserved.        */
/*                                                        */
/* FILE NAME             : menu.c                         */
/* AUTHOR                : Caizhou                        */
/* LANGUAGE              : C                              */
/**********************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"linktable.h"

#define CMD_LEN 128

void help();
void hello();
void add();
void oppnum();
void compare();
void PI();

typedef struct DataNode
{
	myLinkTableNode *pNext;
	char *cmd;
	char *desc;
	int (*handler)();
}myDataNode;

myDataNode *Findcmd(myLinkTable *head,char *cmd)
{
	myDataNode *pnode=(myDataNode*)GetLinkTableHead(head);
	while(pnode!=NULL)
	{
		if(strcmp(pnode->cmd,cmd)==0)
			return pnode;
		pnode=(myDataNode*)GetNextLinkTableNode(head,(myLinkTableNode*)pnode);
	}
	return NULL;
}

int ShowAllcmd(myLinkTable *head)
{
	myDataNode *pnode=(myDataNode*)GetLinkTableHead(head);
	printf("                 menu list:\n");
	printf("-------------------------------------\n");
	while(pnode!=NULL)
	{
		printf("%8s - %s\n",pnode->cmd,pnode->desc);
		pnode=(myDataNode*)GetNextLinkTableNode(head,(myLinkTableNode*)pnode);
	}
	printf("-------------------------------------\n");
	return 0;
}

int init(myLinkTable **ppLinkTable)
{
	*ppLinkTable=CreateLinkTable();
	myDataNode *pnode=(myDataNode*)malloc(sizeof(myDataNode));
	pnode->cmd="help";
	pnode->desc="List all command in this program";
	pnode->handler=help;
	AddLinkTableNode(*ppLinkTable,(myLinkTableNode*)pnode);
	pnode=(myDataNode*)malloc(sizeof(myDataNode));
	pnode->cmd="hello";
	pnode->desc="welcom infomation";
	pnode->handler=hello;
	AddLinkTableNode(*ppLinkTable,(myLinkTableNode*)pnode);
	pnode=(myDataNode*)malloc(sizeof(myDataNode));
	pnode->cmd="add";
	pnode->desc="add two numbers";
	pnode->handler=add;
	AddLinkTableNode(*ppLinkTable,(myLinkTableNode*)pnode);
	pnode=(myDataNode*)malloc(sizeof(myDataNode));
	pnode->cmd="oppnum";
	pnode->desc="output a oppsite number";
	pnode->handler=oppnum;
	AddLinkTableNode(*ppLinkTable,(myLinkTableNode*)pnode);
	pnode=(myDataNode*)malloc(sizeof(myDataNode));
	pnode->cmd="compare";
	pnode->desc="compare  two numbers";
	pnode->handler=conmpare;
	AddLinkTableNode(*ppLinkTable,(myLinkTableNode*)pnode);
	pnode=(myDataNode*)malloc(sizeof(myDataNode));
	pnode->cmd="PI";
	pnode->desc="const math number PI";
	pnode->handler=PI;
	AddLinkTableNode(*ppLinkTable,(myLinkTableNode*)pnode);
	pnode=(myDataNode*)malloc(sizeof(myDataNode));
	pnode->cmd="exit";
	pnode->desc="exit the program";
	pnode->handler=exit;
	AddLinkTableNode(*ppLinkTable,(myLinkTableNode*)pnode);
}myLinkTable *head=NULL;

int main()
{
	init(&head);
	while(1)
	{
		char cmd[CMD_LEN]
		printf("input a cmd>");
		scanf("%s",cmd);
		myDataNode *p=Findcmd(head,cmd)
		if(p==NULL)
			printf("this is a wrong cmd!\n");
		else
		{
			printf("%s\n",p->desc);
			p->handler();
		}
	}
	return 0;
}


 void help()
{
    printf("enter [-commandname] for details\n");
}
void hello()
{
    printf("hello,user\n");
}
void add()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",a+b);
}
void oppnum()
{
    int a;
    scanf("%d",&a);
    printf("%d\n",-a);	
}
void compare()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<b)
	printf("%d<%d\n",a,b);
    else if(a==b)
	printf("%d=%d\n",a,b);
    else 
	printf("%d>%d\n",a,b);
}
void PI()
{
    printf("3.14\n");
}




















