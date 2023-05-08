#include <iostream>

int main()
{
    std::string str;
    std::cout << "what is your name : ";
    std::getline(std::cin, str);

    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == 'a' || str.at(i) == 'e' || str.at(i) == 'i' || str.at(i) == 'o' || str.at(i) == 'u')
            str.at(i) = 'h';
    }
    std::cout << str;
}