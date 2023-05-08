#include <iostream>
using namespace std;

#define SIZE 5
#define UNSUCCESS_VALUE '!'

class Queue
{

    // static const int size = 5;
    char ara[SIZE] = {'\0'};
    int front = -1;
    int rear = -1;

public:
    void enqueue(char data)
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            ara[rear] = data;
        }
        else
        {
            int expectedIndex = (rear + 1) % SIZE;
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
    char dequeue()
    {
        if (front == -1 && rear == -1)
            return UNSUCCESS_VALUE;

        else if (front == rear)
        {
            char item = ara[front];
            ara[front] = '\0';
            front = rear = -1;
            return item;
        }
        else
        {
            char item = ara[front];
            ara[front] = '\0';
            front = (front + 1) % SIZE;
            return item;
        }
    }
    void front_value()
    {
        if (front == -1)
            cout << "empty!" << endl;
        else
            printf("\nFront value is : %c\n", ara[front]);
    }
    void display()
    {
        printf("\n");
        if (front == -1 && rear == -1)
            cout << "queue is empty!\n";
        for (int x : ara)
            printf("%c\t", x);
        printf("\n");
    }
    char n0n_reapting_char()
    {
        int x = front;
        bool flag = false;
        if (front == -1 && rear == -1)
            return UNSUCCESS_VALUE;
        else
        {
            do
            {
                int count = 0;
                char value = ara[x];
                int inner_x = front;
                do
                {
                    if (value == ara[inner_x])
                        count++;
                    inner_x = (inner_x + 1) % SIZE;
                } while (inner_x != front);
                if (count == 1)
                    return value;
                else
                    flag = true;

                x = (x + 1) % SIZE;
            } while (x != front);
        }
        if (flag == true)
            return UNSUCCESS_VALUE;
    }
};

int main()
{
    Queue n;

    char choice;
    char item;
    do
    {
        printf("\nEnter choice:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Print\n");
        printf("4. Front_value\n");
        printf("5. Non_repeating_value\n");
        printf("6. Exit\n");
        scanf(" %c", &choice);
        switch (choice)
        {
        case '1':
        {
            printf("Enter item to enqueue: ");
            getchar();
            scanf("%c", &item);
            n.enqueue(item);
            break;
        }
        case '2':
        {
            char Item = n.dequeue();
            if (Item == UNSUCCESS_VALUE)
                cout << "queue is empty!" << endl;
            else
                cout << "dequed item : " << Item << endl;
            break;
        }
        case '3':
        {
            n.display();
            break;
        }
        case '4':
        {
            n.front_value();
            break;
        }
        case '5':
        {
            char value = n.n0n_reapting_char();
            if (value != UNSUCCESS_VALUE)
                cout << "Non repeated value : " << value << endl;
            else
                cout << "No repeated value\n";
            break;
        }
        case '6':
        {
            printf("Exiting program\n");
            exit(0);
        }
        default:
            printf("Invalid choice\n");
        }
    } while (1);
    return 0;
}