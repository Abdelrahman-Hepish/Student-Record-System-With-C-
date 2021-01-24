#ifndef __LIST_H__
#define __LIST_H__
#include "configuration.h"
typedef void (*ptrf) (ListEntry);
#ifdef  LIMITED_SPACE
#define MAXLIST (100)
typedef struct  list
{
    int size ;
    ListEntry entry [MAXLIST] ;
}List;
#endif // LIMITED_SPACE
#ifdef UNLIMITED_SPACE
typedef  struct  listnode
{
    ListEntry entry ;
    struct listnode *next ;
}ListNode;
typedef struct list{
    int size , currentpos ;
    ListNode *head , *current ;
}List ;
#endif
void  CreateList(List *);
int   ListEmpty (List *) ;
int   ListFull (List *) ;
int   ListSize (List *) ;
void  InsertList (int ,ListEntry  ,List *) ;
void  DeleteList (int ,ListEntry * ,List *) ;
void  RetrieveList (int ,ListEntry * ,List *) ;
void  ReplaceList (int ,ListEntry ,List *) ;
void  TraverseList (List * ,ptrf ) ;
void  DestroyList (List *) ;

#endif // __LIST_H__
