#include <iostream>
// using std::cin;

namespace first
{
    int x = 1;
}
namespace second
{
    double x = 2.54;
}

int main()
{
    using namespace std;
    
    cout << "hello!" << std::endl;

    int num;
    cin >> num;

    cout << second::x << endl;
    
    cout << first::x << endl;


    return 0;
}
