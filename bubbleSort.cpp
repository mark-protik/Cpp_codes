#include <iostream>
using namespace std;
void bubbleSort(int ara[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        cout << "\n\npresent state of array : ";
        for (int i = 0; i < size; i++)
        {
            cout << ara[i] << ' ';
        }
        cout << "\n\nIndex of i = " << i;
        for (int j = 0; j < size - i - 1; j++)
        {
            cout << "\n\nIndex of j = " << j;
            if (ara[j + 1] < ara[j])
            {
                cout << "\n\nara [" << j << " + 1] < ara [" << j << "] = ";
                cout << "true";
                int temp;
                temp = ara[j + 1];
                cout << "\ntemp = "
                     << "ara [" << j << " + 1] = " << ara[j + 1];
                ara[j + 1] = ara[j];
                cout << "\nara [ " << j << " + 1 ]"
                     << " = ara [ " << j << " ] = " << ara[j];
                ara[j] = temp;
                cout << "\nara [" << j << "] = temp = " << ara[j];
                cout << "\n\npresent state of array : ";
                for (int i = 0; i < size; i++)
                {
                    cout << ara[i] << ' ';
                }
            }
        }
    }
}
int main()
{
    int ara[] = {9, 1, 7, 5, 4, 3, 0};
    int size = sizeof(ara) / sizeof(ara[0]);

    bubbleSort(ara, size);

    cout << "\n\nsorted array : \n";
    for (int x : ara)
    {
        cout << x << ' ';
    }
}