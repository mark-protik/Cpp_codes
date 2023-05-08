#include <iostream>
using namespace std;

int partition(int ara[], int low, int high)
{
    int pivot = ara[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (ara[j] < pivot)
        {
            i++;
            int temp = ara[i];
            ara[i] = ara[j];
            ara[j] = temp;
        }
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
        cout << ara[pivot] << endl;
        quickSort(ara, low, pivot - 1);
        quickSort(ara, pivot + 1, high);
    }
}
int main()
{
    int ara[] = {3, 6, 8, 5, 2};
    int size = sizeof(ara) / sizeof(ara[0]);
    quickSort(ara, 0, size - 1);

    for (int x : ara)
    {
        cout << x << " ";
    }
    return 0;
}