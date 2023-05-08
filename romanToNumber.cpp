#include <iostream>
int main()
{
    std::string romanValue;
    
    int sum = 0, count = 0, flag = 0;

    int ara[7] = {0};

    std::cout << "Enter a Roman value : ";
    getline(std::cin, romanValue);
    for (int i = 0; i < romanValue.length(); i++)
    {
        romanValue[i] = toupper(romanValue[i]);
    }

    for (int i = 0; i < romanValue.length(); i++)
    {
        if (romanValue[i] == 'I')
        {
            ara[0] = ara[0] + 1;
            if (romanValue[i + 1] == 'V' || romanValue[i + 1] == 'X' ||
                romanValue[i + 1] == 'C' || romanValue[i + 1] == 'L' || romanValue[i + 1] == 'M')
            {
            }
            else
            {
                sum += 1;
            }
        }
        else if (romanValue[i] == 'V')
        {
            ara[1]++;
            if (i != 0 && romanValue[i - 1] == 'I')
            {
                sum += 4;
            }
            else if (romanValue[i + 1] == 'X' || romanValue[i + 1] == 'C' ||
                     romanValue[i + 1] == 'L' || romanValue[i + 1] == 'M')
            {
            }
            else
            {
                sum += 5;
            }
        }
        else if (romanValue[i] == 'X')
        {
            ara[2]++;
            if (i != 0 && romanValue[i - 1] == 'I')
            {
                sum += 9;
            }
            else if (romanValue[i + 1] == 'C' ||
                     romanValue[i + 1] == 'L' || romanValue[i + 1] == 'M')
            {
            }
            else
            {
                sum += 10;
            }
        }
        else if (romanValue[i] == 'L')
        {
            ara[3]++;
            if (i != 0 && romanValue[i - 1] == 'I')
            {
                sum += 49;
            }
            else if (romanValue[i + 1] == 'C' ||
                     romanValue[i + 1] == 'M')
            {
            }
            else if (i != 0 && romanValue[i - 1] == 'X')
            {
                sum += 40;
            }
            else
            {
                sum += 50;
            }
        }
        else if (romanValue[i] == 'C')
        {
            ara[4]++;
            if (i != 0 && romanValue[i - 1] == 'I')
            {
                sum += 99;
            }
            else if (romanValue[i + 1] == 'M')
            {
            }
            else
            {
                sum += 100;
            }
        }
        else if (romanValue[i] == 'D')
        {
            ara[5]++;
            if (i != 0 && romanValue[i - 1] == 'I')
            {
                sum += 499;
            }
            else
            {
                sum += 500;
            }
        }
        else if (romanValue[i] == 'M')
        {
            ara[6]++;
            if (i != 0 && romanValue[i - 1] == 'I')
            {
                sum += 999;
            }
            else
            {
                sum += 1000;
            }
        }

        if (ara[0] > 3)
        {
            flag = 1;
            break;
        }
        else if (ara[1] > 1)
        {
            flag = 1;
            break;
        }
        else if (ara[2] > 4)
        {
            flag = 1;
            break;
        }
        else if (ara[3] > 1)
        {
            flag = 1;
            break;
        }
        else if (ara[4] > 4)
        {
            flag = 1;
            break;
        }
        else if (ara[5] > 1)
        {
            flag = 1;
            break;
        }
        else if (ara[6] > 3)
        {
            flag = 1;
            break;
        }
    }
    std::cout << "\nRoman value is : " << sum << std::endl;
}