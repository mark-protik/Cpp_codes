#include <iostream>
using namespace std;

void function(int **ara, int row, int col)
{
    cout << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << "enter values : ";
            cin >> ara[i][j];
        }
    }
}

int main()
{
    int row, col;
    cout << "\nEnter row & col : ";
    cin >> row >> col;

    // creating dynamic memory
    int **ara = new int *[row]; // returing address of another array of addresses

    for (int i = 0; i < row; i++)
    {
        ara[i] = new int[col]; // creating col array dynamically
    }

    // taking values
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            ara[i][j] = (i * col) + j;
        }
    }

    // printing values before sending to the function
    // printing values
    for (int i = 0; i < row; i++)
    {
        cout << "ara[" << i << "] = ";
        for (int j = 0; j < col; j++)
        {
            cout << ara[i][j] << " ";
        }
        cout << endl;
    }

    // sending to function
    function(ara, row, col);

    // printing values
    for (int i = 0; i < row; i++)
    {
        cout << "ara[" << i << "] = ";
        for (int j = 0; j < col; j++)
        {
            cout << ara[i][j] << " ";
        }
        cout << endl;
    }

    // deallocating memory
    for (int i = 0; i < row; i++)
    {
        delete[] ara[i];
        ara[i] = NULL;
    }
    delete[] ara;
    ara = NULL;

    return 0;
}