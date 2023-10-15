
#include <stdio.h>
#include<stdlib.h>
struct node 
{
    int val;
    struct node *prev;
    struct node *next;
};
void create(struct node**front,struct node**rear,int no)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->val=no;
    if(*front==NULL)
    {
        *rear=*front=temp;
    }
    else
    {
        (*rear)->next=temp;
        temp->prev=*rear;
        *rear=temp;
    }
}
void display(struct node *front)
{
    int i=1;
    struct node *temp=front;
    while(temp!=NULL)
    {
        printf("%d  node %d ",i,temp->val);
        temp=temp->next;
        
        i++;
    }
    printf("%d",i-1);
}
int main() {
  int no;
  struct node * front=NULL,*rear=NULL;
  for(int i=0;i<10;i++)
  {
      scanf("%d",&no);
      create(&front,&rear,no);
  }
display(front);
    return 0;
}