#include <iostream>
using namespace std;
void selectionSort(int ara[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        cout << "\n\nminimum index : " << min << endl;
        cout << "current position : ";
        for (int index = 0; index < size; index++)
        {
            cout << ara[index] << ' ';
        }

        for (int j = i + 1; j < size; j++)
        {
            cout << "\nIndex of j : " << j;
            if (ara[min] > ara[j])
            {
                min = j;
                cout << "\nmin = " << min;
            }
        }
        int temp;
        temp = ara[i];
        cout << "\ntemp = "
             << "ara[" << i << "] = " << ara[i];
        ara[i] = ara[min];
        cout << "\nara[" << i << "] = "
             << "ara[" << min << "] = " << ara[min];
        ara[min] = temp;
        cout << "\nara[" << min << "] = "
             << "temp = " << ara[min];
    }
}
int main()
{
    int ara[] = {9, 1, 7, 5, 4, 3, 0};
    int size = sizeof(ara) / sizeof(ara[0]);

    selectionSort(ara, size);

    cout << "\n\nsorted array : \n";
    for (int x : ara)
    {
        cout << x<<' ' ;
    }
}