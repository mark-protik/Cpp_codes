#include <stdio.h>
int main()
{
    int num, div, rem, count = 1;
    printf("Enter any number : ");
    scanf("%d", &num);
    int tempNum = num;
    int last_dig = num % 10;

    while (num > 10)
    {
        rem = num % 10;
        div = num / 10;
        num = div;
        count *= 10;
        printf("%d\n",num);
    }
    int first_dig = num;
    int middleNum = tempNum % count;
    int tempNewNum = middleNum + last_dig * count;
    int newNum = tempNewNum - last_dig + first_dig;

    printf("swaped number : %d", newNum);
}
