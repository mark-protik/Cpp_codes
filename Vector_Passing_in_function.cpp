#include <iostream>
#include <vector>
using namespace std;

// pass by value
void function1(vector<int> ara, int size)
{
    for (int i = 0; i < size; i++)
        ara[i] = 69;
}

// pass by reference
void function2(vector<int> &ara, int size)
{
    for (int i = 0; i < size; i++)
        ara[i] = 69;
}

int main()
{
    vector<int> ara{23, 34, 2, 4, 4};

    int size = ara.size();

    cout << "Pass by value : ";
    function1(ara, size);
    for (auto it = ara.begin(); it != ara.end(); it++)
        cout << *it << " ";

    cout << "\n\nPass by ref : ";
    function2(ara, size);
    for (auto it = ara.begin(); it != ara.end(); it++)
        cout << *it << " ";

    cout << endl
         << endl
         << endl;

    //! in array :>

    cout << "In array : \n";
    int arra[] = {1, 2, 3, 4};

    cout << &arra[0] << endl;
    cout << &arra << endl;
    cout << arra << endl;

    //! in vector :>

    cout << "\n\nIn vector : \n";

    cout << &ara[0] << endl;
    cout << &ara << endl;
    // cout << ara << endl;

    return 0;
}