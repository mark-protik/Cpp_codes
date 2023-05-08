#include <iostream>
using namespace std;
void swap(string str, string str2);
void pointerSwap(string *str, string *str2);
int main()
{
    string str = "mark";
    string str2 = "mondol";
    swap(str, str2);
    cout << str << "\t";
    cout << str2 << "\n";

    pointerSwap(&str, &str2);
    cout << str << "\t";
    cout << str2 << "\n";
}
void swap(string str, string str2)
{
    string temp;
    temp = str;
    str = str2;
    str2 = temp;
}
void pointerSwap(string *str, string *str2)
{
    string temp;
    temp = *str;
    *str = *str2;
    *str2 = temp;
}