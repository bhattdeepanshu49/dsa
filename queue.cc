#include<stdio.h>
void enqueue(int qu[] , int *f, int *r,int n,int ch)
{
    if(*r ==n-1)
    {
        printf(" Queue is full");
    }
    if((*f) == -1)
    {
        (*f)++;
        (*r)++;
         qu[*f]=ch;
    }
    else
    {
        (*r)++;
        qu[*r] =ch;
    } 
}
int dequeue(int qu[],int *front,int *rear)
{
    int t;
    if((*front)==-1)
    {
        printf("Queue is empty");
    }
    else
    {
        t=qu[*front];
        (*front)++;
        if((*front)==*(rear+1))
        {
            *front=-1;
            *rear=-1;
        }
    }
    return t;
}
void display(int rear,int front,int q[])
{ 
while(front!=rear)
{
    printf("%d ",q[front]);
    front++;
}
printf("%d",q[rear]);
}
int main()
{
    int n , front= -1,rear=-1;
    scanf("%d" , &n);
    int arr[n] , queue[n];
    for(int i = 0 ; i<n ; i++)
    scanf("%d" , &arr[i]);
    for(int i = 0 ; i<n ; i++)
    enqueue( queue , &front, &rear, n, arr[i]);
    display(rear,front,queue);
    int val=dequeue(queue,&front,&rear);
    printf("\n Deleted element: %d",val);
    printf("\nName -Deepanshu Bhatt\n Section - B1 \n Roll.NO - 27 " );
}