#include <stdlib.h>
#include "List.h"
#ifdef LIMITED_SPACE
void  CreateList(List *pl)
{
 pl->size = 0 ;
}
int  ListEmpty (List *pl)
{
    return  pl->size == 0 ;
}
int   ListFull (List *pl)
{
    return  pl->size == MAXLIST ;
}
int   ListSize (List *pl)
{
    return  pl->size ;
}
void  InsertList (int p,ListEntry e,List *pl)
{
    int i ;
    for(i=pl->size-1;i>=p;i++)
    {
        pl->entry[i+1] = pl->entry[i] ;
    }
    pl->entry[p] = e;
    pl->size ++ ;
}
void  DeleteList (int p,ListEntry *pe ,List *pl)
{
    int i ;
    *pe = pl->entry[p] ;
    for(i=p;i<pl->size-1;i++)
    {
        pl->entry[i] = pl->entry[i+1] ;
    }
    pl->size -- ;
}
void  RetrieveList (int p,ListEntry *pe ,List *pl)
{
    *pe = pl->entry[p] ;
}
void  ReplaceList (int p,ListEntry e,List *pl)
{
    pl->entry[p] = e ;
}
void  TraverseList (List *pl ,ptrf visit)
{
    int i ;
    for(i=0;i<pl->size;i++)
    {
        visit (pl->entry[i]) ;
    }
}
void  DestroyList (List *pl)
{
    pl->size = 0 ;
}
#endif
#ifdef UNLIMITED_SPACE
void  CreateList(List *pl)
{
    pl->size = 0 ;
    pl->currentpos = 0 ;
    pl->head = NULL ;
    pl->current = NULL ;
}
int   ListEmpty (List *pl)
{
    return pl->size == 0 ;
}
int   ListFull (List *pl)
{
    return 0 ;
}
int   ListSize (List *pl)
{
    return pl->size ;
}
void  InsertList (int pos,ListEntry e ,List *pl)
{
    ListNode * p = (ListNode*)malloc(sizeof(ListNode)) ;
    p->entry = e ;
    if(pos == 0 )
    {
        p->next = pl->head ;
        pl->head = p ;
        pl->current = p ;
        pl->currentpos = 0 ;
    }
    else
    {
        if(pos<=pl->currentpos)
        {
            pl->currentpos = 0 ;
            pl->current = pl->head ;
        }
        for(;pl->currentpos<pos-1;pl->currentpos++)
        {
            pl->current = pl->current->next ;
        }
        p->next = pl->current->next ;
        pl->current->next = p ;
        pl->current = p ;
        pl->currentpos ++ ;
    }
    pl->size ++ ;
}
void  DeleteList (int pos,ListEntry *pe ,List *pl)
{
    ListNode  *tmp ;
    if(pos==0)
    {
        *pe = pl->head->entry ;
        pl->current = pl->head->next ;
        free(pl->head) ;
        pl->head = pl->current ;
        pl->currentpos = 0 ;
    }else
    {
        if(pos<=pl->currentpos)
        {
            pl->currentpos = 0 ;
            pl->current = pl->head ;
        }
        for(;pl->currentpos<pos-1;pl->currentpos++)
        {
            pl->current = pl->current->next ;
        }
        *pe = pl->current->next->entry ;
        tmp = pl->current->next ;
        pl->current->next=tmp->next ;
        pl->current = tmp->next ;
        pl->currentpos ++ ;
        free(tmp) ;
    }
    pl->size  -- ;
}
void  RetrieveList (int pos,ListEntry *pe ,List *pl)
{
    if(pos==0)
    {
        *pe = pl->head->entry ;
        pl->current = pl->head;
        pl->currentpos = 0 ;
    }else
    {
        if(pos<=pl->currentpos)
        {
            pl->currentpos = 0 ;
            pl->current = pl->head ;
        }
        for(;pl->currentpos<pos-1;pl->currentpos++)
        {
            pl->current = pl->current->next ;
        }
        *pe = pl->current->next->entry ;
        pl->currentpos ++ ;

    }
}
void  ReplaceList (int pos,ListEntry e ,List *pl)
{
    if(pos == 0 )
    {
     pl->head->entry = e ;
     pl->current = pl->head ;
     pl->currentpos = 0 ;
    }
    else
    {
        if(pos<=pl->currentpos)
        {
            pl->currentpos = 0 ;
            pl->current = pl->head ;
        }
        for(;pl->currentpos<pos-1;pl->currentpos++)
        {
            pl->current = pl->current->next ;
        }
        pl->current->next->entry = e ;
        pl->current = pl->current->next ;
        pl->currentpos ++ ;
    }

}

void  TraverseList (List *pl ,ptrf visit)
{
    ListNode *tmp = pl->head ;
    while (tmp)
    {
        visit (tmp->entry) ;
        tmp = tmp->next ;
    }

}
void  DestroyList (List *pl)
{
    while (pl->head)
    {
        pl->current = pl->head->next ;
        free(pl->head) ;
        pl->head = pl->current ;
    }
    pl->currentpos = 0 ;
    pl->size = 0 ;
}
#endif