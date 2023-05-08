#include <iostream>
using namespace std;
void bubbleSort(int ara[], int size);
int index(int ara[], int size, int key);
int binarySearch(int ara[], int size, int key);
int main()
{
    int ara[] = {2, 4, 2, 0, 9, -1, 2};
    int size = sizeof(ara) / sizeof(ara[0]);
    bubbleSort(ara, size);
    for (int x : ara)
        cout << x << " ";
    cout << "\nEnter any number : ";
    int key;
    cin >> key;
    // int targetIndex = index(ara, size, key);
    int targetIndex = binarySearch(ara, size, key);
    if (targetIndex != -1)
        cout << "The index is : " << targetIndex << endl;
    else
        cout << "Not is the array";
    return 0;
}
void bubbleSort(int ara[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ara[j + 1] < ara[j])
            {
                int temp = ara[j + 1];
                ara[j + 1] = ara[j];
                ara[j] = temp;
            }
        }
    }
}
int index(int ara[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (key == ara[i])
            return i;
    }
    return -1;
}
int binarySearch(int ara[], int size, int key)
{
    int low = 0;
    int high = size - 1;
    int mid = 0;
    while (true)
    {
        mid = low + (high - low) / 2;
        if (ara[mid] == key)
            return mid;
        else if (ara[mid] > key)
            high = mid - 1;
        else if (ara[mid] < key)
            low = mid + 1;
        if (low > high)
            return -1;
    }
}