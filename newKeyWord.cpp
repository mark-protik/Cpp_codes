#include <iostream>
using namespace std;
int main()
{

    int *p = new int(4);
    cout << *p << endl;

    float *ara = new float[3];
    ara[0] = 32.232;
    ara[1] = 42;
    ara[2] = 34;
    delete[] ara;
    for (int i = 0; i < 3; i++)
    {
        cout << ara[i] << endl;
    }
    return 0;
}