/*
Singly linked list
1.Creating
2.Sorting
3.Insertion
4.Deletion
*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

// create a node
struct node{
 int data;
 struct node *next;
};


//create a linked list
//NOTE- the time and space of this function is (oder of N)
struct node* create(int a[],int n ,struct node *first)
{
    int i;
    struct node *temp,*last;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for( i=1;i<n;i++)
    {
         temp=(struct node*)malloc(sizeof(struct node));
         temp->data=a[i];
         temp->next=NULL;
         last->next=temp;
         last=temp;
    }  
    return first;   
}


//display a linked list
//NOTE- the time and space of this function is (oder of N)
void display(struct node *first)
{
  
    while(first!=NULL)
    {
        printf("%d\n",first->data);
        first=first->next;
    }

}


//display all element by recurive function 
void see(struct node *first)
{
    if(first==0)
    return ;
    else
    {
         printf("%d\n",first->data);
         return see(first->next);
    }
}


//add all the  value of linked list
//NOTE- the time and space of this function is (oder of N)
int sum(struct node*first)
{
    int add=0;
    while(first!=NULL)
    {
        add+=first->data;
        first=first->next;
    }
    return add;
}



//add all element by recurive function 
//NOTE- the time and space of this function is (oder of N)
int add(struct node*first)
{
    if(first==NULL)
    return 0;
    else
    {
        return add(first->next)+first->data;
    }
}


//Maximum Element in a Linked List
int maxElement(struct node *first)
{
    int max=0;
    while(first!=NULL)
    {
        if(first->data>max)
        max=first->data;
        first=first->next;
    }
    return max;
}


//seraching in a linked list
/*there are two sorting techinque :
1.Binary search
2.Linear search

In linked list we can perform binary search because we can't jump in the middle of a linked list directly
So we do linear search.
*/
 bool searching(struct node *first,int element)
{
   while(first!=NULL)
   {
      if(element==first->data)
      return 1;
      first=first->next;
   }
   return 0;
}


//insertion at a first place
//max-O(n)
//min-O(1)
void insert(struct node *first,int pos,int x)
{
    struct node*t,*p;
 if(pos==0)
 {
 t=(struct node*)malloc(sizeof(struct node));
 t->data=x;
 t->next=first;
 first=t;
 }
 else if(pos>0)
 {
    p=first;
    for(int i=0;i<pos-1&&p;i++)
    p=p->next;
    if(p)
    {
        t=(struct node*)malloc(sizeof(struct node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
 }

}

int main()
{
    struct node *first=NULL;
    first=(struct node*)malloc(sizeof(struct node));
    int a[]={1,2,3,4,5};
    int n=5;
    int element=3;
    create(a,n,first);
    display(first);
    // int adds=sum(first);
    // printf("%d\n",adds);
    // int sum=add(first);
    // printf("%d\n",sum);
    // see(first);
    // int max=maxElement(first);
    // printf("%d\n",max);
    // printf("%d",searching(first,element));
    // return 0;
    int pos=0,x=45;
    insert(first,pos,x);
    display(first);
}