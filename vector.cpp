#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> ara;
    ara.push_back(10);

    for (int i = 0; i < 10; i++)
        ara.push_back(i * 10);

    ara.assign(10, 69); //! fill all the first 10 value with 69;

    // cout << *ara.begin();

    vector<int> ara1{1, 2, 3, 4, 5};
    vector<int> ara2{0, 0, 0};

    // ara1.swap(ara2); //! swaping a vector with another ... size doesn't matter LMAO!

    ara1.pop_back(); //! POping back element
    ara1.pop_back();

    ara1.insert(ara1.begin() + 1, 12); //! insert is only possible using iterator
    ara1.insert(ara1.end(), 45);

    ara1.insert(ara1.begin() + 2, 4, 100); //! another use of insert function

    ara1.erase(ara1.begin());

    // for (auto it = ara1.begin(); it !=ara1.end(); it++) //? printing using iterator
    //     cout << *it << endl;

    // for (int x : ara1)
    //     cout << x << endl;

    for (int i = 0; i < ara1.size(); i++)
    {
        cout << ara1[i] << " ";
    }

    return 0;
}