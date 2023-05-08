#include <iostream>
using namespace std;

void permutation(string str, string ans)
{

    cout << "recieving value >>>>>>>>>>>>>>> " << str << " " << ans << endl;
    if (str.length() == 0)
    {
        cout << "retruning ans >>>>>>>>>>>>>> " << endl;
        cout << ans << "\n\n";
        return;
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        string rest_string = str.substr(0, i) + str.substr(i + 1);
        cout << "before sending >>>>>>>>>>>>> " << endl;
        cout << "rest String              : " << rest_string << endl;
        cout << "targeted Char            : " << ch << endl;
        cout << "value sending : " << rest_string << " " << ans + ch << endl;
        cout << "\n";
        permutation(rest_string, ans + ch);
        cout << "after returning >>>>>>>>>>>>>" << endl;
        cout << "remaning string    : " << str << endl;
        // cout << "returning ans : " << ans << endl;
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