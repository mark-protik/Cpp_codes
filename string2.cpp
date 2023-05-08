#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    // string name;
    // string last_name = "mondol";

    // //! how to input string
    // getline(cin, name);

    // //! append a string with another string
    // name.append(last_name);

    // //! add two string
    // name = name + last_name;

    // cout << name << endl;

    // //! using iterator...
    // for (string::iterator i = name.begin(); i <= name.end(); i++)
    //     cout << *i;

    // cout << endl;

    // //! using normal i
    // for (int i = 0; name[i] != '\0'; i++)
    //     cout << name[i];

    // //! clear a string
    // name.clear();

    /*
//    ! if two string are equal it will return 0;
//    ! else if the first string is bigger then seconf string it will return x>0
//    ! else it will return x<0;
//     */
    //     string str, str2;
    //     str = "abcdfd";
    //     str2 = "abc";
    //     cout << str.compare(str2);

    // //! erase
    // string strr = "mark_protik";
    // strr.erase(5); //! from the index to erase to the last
    // cout << strr;

    // //! erase
    // string first_string = "mark_Protik";
    // first_string.erase(4, 4); //! from the index and the amount of character to erase
    // cout << first_string;

    // //! finding string into a string
    // string str_name = "mark protik";
    // cout << str_name.find("ark "); //! if the string has found then it will return the index where the string has begun

    // //! insert a string into another string
    // string strin_g = "markprotik";
    // strin_g.insert(2, "MondoL "); //! parameter ( index to start , string);
    // cout << strin_g;

    // //! getting substring
    // string main_string = "mark_protik_mondol";
    // string sub_string = main_string.substr(2, 4); //! parameter( starting index , length);
    // cout << sub_string;

    // //! getting substring
    // string main_string = "mark_protik_mondol";
    // string sub_string = main_string.substr(2); //! parameter( starting index );
    // cout << sub_string;

    // //! string to integer
    // string number_string = "12323";
    // int num = stoi(number_string); //! stoi = string to integer
    // cout << num;

    // //! integer to string
    // int numb = 34;
    // string number = to_string(numb);
    // cout << number;

    // //! sorting a string
    // string s_tring = "abcd  er";
    // sort(s_tring.begin(), s_tring.end()); //! to use it we need a header file called "algorithm";
    // cout << s_tring;

    // string str;
    // getline(cin, str); // !take a full string with spaces
    // cout << str << endl;

    // string str;
    // cin >> str;
    // cout << str << endl; //! if we get any space it will not count after the space

    // char str[100];
    // cin >> str;
    // cout << str << endl;

    //! to upper to lower

    // string str;
    // getline(cin, str);

    // cout << (char)tolower(str[0]) << endl;//!tolower return ascii value of that number, so we have to typecast it

    // //! in cpp we have to manually do toupper or tolower
    // char str[100];
    // cin >> str;
    // for (int i = 0; str[i] != '\0'; i++)
    //     str[i] = toupper(str[i]);

    // cout << str << endl;

    //! string
    // string str;
    // getline(cin, str);
    // for (int i = 0; str[i] != '\0'; i++)
    //     str[i] = toupper(str[i]);

    // cout << str;

    // //! string reverse
    // string str;
    // cin >> str;
    // string str3;
    // for (int i = str.length() - 1; i > -1; i--)
    // {
    //     char x = str[i];
    //     str3 += x;
    // }
    // cout << str3;

    return 0;
}