#include <iostream>
void change(int ara[]);
int main()
{
    int ara[5];

    int size = sizeof(ara) / sizeof(ara[0]);

    for (int i = 0; i < size; i++)
    {
        std::cin >> ara[i];
    }

    change(ara);

    for (int x : ara)
    {
        std::cout << x << '\t';
    }
}
void change(int ara[])
{
    ara[0] = 69;
    ara[1] = 420;
}