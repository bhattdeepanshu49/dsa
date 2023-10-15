#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* create(struct node*head,struct node **rear,int n)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        (*rear)=temp;
    }
    else
    {
        (*rear)->next=temp;
        (*rear)=temp;
    }
    return head;
}

void display(struct  node* head)
{
      struct node* temp=head;
      printf("Linked list :");
      while(temp)
      {
        printf("%d ",temp->data);
        temp=temp->next;
      }
}
int delete(struct node* head)
{
  struct node* temp=head,*p=NULL;
  while(temp->next!=NULL)
  {
    p=temp;
    temp=temp->next;

  }
  int x=temp->data;
  p->next=NULL;
  free(temp);
  return x;
}
int main()
{
 int n;
 scanf("%d",&n);
 int arr[n];
 struct node*head=NULL,*rear=NULL;
 for(int i=0;i<n;i++)
 {
    scanf("%d",&arr[i]);
 }
 for(int i=0;i<n;i++)
 {
   head= create(head,&rear,arr[i]);
   if(i==0)
   {
    rear=head;
   }
 }
display(head);
int val=delete(head);
printf("\nDeleted element: %d",val);
printf("\nName -Deepanshu Bhatt\n Section - B1 \n Roll.NO - 27 " );
return 0;

}
