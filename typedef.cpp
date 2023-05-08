#include <iostream>
// typedef std::string str_t;
// typedef int number_t;
/*we can easily replace typedef by using "using" keyword.*/

namespace mark
{
    int x = 120;
}
using str_t = std::string;
using number_t = int;

int main()
{

    str_t str = "Bro";
    std::cout << str << std::endl;

    number_t num = 45;
    std::cout << num << std::endl;
    std::cout << mark::x;

    return 0;
}
