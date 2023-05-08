#include <iostream>
using namespace std;
int *func(int *num, int size)
{
    static int ara[100];

    for (int i = 0; i < size; i++)
    {
        ara[i] = num[i] * 2;
    }
    cout << "\naddress of local ara : ";
    cout << ara << endl;
    cout << "\nprinting in function : \n";
    for (int i = 0; i < size; i++)
    {
        cout << ara[i] << endl;
    }
    return ara;
}
int main()
{
    int num[] = {10, 20, 30, 40, 50};
    int size = sizeof(num) / sizeof(num[0]);
    int *ptr = nullptr;
    ptr = num;
    cout << "\n\n        ******ARRAY******" << endl;
    cout << "\naddress of num[0]= " << &num[0] << endl;
    cout << "Value of num     = " << num << endl;
    cout << "Value of ptr     = " << ptr << endl;
    cout << "address of ptr   = " << &ptr << endl;
    cout << "Pointing to ptr  = " << *ptr << endl;
    int *ptrr = nullptr;

    ptrr = func(num, size);
    cout << "\nrecieved address by ptrr : "
         << ptrr;
    cout << "\naddress of ptrr : " << &ptrr << endl;
    cout << "\nprinting in Main function : \n";
    for (int i = 0; i < size; i++)
    {
        cout << ptrr[i] << endl;
    }
    return 0;
}