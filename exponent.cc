#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// int* stringToInt(char str[], int n) {
//     // int *arr = (int*)malloc(n * sizeof(int)); 
//     int no,p;
//     int j = 0;

//     for (int i = 0; i < n; i++) 
//     {
//         if (str[0] == 'x')
//         {
//             no = 1;
//         } 
//         else if (str[i] >= '0' && str[i] <= '9') 
//         {
//             int num = 0;
//             while (i < n && str[i] >= '0' && str[i] <= '9') 
//             {
//                 num = num * 10 + (str[i] - '0');
//                 i++;
//             }
//             i--;
//             no = num;
//             j++;
//         }
//         else if((str[i]=='+'||str[i]=='-')&&str[i+1]=='x')
//         {
//             no=1;
//             j++;
//         }
//         else if((str[i+1]=='+'||str[i]=='-')&&str[i]=='x')
//         {
//             no=1;
//             j++;
//         }
//     }
    

//     return head;
// }
// node *stringToInt(char str[]) {
//     node *head = NULL;
//     int i = 0;
//     int len = strlen(str);

//     while (i < len) {
//         int coef = 0, expo = 0;
//         int sign = 1;

//         // Check for the sign
//         if (str[i] == '-') {
//             sign = -1;
//             i++;
//         } else if (str[i] == '+') {
//             i++;
//         }

//         // Read coefficient
//         while (i < len && (str[i] >= '0' && str[i] <= '9')) {
//             coef = coef * 10 + (str[i] - '0');
//             i++;
//         }
//         coef *= sign; // Apply the sign

//         // Skip 'x'
//         i++;

//         // Read exponent
//         while (i < len && (str[i] >= '0' && str[i] <= '9')) {
//             expo = expo * 10 + (str[i] - '0');
//             i++;
//         }

//         // Insert the term into the linked list
//         head = create(head, coef, expo);
//     }

//     return head;
// }
// void create()
// {

// }
// void display()
// {

// }
// int main()
// {
//     char p[100],q[100];
//     gets(p);
//     gets(q);
//     node*head,*ptr;
//     int n = strlen(p);
//     int m = strlen(q);
//     int *p = stringToInt(p, n);


// }
struct node{
    int data;
    int power;
    struct node*next;
};
struct node* create(struct node*head,int n,int p)
{   struct node *t;
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    temp->data=n;
    temp->power=p;
    temp->next=NULL;
    if(head==NULL|| p > head->power)
    {
        temp->next = head;
        head = temp;
    }
    else
    { 
        t=head;
        while(t->next!= NULL && t->next->power >=p)
    {
        t=t->next;
        temp->next = t->next;
        t->next = temp;
    }
    }
    return head;
}
 
void display(struct  node* head)
{
      struct node* temp=head;
      while(temp)
      {
        printf("%d\n",temp->data);
        temp=temp->next;
      }
}
// void add(struct node*head1,struct node *head2)
// {
//     struct node *ptr1=head1;
//      struct node *ptr2=head2;
//       struct node *head3=NULL;
//      while(ptr1!=NULL && ptr2!=NULL)
//      {
//         if(ptr1->power>ptr2->power)
//         {
//             head3=create(head3,ptr1->data + ptr)
//         }
//      }
// }
struct node *stringToInt(char str[]) {
    node *head = NULL;
    int i = 0;
    int len = strlen(str);

    while (i < len) {
        int coef = 0, expo = 0;
        int sign = 1;

        // Check for the sign
        if (str[i] == '-') {
            sign = -1;
            i++;
        } else if (str[i] == '+') {
            i++;
        }

        // Read coefficient
        while (i < len && (str[i] >= '0' && str[i] <= '9')) {
            coef = coef * 10 + (str[i] - '0');
            i++;
        }
        coef *= sign; // Apply the sign

        // Skip 'x'
        i++;

        // Read exponent
        while (i < len && (str[i] >= '0' && str[i] <= '9')) {
            expo = expo * 10 + (str[i] - '0');
            i++;
        }

        // Insert the term into the linked list
        head = create(head, coef, expo);
    }

    return head;
}
int main()
{
    char str[100],str1[100];
    gets(str);
    gets(str1);
    struct node * head1=NULL, *head2 = NULL;
    head1= stringToInt(str);
    head2= stringToInt(str1);
    
    return 0;  
}