#include <iostream>
using namespace std;

void function(int *ara, int row)
{
    cout << endl
         << endl;

    for (int i = 0; i < row; i++)
        ara[i] = i * 10;
}
int main()
{
    int row;
    cout << "Enter row : ";
    cin >> row;

    // creating dynamic array
    int *ara = new int[row];

    // taking values
    for (int i = 0; i < row; i++)
        cin >> ara[i];

    // printing values before sending to the function
    for (int i = 0; i < row; i++)
        cout << ara[i] << " ";

    // to the function
    function(ara, row);

    // printing changed values
    for (int i = 0; i < row; i++)
        cout << ara[i] << " ";

    // address printing...
    cout << endl
         << endl;
    cout << ara << endl;
    cout << &ara << endl;
    cout << &ara[0] << endl;

    // deallocating memory
    delete[] ara;
    ara = NULL;

    return 0;
}