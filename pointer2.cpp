#include <iostream>
using namespace std;

void display(int &a) // pass by reference via reference object
{
    cout << endl;
    cout << "in display function : \n";

    cout << "a          : " << a << endl;
    cout << "&a         : " << &a << endl;
    cout << endl;
}
void display2(int *a) // pass bu reference via pointer
{
    cout << "in display function 2 : \n";

    cout << "a           : " << a << endl;
    cout << "&a          : " << &a << endl;
    cout << "*a          : " << *a << endl;
}
void display3(int *&ptr)
{
    cout << "\nin display function 3 : \n";

    cout << "ptr         : " << ptr << endl;
    cout << "&ptr        : " << &ptr << endl;
    cout << "*&ptr       : " << *&ptr << endl;
    cout << "**&ptr      : " << **&ptr << endl;
}
void display4(int *ptr)
{
    cout << "\nin display function 4 : \n";

    cout << "ptr         : " << ptr << endl;
    cout << "&ptr        : " << &ptr << endl;
    cout << "*ptr        : " << *ptr << endl;
    cout << "*&ptr       : " << *&ptr << endl;
}
int main()
{
    int a = 10;
    int *ptr = &a;
    *ptr = 69;

    cout << "in main function : \n";

    cout << "&a          : " << &a << endl;
    cout << "&ptr        : " << &ptr << endl;
    cout << "a           : " << a << endl;
    cout << "ptr         : " << ptr << endl;
    cout << "*ptr        : " << *ptr << endl;

    int *ptr3 = ptr;
    cout << "\na pointer pointing to a pointer : \n";

    cout << "ptr3        : " << ptr3 << endl;
    cout << "&ptr3       : " << &ptr3 << endl;
    cout << "*ptr3       : " << *ptr3 << endl;

    display(a);
    display2(&a);

    cout << "\nafter declaring pointer to pointer  : \n";

    int **ptr2 = &ptr;
    cout << "ptr2         : " << ptr2 << endl;
    cout << "&ptr2        : " << &ptr2 << endl;
    cout << "*ptr2        : " << *ptr2 << endl;
    cout << "**ptr2       : " << **ptr2 << endl;

    display3(ptr);
    display4(ptr);

    // cout << a << endl;

    // cout << a;
}