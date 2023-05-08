#include <iostream>
using namespace std;
int recurSum(int n)
{
    int sum = 0;
    if (n == 10)
        return 10;

    sum = recurSum(n + 1);
    cout << n <<endl;
    return n + sum;
}
int main()
{
    int num;
    cin >> num;
    int sum = recurSum(num);
    cout << sum;
}