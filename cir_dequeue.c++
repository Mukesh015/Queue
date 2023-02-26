#include <iostream>
#define size 5

int ar[size];
int front = -1;
int rear = -1;

void front_enqueue()
{
    int data;
    if ((front == 0 && rear == size - 1) || (front == rear + 1))
    {
        std::cout << "Queue is overflow" << std::endl;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        std::cout << "Enter data\t";
        std::cin >> data;
        ar[front] = data;
        std::cout << "Data inserted at " << front << " index" << std::endl;
    }
    else if (front == 0)
    {
        front = size - 1;
        std::cout << "Enter data\t";
        std::cin >> data;
        ar[front] = data;
        std::cout << "Data inserted at " << front << " index" << std::endl;
    }
    else
    {
        front--;
        std::cout << "Enter data\t";
        std::cin >> data;
        ar[front] = data;
        std::cout << "Data inserted at " << front << " index" << std::endl;
    }
}
void front_dequeue()
{
    if (front == -1 && rear == -1)
    {
        std::cout << "Queue is underflow" << std::endl;
    }
    else if (front == rear)
    {
        std::cout << ar[front] << " id deleted" << std::endl;
        std::cout << "Data deleted at " << front << " index" << std::endl;
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        std::cout << "Data inserted at " << front << " index" << std::endl;
        std::cout << ar[front] << " id deleted" << std::endl;
        front = 0;
    }
    else
    {
        std::cout << "Data inserted at " << front << " index" << std::endl;
        std::cout << ar[front] << " id deleted" << std::endl;
        front = (front + 1) % 5;
    }
}
void rear_enqueue()
{
    int data;
    if (front == (( rear+ 1) % 5))
    {
        printf("Queue overflow\n");
    }
    else if (rear == -1 && front == -1)
    {
        std::cout << "Enter data\t";
        std::cin >> data;
        rear = 0;
        front = 0;
        ar[rear] = data;
        std::cout << "Data inserted at " << rear << " index" << std::endl;
    }
    else if(rear==size-1){
        std::cout << "Enter data\t";
        std::cin >> data;
        ar[rear] = data;
        std::cout << "Data inserted at " << rear << " index" << std::endl;
    }
    else
    {
        std::cout << "Enter data\t";
        std::cin >> data;
        rear = (rear + 1) % 5;
        ar[rear] = data;
        std::cout << "Data inserted at " << rear << " index" << std::endl;
    }
}
void rear_dequeue()
{
    if (front == -1 && rear == -1)
    {
        std::cout << "Queue is underflow" << std::endl;
    }
    else if (front == rear)
    {
        std::cout <<ar[rear]<< " deleted at " << rear << " index" << std::endl;
        front = rear = -1;
    }
    else if (rear == 0)
    {
        std::cout <<ar[rear]<< " deleted at " << rear << " index" << std::endl;
        rear = size - 1;
    }
    else
    {
        std::cout <<ar[rear]<< " deleted at " << rear << " index" << std::endl;
        rear--;
    }
}
void display()
{
    int temp = front;
    while (temp != rear)
    {
        std::cout << ar[temp] << "\t";
        temp = (temp + 1) % size;
    }
    std::cout << ar[temp] << std::endl;
}
int main()
{
    int c;
    while (1)
    {
        std::cout << "Enter 1 for enqueue_front 2 for dequeue_front 3 for enqueue_rear 4 for de_rear 5 for display" << std::endl;
        std::cin >> c;
        switch (c)
        {
        case 1:
            front_enqueue();
            break;
        case 2:
            front_dequeue();
            break;
        case 3:
            rear_enqueue();
            break;
        case 4:
            rear_dequeue();
            break;
        case 5:
            display();
            break;
        default:
            std::cout << "Enter a valid input\t" << std::endl;
        }
    }
    return 0;
}