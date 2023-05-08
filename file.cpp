#include <iostream>
#include <string>
#include <fstream>
#include <math.h>

int primeCheck(int num);

using namespace std;

int main()
{
    fstream file;
    file.open("mark.txt", ios::out);
    if (file.is_open())
    {
        for (int i = 0; i < 5; i++)
        {
            string str;
            getline(cin, str);
            file << str << endl;
        }
        file.close();
    }
    else
        cout << "file not find!" << endl;

    int sum = 0;
    file.open("mark.txt", ios::in);
    if (file.is_open())
    {

        string str;
        while (getline(file, str))
        {
            if (primeCheck(stoi(str)))
                sum += stoi(str);

            cout << str << endl;
        }
        file.close();
    }
    else
        cout << "file not found!" << endl;

    cout << "the sum is : " << sum << endl;
}
int primeCheck(int num)
{
    if (num == 1)
        return 0;
    bool flag = true;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            flag = false;
            break;
            return 0;
        }
        else
            flag = true;
    }
    if (flag == true)
        return 1;
    else
        return 0;
}