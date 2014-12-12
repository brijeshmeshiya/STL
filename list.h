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

/* This functions delete node from linked list
   Argument : 1) h= (head of link list) - May Modifies head Pointer
              2) d= (data to delete - some integer value)
*/
void remove(struct node **h,int d)
{
if(*h==NULL)
{
cout<<"Can't Delete Node From Empty Link List"<<endl;
}
else if((*h)->data==d)
{
struct node *t = *h;
cout<<"Node Is deleted with data : "<<d<<" And Head Pointer is changed"<<endl;
*h = (*h)->next;
free(t);
}
else
{
struct node *t= *h;
while(t->next!=NULL && t->next->data!=d)
{
t=t->next;
}
if(t->next!=NULL && t->next->data==d)
{
cout<<"Node with data : "<<d<<" Is Deleted"<<endl;
struct node *temp=t->next;
t->next=temp->next;
free(temp);
}
else
{
cout<<"No Node Found With Data : "<<d<<endl;
}
return ;
}
}

/* This functions delete all duplicate node from linked list defined in argument
   Argument : 1) h= (head of link list) - May Modifies head Pointer
              2) d= (data to delete - some integer value)
*/
void remove_all(struct node **h,int d)
{
if(*h==NULL)
{
cout<<"Can't Delete Node From Empty Link List"<<endl;
}
else if((*h)->data==d)
{
struct node *t = *h;
cout<<"Node Is deleted with data : "<<d<<" And Head Pointer is changed"<<endl;
*h = (*h)->next;
free(t);
remove_all(h,d);
}
else
{
struct node *t= *h;
while(t!=NULL && t->next!=NULL)
{
if(t->next->data==d)
{
cout<<"Node with data : "<<d<<" Is Deleted"<<endl;
struct node *temp=t->next;
t->next=temp->next;
free(temp);
}
if(t!=NULL)
{
t=t->next;
}
}
if(t!=NULL && t->next!=NULL && t->next->data==d)
{
cout<<"Node with data : "<<d<<" Is Deleted"<<endl;
struct node *temp=t->next;
t->next=temp->next;
free(temp);
}
return ;
}
}
  
/* Function to traverse link list
   Argument : 1) h =(head of linked list)
*/
void traverse(struct node *h)
{
if(h==NULL)
{
cout<<"No Link List To Traverse."<<endl;
}
else
{
cout<<"Traversal : ";
while(h!=NULL)
{
cout<<h->data<<" ";
h=h->next;
}
cout<<endl;
}
return ;
}

/* This functions delete all duplicate node from linked list defined in argument
   Argument : 1) h= (head of link list) - May Modifies head Pointer
              2) d= (data to delete - some integer value)
*/
void remove_all(struct node **h,int d)
{
if(*h==NULL)
{
cout<<"Can't Delete Node From Empty Link List"<<endl;
}
else if((*h)->data==d)
{
struct node *t = *h;
cout<<"Node Is deleted with data : "<<d<<" And Head Pointer is changed"<<endl;
*h = (*h)->next;
free(t);
remove_all(h,d);
}
else
{
struct node *t= *h;
while(t!=NULL && t->next!=NULL)
{
if(t->next->data==d)
{
cout<<"Node with data : "<<d<<" Is Deleted"<<endl;
struct node *temp=t->next;
t->next=temp->next;
free(temp);
}
if(t!=NULL)
{
t=t->next;
}
}
if(t!=NULL && t->next!=NULL && t->next->data==d)
{
cout<<"Node with data : "<<d<<" Is Deleted"<<endl;
struct node *temp=t->next;
t->next=temp->next;
free(temp);
}
return ;
}
}

