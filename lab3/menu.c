/**********************************************************/
/* Copyright (C) 2017 Caizhou.All rights reserved.        */
/*                                                        */
/* FILE NAME             : menu.c                         */
/* AUTHOR                : Caizhou                        */
/* LANGUAGE              : C                              */ 
/**********************************************************/



#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include"linklist.h"

#define CMD_LEN 128

void help();
void hello();
void add();
void oppnum();
void compare();
void PI();
static tDataNode menu[]=
{
	{"help","List all command in this program",help,&menu[1]},
	{"hello","welcom infomation",hello,&menu[2]},
	{"add","add two numbers",add,&menu[3]},
	{"oppnum","output a oppsite number",oppnum,&menu[4]},
	{"compare","compare two numbers",compare,&menu[5]}
	{"PI","const math number PI",PI,&menu[6]},
	{"exit","exit the program",exit,NULL}
};
 
 int main()
 {
	 while(1)
	 {
		 char cmd[CMD_LEN];
		 printf("input a cmd:");
		 scanf("%s",cmd);
		 tDataNode *p=FindCmd(menu,cmd);
		 if (p==NULL)
			 printf("\tthis is a wrong cmd\n");
		 printf("\t%s -%s\n",p->cmd,p->info);
		 if(p->handler!=NULL)
			 p->handler();
	 }	
	return 0;	 
 }
	 
	 
	 
	 
	 
 
 void help()
{
    printf("enter help [-commandname] for details\n");
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

