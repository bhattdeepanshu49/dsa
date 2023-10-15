#include<stdio.h>
#include<string.h>
void push(char st[],char n,int *top)
{
   (*top)++;
   st[(*top)]=n;
}
char pop (char st[],int *top)
{
    if(*top==-1)
    {
        return 0;
    }
    char ch=st[*top];
    (*top)--;
    return ch;
}
int empty(int top)
{
 if(top==-1)
 {
    return 1;
 }
 return 0;
}
int main()
{
    int top=-1;
    char stack[100];
    char  s[100]="a+b/c-d*e";
    char ans[100]="";
    int n=strlen(s);
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            ans[j]=s[i];
            j++;
        }
        else
        {
            if(empty(top))
            {
                push(stack,s[i],&top);
            }
            else
            {
                if(s[i]>stack[top])
                {
                    push(stack,s[i],&top);
                }
                else
                {
                    while(!empty(top) && s[i]<=stack[top])
                    {
                        ans[j]=pop(stack,&top);
                        j++;
                    }
                   push(stack,s[i],&top);
                }  
            }
        }
    }
    printf("%s",ans);
}