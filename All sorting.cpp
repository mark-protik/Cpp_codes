#include <iostream>
using namespace std;
void selectionSort(int ara[], int size);
void bubbleSort(int ara[], int size);
void insertionSort(int ara[], int size);

int main()
{
    int ara[] = {8, 7, 1, 5, 4, 9, 6, 2, 3};
    int size = sizeof(ara) / sizeof(ara[0]);
    // selectionSort(ara, size);
    // bubbleSort(ara, size);
    insertionSort(ara, size);
    for (int x : ara)
    {
        cout << x << ' ';
    }
}
void selectionSort(int ara[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (ara[min] > ara[j])
            {
                min = j;
            }
        }
        int temp;
        temp = ara[i];
        ara[i] = ara[min];
        ara[min] = temp;
    }
}
void bubbleSort(int ara[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ara[j + 1] < ara[j])
            {
                int temp;
                temp = ara[j + 1];
                ara[j + 1] = ara[j];
                ara[j] = temp;
            }
        }
    }
}
void insertionSort(int ara[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = ara[i];
        int j = i - 1;
        while (j >= 0 && ara[j] > temp) //{7, 8, 1, 5, 4, 9, 6, 2, 3}
        {
            ara[j + 1] = ara[j];
            j--;
        }
        ara[j + 1] = temp;
    }
}