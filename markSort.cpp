#include <iostream>
using namespace std;
void divide(int ara[], int low, int high);
void merge(int ara[], int low, int mid, int high);
int main()
{
    int size;
    cout << "enter the size of array : " << endl;
    cin >> size;

    int ara[size];
    for (int i = 0; i < size; i++)
    {
        cout << "ara[" << i << "] = ";
        cin >> ara[i];
    }
    divide(ara, 0, size - 1);
    for (int x : ara)
        cout << x << " ";
    return 0;
}
void divide(int ara[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        divide(ara, low, mid);
        divide(ara, mid + 1, high);
        merge(ara, low, mid, high);
    }
}
void merge(int ara[], int low, int mid, int high)
{
    int size_ara1 = mid - low + 1;
    int size_ara2 = high - mid;

    int ara1[size_ara1];
    int ara2[size_ara2];

    for (int i = 0; i < size_ara1; i++)
        ara1[i] = ara[low + i];
    for (int i = 0; i < size_ara2; i++)
        ara2[i] = ara[mid + i + 1];

    int i = 0;
    int j = 0;
    int k = low;

    while (i < size_ara1 && j < size_ara2)
    {
        if (ara1[i] < ara2[j])
            ara[k++] = ara1[i++];
        else
            ara[k++] = ara2[j++];
    }
    while (i < size_ara1)
        ara[k++] = ara1[i++];
    while (j < size_ara2)
        ara[k++] = ara2[j++];
}