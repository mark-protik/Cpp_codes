#include <iostream>
int change(int ara[], int size);
int main()
{
    int ara[5];

    int size = sizeof(ara) / sizeof(ara[0]);

    for (int i = 0; i < size; i++)
    {
        std::cin >> ara[i];
    }

    int sum = change(ara, size);
    std::cout << "the sum is : " << sum << '\n';

    for (int x : ara)
    {
        std::cout << x << '\t';
    }
}
int change(int ara[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        std::cout << ara[i] << '\n';
        total += ara[i];
    }
    return total;
}