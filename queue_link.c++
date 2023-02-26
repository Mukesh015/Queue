#include <iostream>
// creating custom data-type...
typedef struct list
{
    int data;
    struct list *link;
} ls;
// Declaration...
ls *front = NULL;
ls *rear = NULL;
// Queue insertion function...
ls *enqueue()
{
    ls *newnode;
    newnode = new ls;
    if (newnode != NULL)
    {
        std::cout << "Enter data\t";
        std::cin >> newnode->data;
        newnode->link = NULL;
        if (rear == NULL && front == NULL)
        {
            rear = front = newnode;
        }
        else
        {
            rear->link = newnode;
            rear = newnode;
        }
    }
    else
    {
        std::cout<<"Queue is overflow"<<std::endl;
    }
    return rear;
}
// creating deleting function...
ls *dequeueu()
{
    ls *temp;
    if (rear == NULL && front == NULL)
    {
        std::cout << "Queue is Underflow" << std::endl;
    }
    else if (front == rear)
    {
        std::cout << front->data << " is deleted" << std::endl;
        front = rear = NULL;
    }
    else
    {
        temp = front;
        std::cout << front->data << " is deleted" << std::endl;
        front = front->link;
        free(temp);
    }
    return front;
}
void display()
{
    ls *temp = front;
    while (temp!= rear)
    {
        std::cout << temp->data << "\t";
        temp=temp->link;
    }
    std::cout << temp->data << std::endl;
}
int main()
{
    int c;
    while (1)
    {
        std::cout << "Enter 1 for enqueue 2 for dequeue 3 for display\t";
        std::cin >> c;
        switch (c)
        {
        case 1:
            rear = enqueue();
            break;
        case 2:
            front = dequeueu();
            break;
        case 3:
            display();
            break;
        default:
            std::cout << "wrong input" << std::endl;
            break;
        }
    }
    return 0;
}