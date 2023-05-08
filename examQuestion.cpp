#include <iostream>
#include <string.h>

int top = -1;
char Stack[4] = {'\0'};

void push(char x)
{
    Stack[++top] = x;
    return;
}
char pop(void)
{
    return Stack[top--];
}
int main()
{
    char Str1[4] = {'\0'};
    char Str2[4] = {'\0'};

    int i;
    strcpy(Str1, "CSE");
    for (int i = 0; i < 3; i++)
    {
        push(Str1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        Str2[i] = pop();
    }
    printf("%s", Str2);
    return 0;
}
