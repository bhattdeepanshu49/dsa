
#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
}node;


struct node *insert(node *head, node ** rear,int num)
{
    node *temp=(node*)malloc (sizeof(node));
    temp->val=num;
    if(head==NULL)
    {
        (*rear)=head=temp;
    }
    else
    {
        (*rear)->next=temp;
        temp->next=NULL;
        (*rear)=temp;
    }
    return head;
}


node * insertAtFront(node*head,int num)
{
     node *temp=(node*)malloc (sizeof(node));
    temp->val=num;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
    return head;
}


void insertAtLocation(node * head, int pos ,int num)
{
    node *t=head,*r=NULL;
    node *temp=(node*)malloc (sizeof(node));
    temp->val=num;
    int i=0;
   
    while(i!=pos)
    {
        r=t;
        t=t->next;
        i++;
    }
    r->next=temp;
    temp->next=t;
    
}

void display(node *head)
{
    while(head !=NULL)
    {
        printf("%d ",head->val);
        head=head->next;
    }
}

int main() {
   node *head=NULL , *rear=NULL;
   head=insert(head,&rear,10);
   head=insert(head,&rear,20);
   head=insertAtFront(head,5);
   insertAtLocation(head, 2,15);
   display(head);
    return 0;
}