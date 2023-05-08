#include <iostream>
using namespace std;
bool palindromeCheck(int num)
{
    int mod = 0, temp = 0, div = 0, num2 = num;

    if (num < 10)
        return false;
    else
    {
        while (num != 0)
        {
            mod = num % 10;
            cout << "\nmod value = " << mod << endl;
            div = num / 10;
            cout << "div value = " << div << endl;
            temp = temp * 10 + mod;
            cout << "temp value = " << temp << endl;
            num = div;
            cout << "\n\n";
        }

        if (num2 == temp)
            return true;
        else
            return false;
    }
}
int main()
{
    int num;
    cout << "Enter num : ";
    cin >> num;
    if (palindromeCheck(num))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}