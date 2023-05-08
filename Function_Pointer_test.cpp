#include <iostream>
#include <vector>
using namespace std;

bool Ascending_compare(int a, int b)
{
    return a > b;
}
bool Descending_compare(int a, int b)
{
    return a < b;
}

void auto_sort(vector<int> &vec, bool (*funcPtr)(int, int)) // receiveing any function
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if (funcPtr(vec[j], vec[j + 1]))
            {
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

int main()
{
    vector<int> vec = {6, 0, 12, 2, 3, -5};

    cout << "\nbefore sorting : " << endl;
    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";

    //! main use of function pointer

    bool (*comparePtr)(int, int) = Descending_compare;
    auto_sort(vec, comparePtr);

    //!............................................

    cout << "\nafter sorting : " << endl;
    for (int x : vec)
        cout << x << " ";
}