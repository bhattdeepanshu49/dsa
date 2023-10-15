#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
 int coeff;
 int exp;
 struct Node *next;
}*poly=NULL;
void create()
{
 struct Node *t,*last=NULL;
 int num,i;
 
 printf("Enter number of terms");
 scanf("%d",&num);
 printf("Enter each term with coeff and exp\n");
 
 for(i=0;i<num;i++)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 scanf("%d%d",&t->coeff,&t->exp);
 t->next=NULL;
 if(poly==NULL)
 {
 poly=last=t;
 }
 else
 {
 last->next=t;
 last=t;
 }
 }
}
int* stringToInt(const char str[], int n) {
    int *arr = (int*)malloc(n * sizeof(int)); // allocate memory for the integer array
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] == 'x') {
            arr[j] = 1;
            j++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            int num = 0;
            while (i < n && str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i] - '0');
                i++;
            }
            i--; // compensate for the extra increment in the loop
            arr[j] = num;
            j++;
        }
    }

    // Resize the array to fit the actual number of elements
    arr = (int*)realloc(arr, j * sizeof(int));

    return arr;
}


void Display(struct Node *p)
{
 while(p)
 {
 printf("%dx%d +",p->coeff,p->exp);
 p=p->next;
 }
 printf("\n");
}
long Eval(struct Node *p, int x)
{
 long val=0;
 
 while(p)
 {
 val+=p->coeff*pow(x,p->exp);
 p=p->next;
 }
 return val;
}
int main() {
    char str[] = "x2+3x+4";
    int n = strlen(str);
    int *p = stringToInt(str, n);
     
    for (int i = 0; i < n; i++) {
        printf("%d\n", p[i]);
    }

    free(p); // Don't forget to free the dynamically allocated memory

    return 0;
}