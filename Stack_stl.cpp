#include <iostream>
#include <stack>
// using namespace std;
using std::cin;
using std::cout;
using std::endl;
using std::stack;

void print(stack<int> &myStack)
{
    while (!myStack.empty())
    {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    myStack.pop();
    myStack.pop();

    if (myStack.empty())
        cout << "empty" << endl;
    else
        cout << "not empty" << endl;

    cout << "Size of my stack is " << myStack.size() << endl;

    print(myStack);

    cout << "Size of my stack is " << myStack.size() << endl;

    return 0;
}