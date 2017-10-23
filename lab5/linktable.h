

#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#include <pthread.h>

#define SUCCESS 0
#define FAILURE (-1)


typedef struct LinkTableNode
{
    struct LinkTableNode * pNext;
}tLinkTableNode;


typedef struct LinkTable
{
    tLinkTableNode *pHead;
    tLinkTableNode *pTail;
    int			SumOfNode;
    pthread_mutex_t mutex;
}tLinkTable;

tLinkTable * CreateLinkTable();

int DeleteLinkTable(tLinkTable *pLinkTable);

int AddLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode);

int DelLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode);

tLinkTableNode * SearchLinkTableNode(tLinkTable *pLinkTable, int Conditon(tLinkTableNode * pNode));

tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);

tLinkTableNode * GetNextLinkTableNode(tLinkTable *pLinkTable,tLinkTableNode * pNode);

#endif 


