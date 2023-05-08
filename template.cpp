#include <iostream>
using namespace std;

/*
if I used swap instead of Swap, there was a problem. In standard namespace(std)
already there is function named swap.
*/
template <typename T> // declaring a template
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
/*void swap(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}*/
int main()
{
    int a, b;
    a = 5;
    b = 10;
    cout << a << " - " << b << endl;
    Swap(a, b);
    cout << a << " - " << b << endl;

    char c, d;
    c = 'c';
    d = 'd';
    cout << c << " - " << d << endl;
    Swap(c, d);
    cout << c << " - " << d << endl;

    /*
    the thing is we need to overload the function for int data type and also for char data type.
    so later if we get double or string value , we need to construct these types of swap function!
    which is similar code writing again and again...
   ! So, devs had come with an idea to not to repeat code anymore and the way is by using template
    */
}