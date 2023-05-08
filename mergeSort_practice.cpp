#include <iostream>
using namespace std;

void merge(int ara[], int low, int mid, int high)
{
    int size1 = mid - low + 1;
    int size2 = high - mid;

    int ara1[size1];
    int ara2[size2];

    for (int i = 0; i < size1; i++)
    {
        ara1[i] = ara[low + i];
    }
    for (int j = 0; j < size2; j++)
    {
        ara2[j] = ara[mid + 1 + j];
    }

    int j = 0, k = 0, l = low;
    while (j < size1 && k < size2)
    {
        if (ara1[j] < ara2[k])
        {
            ara[l] = ara1[j];
            j++;
        }
        else
        {
            ara[l] = ara2[k];
            k++;
        }
        l++;
    }
    while (j < size1)
    {
        ara[l] = ara1[j];
        j++;
        l++;
    }
    while (k < size2)
    {
        ara[l] = ara2[k];
        k++;
        l++;
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
    int size;
    int ara[] = {2, 4, 1, 3, 9, 45, -89, 6, 56, 8, 0};
    size = sizeof(ara) / sizeof(ara[0]);
    divide(ara, 0, size - 1);
    for (int x : ara)
    {
        cout << x << endl;
    }
}