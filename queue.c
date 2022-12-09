#include <stdio.h>
#include <stdlib.h>
#define max 10
int ar[max], front = -1, rear = -1;

void enqueue()
{
    int item;
    if (rear == max-1)
    {
        printf("Queue is overflow\n");
    }
    else if (rear == -1 && front == -1)
    {
        printf("Enter item\t");
        scanf("%d", &item);
        front++;
        rear++;
        ar[rear] = item;
    }
    else
    {
        printf("Enter item\t");
        scanf("%d", &item);
        rear++;
        ar[rear] = item;
    }
}
void dequeue()
{
    int temp;
    if (rear == -1 && front == -1)
    {
        printf("Queue is underflow\n");
    }
    else if (rear == front)
    {
        temp = ar[front];
        front=-1;
        rear=-1;
        printf("%d is removed successfully\n", temp);  
    }
    else
    {
        temp = ar[front];
        front++;
        printf("%d is removed successfully\n", temp);
    }
}
void peek()
{
    if (rear == -1 && front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d\t", ar[i]);
        }
    }
}
void main()
{
    int c;
    while (1)
    {
        printf("Enter---> 1 for insert\t2 for remove\t3for peek\t4 for exit\t");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            printf("Program end\t");
            exit(0);
        default:
            printf("Wrong input\n");
        }
    }
}