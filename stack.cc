#include<stdio.h>
void push(int st[],int *top,int n,int no)
{
    if((*top) >= n)
    {
        printf( " Stack is full");
    }
    else
    {
        (*top)++;
        st[*top] = no;
    }
}
int pop(int st[],int *top)
{
    int n;
    if((*top)==-1)
    printf("Stack is empty");
    else
    {
         n=st[*top];
         (*top)--;
    }
    return n;
}
void display(int st[],int top)
{
    printf("stack is:");
    while(top>=0)
    {
         printf("%d ",st[top]);
         top--;
    }
}
int main()
{
    int n , top = -1;
    scanf("%d" , &n);
    int arr[n] , st[n];
    for(int i = 0 ; i<n ; i++)
    scanf("%d" , &arr[i]);
    for(int i = 0 ; i<n ; i++)
    push(st , &top , n , arr[i]);
    int val;
    val=pop(st,&top);
    printf( "deleted value: %d \n" , val );
    display(st,top);
    printf("\nName -Deepanshu Bhatt\n Section - B1 \n Roll.NO - 27 " );
    return 0;
}