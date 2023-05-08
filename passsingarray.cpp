#include <iostream>
void change(int ara[]);
int main()
{
    int ara[5];

    int size = sizeof(ara) / sizeof(ara[0]);

    std::cout << size << '\n';

    change(ara);
}
void change(int ara[]) // recieving a pointer
{
    int size = sizeof(ara) / sizeof(ara[0]);

    std::cout << size;
}