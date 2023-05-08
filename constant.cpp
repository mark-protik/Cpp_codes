#include <iostream>
using namespace std;

#define MAX 10;

int main()
{
    const double PI = 3.14159;
    const int LIGHT_SPEED = 299792458;
    const int HEIGHT = 1080;
    const int WIDTH = 1920;

    double rad;
    cout << "Enter radious : ";
    cin >> rad;


    cout << "The area is " << PI * rad * rad;
    return 0;
}