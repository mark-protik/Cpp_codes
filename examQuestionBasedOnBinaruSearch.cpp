#include <iostream>
using namespace std;

int search(int ara[], int size, int key)
{
    int high = size - 1;
    int low = 0;
    int mid = 0;
    int count = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (ara[mid] == key)
            return mid;
        else if (key > ara[mid] && ara[mid + 1] > key)
            return mid + 1;

        else if (ara[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
        count++;
    }
    return -1;
}
void insertionSort(int ara[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = ara[i];
        int j = i - 1;
        while (j >= 0 && ara[j] > temp)
        {
            ara[j + 1] = ara[j];
            j--;
        }
        ara[j + 1] = temp;
    }
}
int main()
{
    int ara[] = {4, 3, 1, 8, 6};
    int size = sizeof(ara) / sizeof(ara[0]);
    insertionSort(ara, size);

    for (int x : ara)
    {
        cout << x << " ";
    }

    int key;
    cout << "\nEnter a key to find : ";
    cin >> key;
    int index = search(ara, size, key);
    if (index != -1)
        cout << "Index : " << index << "  ::  Value : " << ara[index] << endl;

    else
        cout << "Not in the array";
    return 0;
}