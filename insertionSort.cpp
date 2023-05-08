#include <iostream>
using namespace std;
void insertionSort(int ara[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = ara[i];
        int j = i - 1;
        while (ara[j] > temp && j >= 0)
        {
            ara[j + 1] = ara[j];
            j--;
        }
        ara[j + 1] = temp;
    }
}
int main()
{
    int ara[] = {9, 1, 7, 5, 4, 3, 0};
    int size = sizeof(ara) / sizeof(ara[0]);

    insertionSort(ara, size);

    cout << "\n\nsorted array : \n";
    for (int x : ara)
    {
        cout << x << ' ';
    }
}