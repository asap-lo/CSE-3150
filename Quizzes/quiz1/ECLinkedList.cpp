#include "ECLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/* get the length of the linked list: how many nodes in the linked list */
/* pHead: head node pointer to the linked list */
/* return the number of nodes of the linked list pointed by pHead */
int ECGetLinkedListLength(struct ECLinkedListNode *pHead )
{
  /* your code here */
  int count = 0;
  for(int i = 0; pHead != NULL; i++)
  {
    count++;
    pHead = pHead->pNext;
  }
  return count;
}

/* delete all nodes with a specific value from the linked list */
/* input: pHead: head node pointer to the linked list which to be processed */
/* input: val: all nodes with value equal to val should be deleted */
/* output: the pointer to the head ndoe of the linked list after the delete operation */
struct ECLinkedListNode *ECLinkedListDeleteVal(struct ECLinkedListNode *pHead, int val)
{
  /* your code here */
  struct ECLinkedListNode *cur= pHead;
  struct ECLinkedListNode *temp = pHead;
  while(cur!= NULL)
  {
    if(cur->value == val)
    {
      if(cur== pHead) 
      {
        pHead = pHead->pNext;
        free(cur);
        cur= pHead;
        continue;
      }
      temp->pNext = cur->pNext; 
      free(cur); 
      cur= temp->pNext; 
    }
    else 
    {
      temp = cur;
      cur= cur->pNext;
    }
  }
  return pHead; 
}
