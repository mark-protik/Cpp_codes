#include <iostream>
using namespace std;

class Doubly_Node // creating a class instead of struct
{
public: // access modifier
    int value;
    Doubly_Node *next;
    Doubly_Node *prev;

    Doubly_Node(int value)
    {
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};
using Node = Doubly_Node;

Node *head = NULL;
Node *tail = NULL;

void insertFirst(int value)
{
    Node *temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
        tail = head;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;

        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        tail = temp;
    }

    // cout << "head  " << head->value << endl;
    // cout << "tail  " << tail->value << endl;
}

void insert(int value)
{
    Node *temp = new Node(value);
    if (head == NULL)
    {
        insertFirst(value);
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

Node *search(int elem)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->value == elem)
        {
            return temp;
            break;
        }
        temp = temp->next;
    }
    return NULL;
}

void insertItem(int elem, int num)
{
    // Insert item after a particular number

    Node *temp = new Node(num);
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    else
    {
        Node *loc = search(elem);
        if (loc == NULL)
        {
            cout << "Not in the list" << endl;
            exit(1);
        }
        else
        {
            if (loc->next == NULL)
            {
                insert(num);
            }
            else
            {
                Node *nextItem = loc->next;
                temp->next = nextItem;
                nextItem->prev = temp;
                loc->next = temp;
                temp->prev = loc;
            }
        }
    }
}

void printRev(Node *temp)
{
    // printing reverse

    if (temp == NULL)
        return;
    printRev(temp->next);
    cout << temp->value << "->";
}

void print()
{
    // general order

    Node *temp = head;
    if (temp == NULL)
    {
        cout << "Empty list!" << endl;
        return;
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->value << "->";
            temp = temp->next;
        }
    }
    cout << "\nhead  " << head->value << endl;
    cout << "tail  " << tail->value << endl;
}
void deleteLast()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    else if (head == tail)
    {
        head = tail = NULL;
    }
    else
    {
        Node *Prev = tail->prev;
        Node *temp = tail;
        Prev->next = NULL;
        tail = Prev;
        delete temp;
    }
}
int main(void)
{
    insertFirst(10);
    insert(20);
    insert(30);
    insert(40);
    insertItem(10, 100);
    insertItem(100, 11);
    insertItem(40, 100);
    deleteLast();
    print();
    printRev(head);
    return 0;
}
