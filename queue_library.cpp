#include <iostream>
using namespace std;

class Queue
{
public:
    static const int size = 5;
    int ara[size] = {0};
    int front = -1;
    int rear = -1;

    void enqueue(int data)
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            ara[rear] = data;
        }
        else
        {
            int expectedIndex = (rear + 1) % size;
            if (expectedIndex == front)
            {
                printf("Queue full\n");
                return;
            }
            else
            {
                rear = expectedIndex;
                ara[rear] = data;
            }
        }
    }
    void dequeue()
    {
        if (front == -1 && rear == -1)
        {
            printf("\nQueue is empty!\n");
            return;
        }
        else if (front == rear)
        {
            ara[front] = 0;
            front = rear = -1;
        }
        else
        {
            ara[front] = 0;
            front = (front + 1) % size;
        }
    }
    void front_value()
    {
        printf("\nFront value is : %d\n", ara[front]);
    }
    void display()
    {
        printf("\n");
        for (int x : ara)
        {
            printf("%d\t", x);
        }
    }
};

int main()
{
    Queue n;
    n.enqueue(10);
    n.enqueue(20);
    n.enqueue(30);
    n.enqueue(40);
    n.dequeue();
    n.dequeue();
    n.dequeue();
    n.enqueue(50);
    n.display();
    n.enqueue(60);
    n.enqueue(70);
    n.display();
    n.enqueue(80);
    n.dequeue();
    n.dequeue();
    n.dequeue();
    n.display();
    n.dequeue();
    n.dequeue();
    n.dequeue();
    n.dequeue();
    n.front_value();
}