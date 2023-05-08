#include <iostream>
using namespace std;
// #define SIZE 10;

class Stack
{
public:
    static const int size = 5;
    int arr[size] = {0};
    int front = -1;
    int rear = -1;

    void push(int data)
    {
        if (front == -1 && rear == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        else if (front != -1 && rear + 1 == size)
        {
            cout << "\nStack is overflow!" << endl;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    void pop()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nStack is empty!" << endl;
        }
        else if (front == 0 && rear == 0)
        {
            cout << "\npoped element : " << arr[rear] << endl;
            arr[rear] = 0;
            front = rear = -1;
        }
        else
        {
            cout << "\npoped element : " << arr[rear] << endl;
            arr[rear] = 0;
            rear--;
        }
    }
    void top()
    {
        if (front == -1 && rear == -1)
        {
            cout << "\nStack is empty!" << endl;
        }
        else
        {
            cout << "\nTop element : " << arr[rear] << endl;
        }
    }
    void display()
    {
        cout << endl;
        for (int x : arr)
        {
            cout << x << " ";
        }
    }
};

int main()
{
    Stack n;
    n.push(1);
    n.push(2);
    n.push(3);
    n.push(4);
    n.display();
    n.push(5);
    n.pop();
    n.pop();
    n.pop();
    n.pop();
    n.pop();
    n.display();
    n.pop();
    n.pop();
    n.push(1);
    n.display();
}