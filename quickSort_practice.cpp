#include <iostream>
using namespace std;

int pivot(int ara[], int low, int high)
{
    int pi = ara[high];
    int j = low - 1;
    for (int i = low; i < high; i++)
    {
        if (ara[i] < pi)
        {
            j++;
            int temp = ara[i];
            ara[i] = ara[j];
            ara[j] = temp;
        }
    }
    j++;
    int temp = ara[j];
    ara[high] = temp;
    ara[j] = pi;
    return j;
}
void quicksort(int ara[], int low, int high)
{
    if (low < high)
    {
        int pind = pivot(ara, low, high);
        quicksort(ara, low, pind-1);
        quicksort(ara, pind + 1, high);
    }
}
int main()
{
    int ara[] = {9, 3, 4, 1, 5, 6, 1, 0};
    int size = sizeof(ara) / sizeof(ara[0]);
    quicksort(ara, 0, size - 1);
    for (int x : ara)
    {
        cout << x << endl;
    }
}