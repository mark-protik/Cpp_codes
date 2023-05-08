#include <iostream>
using namespace std;

void selection_sort(int ara[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (ara[i] > ara[j])
            {
                min = j;
            }
        }
        int temp = ara[i];
        ara[i] = ara[min];
        ara[min] = temp;
    }
}
int main()
{
    int ara[] = {9, 8, 7, 6, 5, 4, 3, 3, 1};
    int size = sizeof(ara) / sizeof(ara[0]);

    selection_sort(ara, size);

    for (int x : ara)
    {
        cout << x << " ";
    }
}