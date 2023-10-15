#include<stdio.h>
int oper(char s)
{
    switch(s)
    {
        case '+':return 2;
        case '-':return 2;
        case '(':return 1;
        case ')':return 3;
    }
    return 0;
}
void push(int st[],int no,int n,int *first)
{
    if(*first>=n)
    {
        printf("stack is full");
    }
    else
    {
        (*first)++;
        st[*first]=no;
    }
}
int pop(char st[],int *first)
{

}
int main()
{
    char str[100];
    int n;
    scanf("%d",&n);
    str[n];
    gets(str);
    int first=-1;
    int stack[n];
    int no=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]!='+'&&str[i]!='-'&&str[i]!='('&&str[i]!=')')
        {
               no=no*10+(str[i]-'0');
        }
        else
        {
            if(no!=0)
            push(stack,no,n,&first);
            else
            {
                push(stack,oper(str[i]),n,&first);
            }
        }
    }
}