#include <iostream>
using namespace std;
void recur(int num)
{
    if (num == 11)
        return;
    cout << num;
    recur(num + 1);
}
int main()
{
    int num;
    cin >> num;
    recur(num);
    return 0;
}