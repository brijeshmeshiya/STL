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

/* This Function finds tail in link list
   Argument 1) : h = (head of linked list)
   	    2) : t = (tail of linked list)
*/
void find_tail(struct node *h,struct node **t)
{
if(h==NULL)
{
cout<<"Can't Find Tail Since Link list is empty"<<endl;
*t=NULL;
}
else
{
while(h->next!=NULL)
{
h=h->next;
}
*t=h;
}
return ;
}

/* This Function Push New Node At End In Existing Link List
   Argument : 1) h = (head of linked list)  
    	      2) d = (data - some integer value) 
*/
void push_back(struct node **h,int d)
{
struct node *t = (struct node *)malloc(sizeof(struct node));
t->data=d;
t->next=NULL;
if(*h==NULL)
{
*h=t;
}
else
{
struct node *tail=NULL;
find_tail(*h,&tail);
tail->next=t;
}
return;
}


