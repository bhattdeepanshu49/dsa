#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* enqueue(struct node*head,struct node **rear,int n)
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
int dequeue(struct node*head,struct node **rear)
{
    struct node* temp;
    temp=head;
    while(temp->next!=(*rear))
    {
        temp=temp->next;
    }
    int x=0;
    x=temp->next->data;
    temp->next=NULL;
    (*rear) =temp;
    return x;
}
void display(struct  node* head)
{
      struct node* temp=head;
      printf("queue is:");
      while(temp)
      {
        printf("  %d",temp->data);
        temp=temp->next;
        
      }
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
   head= enqueue(head,&rear,arr[i]);
   if(i==0)
   {
    rear=head;
   }
 }
display(head);
int no=dequeue(head,&rear);
printf("\nDeleted no :%d",no); 
printf("\nName -Deepanshu Bhatt\n Section - B1 \n Roll.NO - 27 " );
return 0;

}