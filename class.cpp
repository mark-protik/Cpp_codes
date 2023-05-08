#include <iostream>
#include <string>
using namespace std;

class Mark : AbstractFruit
{
    void lamda()
    {
        cout << "lamda";
    }
};
class AbstractFruit
{
    virtual void askForPromotion() = 0;
};
class Fruit : Mark
{
private:
    string name;
    string type;
    int weight;

public:
    Fruit()
    {
    }
    Fruit(string name)
    {
        this->name = name;
    }
    Fruit(string name, string type)
    {
        this->name = name;
        this->type = type;
    }
    Fruit(string name, string type, int weight)
    {
        this->name = name;
        this->type = type;
        this->weight = weight;
    }

    void display()
    {
        cout << "info :: " << endl;
        cout << name << " " << endl;
    }

    void askForPromotion()
    {
        if (weight > 34)
        {
            cout << "you may go";
        }
    }
    void setName(string name)
    {
        this->name = name;
    }
};

int main()
{
    Fruit apple = Fruit("apple", "apple", 334);
    apple.askForPromotion();
    apple.display();

    return 0;
}