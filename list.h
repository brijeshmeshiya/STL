// This file contains functions related to link list

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
int data;
struct node *next;
};

/* Function to insert node into linked list at front
   Argument : 1) h=(head of list) or (null)
  	      2) d = (data - some integer value)
*/

void push_front(struct node **h,int d)
{

/* Allocate Node */

struct node *t = (struct node *)malloc(sizeof(struct node));
t->data=d;
t->next=NULL;


/* If No node exist till now */
if(*h==NULL)	
{
*h=t;
}
else	/* Make Allocated Node head And change its link to Previous Head */
{
t->next=*h;
*h=t;
}
return ;
}
