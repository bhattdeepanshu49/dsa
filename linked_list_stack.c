#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node* push(struct node*head,int n)
{
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->next=NULL;
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
int pop(struct node *head)
{
    if(head==NULL)
    return -1;
    struct node*temp=head;
    head=head->next;
    int x=temp->data;
    temp->next=NULL; 
    free(temp);
    return x;
}
void display(struct  node* head)
{
      struct node* temp=head;
      printf("stack is:");
      while(temp)
      {
        printf(" %d",temp->data);
        temp=temp->next;
        
      }
}
int main()
{
 int n;
 scanf("%d",&n);
 int arr[n];
 struct node*head=NULL;
 for(int i=0;i<n;i++)
 {
    scanf("%d",&arr[i]);
 }
 for(int i=0;i<n;i++)
 {
   head= push(head,arr[i]);
 }
display(head);
int no=pop(head);
printf("\nDeleted no :%d",no); 
printf("\nName -Deepanshu Bhatt\n Section - B1 \n Roll.NO - 27 " );
return 0;

}