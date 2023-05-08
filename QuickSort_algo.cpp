#include <iostream>
using namespace std;

int partition(int ara[], int low, int high)
{
    int i = low - 1;
    int pivot = ara[high];
    int j = low;
    while (j < high)
    {
        if (ara[j] < pivot)
        {
            i++;
            int temp = ara[i];
            ara[i] = ara[j];
            ara[j] = temp;
        }
        j++;
    }
    i++;
    int temp = ara[i];
    ara[i] = pivot;
    ara[high] = temp;
    return i;
}
void quickSort(int ara[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(ara, low, high);
        quickSort(ara, low, pivot - 1);
        quickSort(ara, pivot + 1, high);
    }
}
int main()
{
    int ara[] = {5, 2, 7, 8, 1};
    int size = sizeof(ara) / sizeof(ara[0]);
    quickSort(ara, 0, size - 1);
    for (int x : ara)
        cout << x << " ";
    return 0;
}