#include <iostream>
#include <conio.h>
int main()
{
    std::string str;
    std::cout << "What's your name : ";
    // std::cin >> str;
    std::getline(std::cin, str);

    std::cout << "My name is " << str;
    getch();
}