#include <iostream>
using namespace std;

class Node // creating a class instead of struct
{
public: // access modifier
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

Node *location(Node *&head, int value, Node *&tail) // for finding a particular value, returns a address
{

    Node *temp = head;
    while (temp->value != value && temp != NULL)
    {

        if (temp == tail && temp->value != value)
        {
            return NULL;
        }
        else
            temp = temp->next;
    }
    return temp;
}

Node *prev_location(Node *&head, int value, Node *&tail)
{
    Node *temp = head;
    Node *prev = temp;
    while (temp->value != value)
    {
        prev = temp;
        temp = temp->next;
    }
    return prev;
}

void insert(Node *&head, int value, Node *&tail)
{
    Node *n = new Node(value);

    if (head == NULL) // if head null we are putting value into head;
        head = n;
    else
        tail->next = n;
    tail = n; // changing the tail pointer
}

void insert_head(Node *&head, int value)
{
    Node *temp = new Node(value);

    temp->next = head;
    head = temp; // changing head pointer
}

void insert_middle_searching_by_value(Node *&head, int target, int value, Node *&tail)
{
    if (head == NULL)
        return;
    else
    {
        Node *temp = new Node(value);
        Node *loc = location(head, target, tail);

        if (loc->next != NULL && loc->value == target)
        {
            temp->next = loc->next;
            loc->next = temp;
        }
        else if (loc == tail || loc == NULL)
        {
            cout << "suggesting inrest last..." << endl;
            return;
        }
    }
}

void delete_head(Node *&head)
{

    Node *temp = head;
    if (temp == NULL)
        cout << "Head is NULL" << endl;
    head = temp->next;
    delete temp;
    temp = NULL;
}

void delete_last(Node *&head, Node *&tail)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "empty" << endl;
        tail = head;
        return;
    }
    else if (head->next == NULL)
    {
        temp = head;
        head = NULL;
        tail = head;
        delete temp;
    }
    else
    {
        temp = prev_location(head, tail->value, tail);
        tail = temp;
        // cout << tail->value << endl;
        tail->next = NULL;
        delete temp;
        temp = NULL;
    }
}

void delete_middle(Node *&head, int target, Node *&tail)
{

    if (head == NULL)
    {
        cout << "empty!" << endl;
        return;
    }
    else if (head == tail)
    {
        delete_head(head);
    }
    else if (head->value == target)
    {
        cout << "Instead of deleting middle ; Delete head or tail element" << endl;
        return;
    }
    else
    {
        Node *pre_loc = prev_location(head, target, tail);
        Node *temp;
        temp = pre_loc->next;
        pre_loc->next = temp->next;
        delete temp;
        temp = NULL;
    }
}

void display(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

void sort_ascending(Node *&head)
{
    if (head == NULL)
        return;
    else
    {
        Node *Temp = head;

        while (Temp != NULL)
        {
            Node *temp = Temp;
            Node *min_loc = temp;
            int min = temp->value;

            while (temp != NULL)
            {
                if (min > temp->value)
                {
                    min = temp->value;
                    min_loc = temp;
                }
                temp = temp->next;
            }
            min_loc->value = Temp->value;
            Temp->value = min;
            Temp = Temp->next;
        }
    }
}

void sort_descending(Node *&head)
{
    if (head == NULL)
        return;
    else
    {
        Node *Temp = head;

        while (Temp != NULL)
        {
            Node *temp = Temp;
            Node *min_loc = temp;
            int min = temp->value;

            while (temp != NULL)
            {
                if (min < temp->value)
                {
                    min = temp->value;
                    min_loc = temp;
                }
                temp = temp->next;
            }
            min_loc->value = Temp->value;
            Temp->value = min;
            Temp = Temp->next;
        }
    }
}

void remove_duplicate(Node *&head, Node *&tail)
{
    Node *current = head;
    Node *next_node = NULL;

    Node *temp = NULL;
    int flag = 0;
    while (current != NULL)
    {
        Node *prev = current;
        next_node = current->next;
        while (next_node != NULL)
        {
            flag = 0;
            if (current->value == next_node->value)
            {
                flag = 1;
                prev->next = next_node->next;
                temp = next_node;
            }
            if (flag == 0)
            {
                prev = next_node;
                next_node = next_node->next;
            }
            else
            {
                temp->next = NULL;
                free(temp);
                next_node = prev->next;
            }
        }
        tail = prev;
        // cout << tail->value << endl;
        current = current->next;
    }
}

void free_list(Node *&head, Node *&tail)
{
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *loc = NULL;

    int choise;
    int value;
    int target;

    while (1)
    {
        cout << "\n\n 0. Display \n 1. Insert \n 2. Insert_head \n 3. Insert_middle \n 4. Location \n 5. Delete_head \n 6. Delete_last \n 7. Delete_middle \n 8. Sort_ascending \n 9. Sort_descending \n 10.Remove duplicates\n";
        cout << ".........................\n ........................." << endl;
        cout << "\nchoise : ";
        cin >> choise;
        cout << endl;
        switch (choise)
        {
        case 0:
            display(head);
            break;

        case 1:
            cout << "enter value : ";
            cin >> value;
            insert(head, value, tail);
            break;

        case 2:
            cout << "enter value : ";
            cin >> value;
            insert_head(head, value);
            break;

        case 3:
            cout << "enter target : ";
            cin >> target;
            cout << "enter value : ";
            cin >> value;
            insert_middle_searching_by_value(head, target, value, tail);
            break;

        case 4:
            if (head != NULL)
            {
                cout << "enter value : ";
                cin >> value;
                loc = location(head, value, tail);
                if (loc == NULL)
                    cout << "\nNot in the list" << endl;
                else
                    cout << "Location  : " << loc << "\nLocation value : " << loc->value << endl;
            }
            else
                cout << "\nEmpty list" << endl;
            break;

        case 5:
            delete_head(head);
            break;

        case 6:
            delete_last(head, tail);
            break;

        case 7:
            cout << "enter value : ";
            cin >> value;
            delete_middle(head, value, tail);
            break;

        case 8:
            sort_ascending(head);
            break;

        case 9:
            sort_descending(head);
            break;

        case 10:
            remove_duplicate(head, tail);
            break;

        default:
            cout << "Enter given choise \n";
            break;
        }
    }
    return 0;
}