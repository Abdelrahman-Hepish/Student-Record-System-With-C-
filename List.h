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
/*
 * Description : CreateList is a function that initializes the List.
 * return      : No thing.
 * Complexity  : O(1).
 */
void  CreateList(List *);
/*
 * Description : ListEmpty is a function that Checks if the List is embty or not.
 * return      : 1 if Stack is empty and 0 if not empty.
 * Complexity  : O(1).
 */
int   ListEmpty (List *) ;
/*
 * Description : ListFull is a function that Checks if the List is full or not.
 * return      : 1 if Stack is full and 0 if not full.
 * Complexity  : O(1).
 */
int   ListFull (List *) ;
/*
 * Description : ListSize is a function that returns the number of elements in the List.
 * return      : the size of the Stack.
 * Complexity  : O(1).
 */
int   ListSize (List *) ;
/*
 * Description  : InsertList is a function that puts a new element in a detected position in the List increases it's size.
 * Precondition : the List is defined and created and not full.
 * return       : No thing.
 * Complexity   : O(N).
 */
void  InsertList (int ,ListEntry  ,List *) ;
/*
 * Description  : ReplaceList is a function that replaces an exist element with a new one in a detected position in the List.
 * Precondition : the List is defined and created and position is exists.
 * return       : No thing.
 * Complexity   : O(N).
 */
void  ReplaceList (int ,ListEntry ,List *) ;
/*
 * Description  : DeleteList is a function that removes one element from a detected position int the Lest and decreases it's size.
 * Precondition : the List is defined and created and not empty.
 * return       : No thing.
 * Complexity   : O(N).
 */
void  DeleteList (int ,ListEntry * ,List *) ;
/*
 * Description  : RetrieveList is a function that copies one element from a detected position int the Lese.
 * Precondition : the List is defined and created and not empty.
 * return       : No thing.
 * Complexity   : O(N).
 */
void  RetrieveList (int ,ListEntry * ,List *) ;
/*
 * Description  : TraverseList is a function that pass on all elements in the List and pass the element to the passed function in the parameters.
 * Precondition : the List is defined.
 * return       : No thing.
 * Complexity   : O(N).
 */
void  TraverseList (List * ,ptrf ) ;
/*
 * Description  : DestroyList is a function that destroys all element in the Lists and makes it as it was initialized.
 * Precondition : the List is defined.
 * return       : No thing.
 * Complexity   : O(N) in UNLIMITED_SPACE and O(1) in LIMITED_SPACE.
 */
void  DestroyList (List *) ;

#endif // __LIST_H__
