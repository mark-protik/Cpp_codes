#include <iostream>
using namespace std;

bool compare(int a, int b) { return a > b; }

int substract(int a, int b)
{
    if (compare(a, b))
        return a - b;
    else
        return b - a;
}

int main()
{
    cout << "address : " << substract << endl; // without the parentheses the name of the function will return the address of the function

    int (*funcPtr)(int, int) = substract; //>=> return type (* name of function)(argument or parameter);
    cout << funcPtr(34, 3);

    return 0;
}

/*
The use of function ptr...
!. it will create a pointer of the function
!!.it helps to optimize the code
*/