#include <iostream>
using namespace std;

int count = 0;
void permutation(string str, string ans)
{
    if (str.length() == 0)
    {
        cout << ans << endl;
        count++;
        cout << count << endl;
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string rest_string = str.substr(0, i) + str.substr(i + 1);
        permutation(rest_string, ans + ch);
    }
}
int main()
{
    string str;
    getline(cin, str);
    cout << endl
         << endl;
    permutation(str, "");

    return 0;
}