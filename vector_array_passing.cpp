#include <iostream>
#include <vector>

using namespace std;

void function(vector<int> ara[], int size)
{
    for (auto i = 0; i < size; i++)
    {
        for (auto j = 0; j < ara[i].size(); j++)
        {
            ara[i][j] = 24;
        }
    }
}
int main(void)
{
    vector<int> ara[3] = {{1, 2, 3}, {12, 2, 4}, {23, 3, 4, 35, 45, 45, 34}};

    int size = ara->size(); //! working with pointer , because we have used "->"
    function(ara, size);

    for (auto i = 0; i < ara->size(); i++)
    {
        for (auto x : ara[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}