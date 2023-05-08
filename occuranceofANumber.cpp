#include <iostream>
using namespace std;

int recur_search(int ara[], int size, int num)
{
    static int i = 0;
    if (i == size && ara[i] != num)
        return -1;
    else if (ara[i] == num)
        return i;
    else
    {
        i++;
        recur_search(ara, size, num);
    }
}
int main()
{
    int ara[] = {23, 35, 35, 2, 1, 3, 0};
    int num, size;
    size = sizeof(ara) / sizeof(ara[0]);
    cin >> num;
    int index = recur_search(ara, size, num);
    cout << index;

    return 0;
}