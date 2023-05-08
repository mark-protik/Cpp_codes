#include <iostream>
using namespace std;

void bubble_sort(int ara[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ara[j] > ara[j + 1])
            {
                int temp = ara[j];
                ara[j] = ara[j + 1];
                ara[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int ara[] = {3, 1, 4, 5, 6, 23, 1, 0};
    int size = sizeof(ara) / sizeof(ara[0]);
    bubble_sort(ara, size);
    for (int x : ara)
    {
        cout << x << " ";
    }
}