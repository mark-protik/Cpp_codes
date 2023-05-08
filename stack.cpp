#include <iostream>
using namespace std;

#define SUCCESS_VALUE 99999
#define UNSUCCESS_VALUE -99999

class Stack
{
    int value;
    Stack *next;
    Stack *head = NULL;
    Stack *tail = NULL;

public:
    Stack() {}
    Stack(int value)
    {
        this->value = value;
        next = NULL;
    }

    Stack *prev_loc(int value)
    {
        Stack *temp = head;
        Stack *prev = NULL;
        while (temp->value != value)
        {
            prev = temp;
            temp = temp->next;
        }
        return prev;
    }

    void push(int value)
    {
        Stack *temp = new Stack(value);
        if (head == NULL && tail == NULL)
            head = temp;
        else
            tail->next = temp;
        tail = temp;
    }
    int pop()
    {
        if (head == NULL)
        {
            cout << "Nothing to pop!" << endl;
            return UNSUCCESS_VALUE;
        }
        else if (head->next == NULL)
        {
            int last = head->value;
            head = tail = NULL;
            return last;
        }
        else
        {
            Stack *temp = prev_loc(tail->value);
            int last_data = tail->value;
            temp->next = NULL;
            tail = temp;

            delete temp;
            temp = NULL;
            return last_data;
        }
    }
    int is_empty()
    {
        if (head == NULL && tail == NULL)
            return 1;
        else
            return 0;
    }
    int peek()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "empty!" << endl;
            return UNSUCCESS_VALUE;
        }
        else if (head->next == NULL)
        {
            int x = head->value;
            head = tail = NULL;
            return x;
        }
        else
            return tail->value;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "empty!" << endl;
            exit(0);
        }
        else
        {
            Stack *temp = head;
            while (temp != NULL)
            {
                if (temp->next == NULL)
                    cout << temp->value;
                else
                    cout << temp->value << " -> ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
    int length()
    {
        int count = 0;
        Stack *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
    void sort()
    {
        Stack st;

        int size = length();
        int i = 0;
        while (i < size)
        {
            Stack *temp = head;
            int max = peek();

            Stack *max_loc = tail;
            while (temp != NULL)
            {
                if (max < temp->value)
                {
                    max = temp->value;
                    max_loc = temp;
                }

                temp = temp->next;
            }
            if (head == tail)
            {
                st.push(max);
                head = tail = NULL;
            }
            else if (max_loc == head)
            {
                st.push(max);
                head = head->next;
            }
            else if (max_loc == tail)
            {
                st.push(max);
                Stack *t = prev_loc(max);
                tail = t;
                tail->next = NULL;
            }
            else
            {
                st.push(max);
                Stack *t = prev_loc(max);
                t->next = t->next->next;
            }
            max_loc = NULL;
            delete max_loc;
            i++;
        }
        for (int i = 0; i < size; i++)
            push(st.pop());
        display();
    }
};

int main()
{
    Stack a;

    int choice;
    while (1)
    {
        cout << "\n 1. push\n 2. pop\n 3. peek\n 4. display\n 5. is_empty\n 6. sort\n 7. exit\n";
        cout << "\nenter choise : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "enter value : ";
            int value;
            cin >> value;
            a.push(value);
            break;
        }

        case 2:
        {
            int x = a.pop();
            if (x == UNSUCCESS_VALUE)
            {
            }
            else
                cout << "popped element : " << x << endl;
            break;
        }

        case 3:
        {
            int y = a.peek();
            if (y == UNSUCCESS_VALUE)
            {
            }
            else
                cout << "last element : " << y << endl;
            break;
        }
        case 4:
        {
            a.display();
            break;
        }
        case 5:
        {
            int z = a.is_empty();
            if (z == 1)
                cout << "empty!\n";
            else
                cout << "not empty!\n";
            break;
        }
        case 6:
        {
            a.sort();
            break;
        }
        case 7:
        {
            cout << "you have successfully terminated!\n";
            exit(0);
        }
        default:
            cout << "invalid choise!\n";
        }
    }
}
