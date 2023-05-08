#include <iostream>
using namespace std;
int main()
{
    int x = 69;
    int *pX = nullptr; // *pX=NULL; //*pX=0;
    pX = &x;
    cout << *pX;
}