#include <iostream>
using namespace std;
int ar[5];
int front = -1, rear = -1;
void enqueue()
{
    int data;
    if (front == ((rear + 1) % 5))
    {
        printf("Queue overflow\n");
    }
    else if (rear == -1 && front == -1)
    {
        cout << "Enter data\t";
        cin >> data;
        rear = 0;
        front = 0;
        ar[rear] = data;
    }
    else
    {
        cout << "Enter data\t";
        cin >> data;
        rear = (rear + 1) % 5;
        ar[rear] = data;
    }
}
void display()
{
    int i = front;
    while (i != rear)
    {
        cout << ar[i] << "\t";
        i = (i + 1) % 5;
    }
    printf("%d\t", ar[i]);
}
void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout<<"Queue is underflow"<<endl;
    }
    else if (front==rear)
    {
        cout<<ar[front]<<" id deleted"<<endl;
        front=rear=-1;
    }
    else
    {
        cout<<ar[front]<<" id deleted"<<endl;
        front=(front+1)%5;
    }
}
int main()
{
    int c;
    while (1)
    {
        cout << "Enter 1 for enqueue 2 for display" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
        default:
            cout << "Enter a valid input\t" << endl;
        }
    }
    return 0;
}