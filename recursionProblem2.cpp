#include <iostream>
using namespace std;
int recur(int num, int power, int p)
{
    if (p == power)
        return num;

    return num * recur(num, power, p + 1);
}
int main()
{
    int value = 0, num, power;
    cin >> num >> power;
    if (power == 0)
        cout << 1;
    else
    {
        int p = 1;
        value = recur(num, power, p);
        cout << value;
    }
    return 0;
}