#include <iostream>
using namespace std;
class Complex
{
public:
    int real, imaginary;

    Complex()
    {
    }
    Complex(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    void getDeta()
    {
        cout << "the real part is : " << real << endl;
        cout << "the imagianry part is : " << imaginary << endl;
    }
    void setDeta(int real, int imaginary)
    {
        this->real = real;
        this->imaginary = imaginary;
    }
    void display()
    {
        cout << "the real part is : " << real << endl;
        cout << "the imagianry part is : " << imaginary << endl;
    }
};
class Number : Complex
{
public:
    Number(int real, int imaginary) : Complex(real, imaginary)
    {
        display();
    }
};
int main()
{
    //! wehen we use pointer we use " -> "
    Complex *ptr = new Complex();
    ptr->setDeta(32, 232);
    // or...
    //(*ptr).setDeta(32, 23);
    ptr->display();

    //! or...

    // Complex com(23, 23);
    // com.display();

    return 0;
}