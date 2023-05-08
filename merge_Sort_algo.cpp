#include <iostream>
using namespace std;

void merge(int ara[], int low, int mid, int high)
{
    int size_ara1 = mid - low + 1;
    int size_ara2 = high - mid;

    int ara1[size_ara1];
    int ara2[size_ara2];
    for (int i = 0; i < size_ara1; i++)
    {
        ara1[i] = ara[low + i];
    }
    for (int i = 0; i < size_ara2; i++)
    {
        ara2[i] = ara[mid + 1 + i];
    }

    int i = 0, j = 0, k = low;

    while (i < size_ara1 && j < size_ara2)
    {
        if (ara1[i] < ara2[j])
        {
            ara[k++] = ara1[i++];
        }
        else
        {
            ara[k++] = ara2[j++];
        }
    }
    while (i < size_ara1)
    {
        ara[k++] = ara1[i++];
    }
    while (j < size_ara2)
    {
        ara[k++] = ara2[j++];
    }
}
void divide(int ara[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        divide(ara, low, mid);
        divide(ara, mid + 1, high);
        merge(ara, low, mid, high);
    }
}
int main()
{
    int ara[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(ara) / sizeof(ara[0]);
    divide(ara, 0, size - 1);

    for (int x : ara)
        cout << x << endl;
    return 0;
}