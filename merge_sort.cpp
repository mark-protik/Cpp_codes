//! divide and concure
#include <iostream>
using namespace std;

void merge(int ara[], int low, int mid, int high)
{
    int ara1_size = mid - low + 1;
    int ara2_size = high - mid;

    int ara1[ara1_size];
    int ara2[ara2_size];

    for (int i = 0; i < ara1_size; i++)
    {
        ara1[i] = ara[low + i];
    }
    for (int i = 0; i < ara2_size; i++)
    {
        ara2[i] = ara[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = low;

    while (i < ara1_size && j < ara2_size)
    {
        if (ara1[i] < ara2[j])
        {
            ara[k] = ara1[i];
            k++;
            i++;
        }
        else
        {
            ara[k] = ara2[j];
            k++;
            j++;
        }
    }
    while (i < ara1_size)
    {
        ara[k] = ara1[i];
        k++;
        i++;
    }
    while (j < ara2_size)
    {
        ara[k] = ara2[j];
        k++;
        j++;
    }
}
void mergeSort(int ara[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        cout << "enter" << endl;
        mergeSort(ara, low, mid);
        cout << "return" << endl;
        mergeSort(ara, mid + 1, high);

        merge(ara, low, mid, high);
    }
}
int main()
{
    int ara[] = {5, 4, 3, 2, 1};
    mergeSort(ara, 0, 4);
    for (int x : ara)
    {
        cout << x << " ";
    }
    return 0;
}