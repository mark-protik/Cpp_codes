#include <iostream>
using namespace std;
bool recur(int ara[], int size)
{
    static int i = 0;
    if (ara[i] <= ara[i + 1])
    {
        i++;

        if (i + 1 == size)
        {
            return true;
        }
        recur(ara, size);
    }
    else
        return false;
}
int main()
{
    int ara[] = {0, 1, 2, 3, 4, 5, 5};
    int size = sizeof(ara) / sizeof(ara[0]);
    bool value = recur(ara, size);
    if (value == true)
        cout << "sorted";
    else
        cout << "unsorted";
    return 0;
}