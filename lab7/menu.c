#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "linktable.h"
#include "menu.h"

int help();
int hello();
int add();
int oppnum();
int compare();
int PI();
int quit();

#define CMD_MAX_LEN 128
#definr CMD_MAX_ARGV_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

char cmd[CMD_MAX_LEN];


typedef struct DataNode
{
    tLinkTableNode * pNext;
    char*   cmd;
    char*   desc;
    int     (*handler)();
} tDataNode;

int SearchCondition(tLinkTableNode * pLinkTableNode)
{
    tDataNode * pNode = (tDataNode *)pLinkTableNode;
    if(strcmp(pNode->cmd, cmd) == 0)
    {
        return  SUCCESS;  
    }
    return FAILURE;	       
}

tDataNode* FindCmd(tLinkTable * head, char * cmd)
{
    return  (tDataNode*)SearchLinkTableNode(head,SearchCondition);
}


int ShowAllCmd(tLinkTable * head)
{
    tDataNode * pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s - %s\n", pNode->cmd, pNode->desc);
        pNode = (tDataNode*)GetNextLinkTableNode(head,(tLinkTableNode *)pNode);
    }
    return 0;
}

int MenuConfig(char * cmd, char * desc, void (*handler)(int argc, char *argv[]))
{
  tDataNode* pNode = NULL;
  if (head == NULL)
    {
       head = CreateLinkTable();
       pNode = (tDataNode*)malloc(sizeof(tDataNode));
       pNode->cmd = "help";
       pNode->desc = "Menu List:";
       pNode->handler = Help;
       AddLinkTableNode(head, (tLinkTableNode *)pNode);
    }
  pNode = (tDataNode*)malloc(sizeof(tDataNode));
  pNode->cmd = cmd;
  pNode->desc = desc;
  pNode->handler = handler;
  AddLinkTableNode(head, (tLinkTableNode *)pNode);
}

int ExecuteMenu()
{
  while(1)
    {
      int argc = 0;
      char *argv[CMD_MAX_ARGV_LEN];
      char cmd[CMD_MAX_LEN];
      char *pcmd = NULL;
      printf("Input a cmd number > ");
      pcmd = fgets(cmd, CMD_MAX_LEN, stdin);
      if (pcmd == NULL)
        {
          continue;
        }
      pcmd = strtok(pcmd, " ");
      while (pcmd != NULL && argc < CMD_MAX_ARGV_LEN)
        {
          argv[argc] = pcmd;
          argc++;
          pcmd = strtok(NULL, " ");
        }
      if (argc == 1)
        {
          int len = strlen(argv[0]);
          *(argv[0] + len - 1) = '\0';
        }
      tDataNode *p = FindCmd(head, argv[0]);
      if( p == NULL)
      {
        printf("This is a wrong cmd!\n ");
        continue;
      }
      printf("%s - %s\n", p->cmd, p->desc); 
      if(p->handler != NULL) 
        { 
          p->handler(argc, argv);
        }
    }
}

void Help(int argc, char *argv[])
{
  ShowAllCmd(head);
}


int InitMenuData(tLinkTable ** ppLinktable)
{
    *ppLinktable = CreateLinkTable();
    tDataNode* pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "help";
    pNode->desc = "Menu List:";
    pNode->handler = help;
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "hello";
    pNode->desc = "welcome!";
    pNode->handler = hello; 
	  AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
	  pNode=(tDataNode*)malloc(sizeof(tDataNode));
	  pNode->cmd="add";
  	pNode->desc="add two numbers";
	  pNode->handler=add;
	  AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "oppnum";
    pNode->desc = "output an oppsite number";
    pNode->handler = oppnum; 
  	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "compare";
    pNode->desc = "compare two numbers";
    pNode->handler = compare; 
  	AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "PI";
    pNode->desc = "const math number PI";
    pNode->handler = PI; 
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
    pNode = (tDataNode*)malloc(sizeof(tDataNode));
    pNode->cmd = "quit";
    pNode->desc = "Quit from Menu";
    pNode->handler = quit; 
    AddLinkTableNode(*ppLinktable,(tLinkTableNode *)pNode);
 
    return 0; 
}


tLinkTable * head = NULL;

int main()
{
    InitMenuData(&head); 
   /* cmd line begins */
    while(1)
    {
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler();
        }
   
    }
}

int help()
{
    ShowAllCmd(head);
    return 0; 
}
int hello()
{
	printf("hello,user\n");
	return 0;
}
int add()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", a + b);
	return 0;
}
int oppnum()
{
	int a;
	scanf("%d", &a);
	printf("%d\n", -a);
	return 0;
}
int compare()
{
	int a, b;
	scanf("%d %d", &a, &b);
	if (a<b)
		printf("%d<%d\n", a, b);
	else if (a == b)
		printf("%d=%d\n", a, b);
	else
		printf("%d>%d\n", a, b);
	return 0;
}
int PI()
{
	printf("3.14\n");
	return 0;
}

int quit()
{
	exit(0);
}
