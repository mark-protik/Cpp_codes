#include <iostream>
#include <string>
using namespace std;

void recur(string str, int i)
{

    if (str[i] == '\0')
        return;
    recur(str, i + 1);
    cout << str[i];
}
int main()
{

    string str;
    getline(cin, str);
    int i = 0;
    recur(str, i);
    return 0;
}