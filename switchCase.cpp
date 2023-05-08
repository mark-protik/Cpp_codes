#include <iostream>
int main()
{
    int num;
    std::cin >> num;
    switch (num)
    {
    case 1:
        std::cout << "one ";
        break;
    case 2:
        std::cout << "two ";
        break;
    case 3:
        std::cout << "three ";
        break;
    default:
        std::cout << "no";
    }
}