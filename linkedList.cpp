#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node()
    {
    }
    Node(int value)
    {
        this->value = value;
        next = NULL;
    }
};
void insert_middle(Node *previous, int value)
{
    //! check is the previous node is NULL
    if (previous == NULL)
    {
        cout << "previous cannot be NULL";
        return;
    }
    //! prepare a new node
    Node *newNode = new Node();
    newNode->value = value;
    //! insert new node after previous
    newNode->next = previous->next;
    previous->next = newNode;
}
void insert_last(Node **head, int value)
{
    //! prepare a new Node
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = NULL;
    //! if list is empty , new node will be head node
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    //! find the last node
    Node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }

    //! insert new node after last node(at the end)
    last->next = newNode;
}
void insert_first(Node **head, int value)
{
    //! prepare a new node
    Node *newNode = new Node();
    newNode->value = value;

    //! put it in front of current head
    newNode->next = *head;

    //! move head of the list to point to the New Node
    *head = newNode;
}
void print_list(Node **head)
{
    Node *temp = *head;
    if (temp->next == NULL && temp->value == NULL)
    {
        cout << "NULL" << endl;
    }
    else
    {
        while (temp->value != NULL)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}
void insert_first_element(Node **head, int value)
{

    Node *temp = *head;
    if (temp->next == NULL)
    {
        Node *newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        insert_first(head, value);
    }
}
void insert_middle_by_value(Node **head, int target, int value)
{
    Node *temp = *head;
    while (temp->value != target)
    {
        temp = temp->next;
    }
    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = temp->next;
    temp->next = newNode;
}
int main()
{

    Node *head = new Node();
    head->value = NULL;
    head->next = NULL;

    insert_first_element(&head, 1);

    print_list(&head);
}
