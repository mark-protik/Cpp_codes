#include <bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++)
        if (arr[i] < arr[i - 1])
            return false;
    return true;
}

void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++)
        swap(arr[i], arr[rand() % n]);
}

void mogaSort(int arr[], int n) {
    while (!isSorted(arr, n))
        shuffle(arr, n);
}

int main() {
    int arr[] = {5, 4, 3,1,5,7,2,-2,45,6,12,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    mogaSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
