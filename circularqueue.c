#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int isEmpty(int f, int r) {
    return f == -1;
}

int isFull(int f, int r, int n) {
    return ((r + 1) % n) == f;
}

void enqueue(int arr[], int *f, int *r, int a, int n) {
    if (isFull(*f, *r, n)) {
        printf("Queue is full\n");
    } else {
        if (*f == -1) {
            *f = 0;
        }
        *r = (*r + 1) % n;
        arr[*r] = a;
    }
}

int dequeue(int arr[], int *f, int *r, int n) {
    if (isEmpty(*f, *r)) {
        printf("Queue is empty\n");
        return -1; 
    } else {
        int t = arr[*f];
        if (*f == *r) {
            *f = -1;
            *r = -1;
        } else {
            *f = (*f + 1) % n;
        }
        return t;
    }
}

void display(int arr[], int f, int r, int n) {
    if (isEmpty(f, r)) {
        printf("Queue is empty\n");
        return;
    }

    int i = f;
    while (1) {
        printf("%d ", arr[i]);
        if (i == r) {
            break;
        }
        i = (i + 1) % n;
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of the queue: ");
    scanf("%d", &n);
    int arr[MAX_SIZE];
    int f = -1, r = -1;
    int a;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        enqueue(arr, &f, &r, a, n);
    }

    printf("Queue elements: ");
    display(arr, f, r, n);

    int dequeued = dequeue(arr, &f, &r, n);
    if (dequeued != -1) {
        printf("Dequeued element: %d\n", dequeued);
        printf("Queue elements after dequeue: ");
        display(arr, f, r, n);
    }
printf("\nName -Deepanshu Bhatt\n Section - B1 \n Roll.NO - 27 " );
    return 0;
}