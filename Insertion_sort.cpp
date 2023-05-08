#include <iostream>
using namespace std;

void selection_sort(int ara[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = ara[i];
        int j = i - 1;
        while (j >= 0 && ara[j] > temp)
        {
            ara[j + 1] = ara[j];
            j--;
        }
        ara[j+1] = temp;
    }
}
int main()
{
    int ara[] = {9, 7, 6,15, 4, 3, 2, 1};
    int size = sizeof(ara) / sizeof(ara[0]);
    selection_sort(ara, size);
    for (int x : ara)
    {
        cout << x << " ";
    }
}