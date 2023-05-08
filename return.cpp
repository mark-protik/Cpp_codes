#include <iostream>
int sum(int x, int y);
void name(std::string str);

typedef std::string string_t;

int main()
{
    int num1, num2;
    string_t str = "Mark ";

    std::cout << str << std::endl;

    std::cout << "Enter number 1 : ";
    std::cin >> num1;
    std::cout << "Enter number 2 : ";
    std::cin >> num2;

    int result = sum(num1, num2);
    std::cout << "The sum is : " << result;

    name("\nmark protik mondol");
}
int sum(int x, int y)
{
    return x + y;
}
void name(std::string str)
{
    std::cout << str + " Namaste ";
}