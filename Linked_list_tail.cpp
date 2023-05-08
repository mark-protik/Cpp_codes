#include <stdio.h>
#include <iostream>
using namespace std;

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

class ListNode
{

public:
    int item;
    ListNode *next;
};

class LinkedListWithTail
{

    ListNode *head;
    ListNode *tail; /*EXTRA*/
    int length;

public:
    LinkedListWithTail()
    {
        head = NULL; // initially set to NULL
        length = 0;
    }

    int getLength() const
    {
        return length;
    }

    int insertItem(int item)
    {
        // insert at the beginning

        ListNode *newNode = new ListNode();
        newNode->item = item;
        newNode->next = head; // point to previous first node

        if (head == NULL)
        {
            head = newNode; /*IMPORTANT - only for the first item of the list*/
            tail = head;
        }
        else
        {
            head = newNode; // set list to point to newnode as this is now the first node
            ListNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            tail = temp;
        }
        cout << "tail  " << tail->item << endl;
        cout << "head  " << head->item << endl;

        length++;
        return SUCCESS_VALUE;
    }

    int deleteItem(int item)
    {
        ListNode *temp;
        ListNode *previous = NULL;

        temp = head; // start at the beginning

        while (temp != NULL)
        {
            if (temp->item == item)
            {
                break;
            }
            else if (temp->next == NULL && temp->item != item)
            {
                cout << "item not in the list!" << endl;
                exit(1);
            }

            previous = temp;
            temp = temp->next; // move to next node
        }

        if (temp == NULL)
        {
            return NULL_VALUE; // item not found to delete or empty list
        }
        else if (temp == head && temp->next == NULL)
        {
            head = tail = NULL;
        }
        else if (temp == head)
        {
            head = head->next; // delete the first node

            cout << "tail  " << tail->item << endl;
            cout << "head  " << head->item << endl;
        }
        else
        {
            previous->next = temp->next;
            ListNode *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            tail = temp;

            cout << "tail  " << tail->item << endl;
            cout << "head  " << head->item << endl;
        }

        delete[] temp;
        length--;
        return SUCCESS_VALUE;
    }

    ListNode *searchItem(int item) const
    {
        ListNode *temp = head; // start at the beginning

        while (temp != NULL)
        {
            if (temp->item == item)
            {
                return temp;
            }

            temp = temp->next; // move to next node
        }

        return NULL; // Not found
    }

    void printList() const
    {
        ListNode *temp = head;

        while (temp != NULL)
        {
            printf("%d->", temp->item);
            temp = temp->next;
        }

        printf("\n");
        printf("Length: %d\n", getLength());
    }

    //------------write code for the functions below-----------
    int insertLast(int item)
    {
        ListNode *temp = new ListNode();

        if (head == NULL)
        {
            cout << "please insert first and then try again." << endl;
            return NULL_VALUE;
        }
        else
        {
            temp->item = item;
            tail->next = temp;
            tail = temp;
        }
        cout << "head  " << head->item << endl;
        cout << "tail  " << tail->item << endl;

        length++;
        return SUCCESS_VALUE;
    }

    ListNode *getItemAt(int position) const
    {
        int pos = 1;
        ListNode *temp = new ListNode();
        temp = head;
        while (temp != NULL)
        {
            if (pos == position)
                return temp;
            else if (pos > length)
                return NULL;
            temp = temp->next;
            pos++;
        }
    }

    int deleteLast()
    {
        if (head == NULL)
            return -1;
        else if (head->next == NULL)
            head = tail = NULL;
        else
        {
            ListNode *cur = head;
            ListNode *prev = NULL;
            while (cur->next != NULL)
            {
                prev = cur;
                cur = cur->next;
            }
            prev->next = NULL;
            tail = prev;
            delete cur;

            cout << "head  " << head->item << endl;
            cout << "tail  " << tail->item << endl;
        }
        length--;
    }
    void swap(int pos1, int pos2)
    {

        ListNode *temp = head;
        int position = 0;

        ListNode *temp1, *temp2;

        if (pos1 <= length && pos2 <= length)
        {
            if (pos1 == pos2)
            {
                /*nothing to do*/
            }
            else
            {
                while (temp != NULL)
                {
                    if (position == pos1)
                    {
                        temp1 = temp;
                    }
                    if (position == pos2)
                    {
                        temp2 = temp;
                    }
                    position++;
                    temp = temp->next;
                }
                int temporary;
                temporary = temp1->item;
                temp1->item = temp2->item;
                temp2->item = temporary;
            }
        }
        else
            cout << "out of bound!" << endl;
    }

    // Added
    ~LinkedListWithTail()
    {
        while (deleteLast() != NULL_VALUE)
        {
            /*NOTHING here*/
        }
    }
};

int main(void)
{
    LinkedListWithTail ll;
    int choice, item;

    while (1)
    {
        printf("\n1. Insert item (First)\n2. Insert item (Last)\n");
        printf("3. Delete item (Last)\n4. Delete item\n");
        printf("5. Search item\n6. Get item at\n7. Print list\n8. Swap\n9. exit\n");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ll.insertItem(item);
        }
        else if (choice == 2)
        {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ll.insertLast(item);
        }
        else if (choice == 3)
        {
            if (ll.deleteLast() == NULL_VALUE)
            {
                printf("\nDeletion failed\n");
            }
            else
            {
                printf("\nDeletion successful\n");
            }
        }
        else if (choice == 4)
        {
            printf("\nEnter item: ");
            scanf("%d", &item);

            if (ll.deleteItem(item) == NULL_VALUE)
            {
                printf("\nDeletion failed\n");
            }
            else
            {
                printf("\nDeletion successful\n");
            }
        }
        else if (choice == 5)
        {
            printf("\nEnter item: ");
            scanf("%d", &item);

            ListNode *returnNode = ll.searchItem(item);

            if (returnNode != NULL)
            {
                printf("\nItem found\n");
            }
            else
            {
                printf("\nItem not found\n");
            }
        }
        else if (choice == 6)
        {
            int position;

            printf("\nEnter position: ");
            scanf("%d", &position);

            ListNode *returnNode = ll.getItemAt(position);

            if (returnNode != NULL)
            {
                printf("\nItem found: %d\n", returnNode->item);
            }
            else
            {
                printf("\nItem not found\n");
            }
        }
        else if (choice == 7)
        {
            ll.printList();
        }
        else if (choice == 8)
        {
            int pos1, pos2;
            cout << "Enter position 1 : ";
            cin >> pos1;
            cout << "Enter position 2 : ";
            cin >> pos2;
            ll.swap(pos1, pos2);
        }
        else if (choice == 9)
        {
            break;
        }
        else
        {
            printf("\nInvalid choice\n");
        }

        printf("\n---------------------------------------------\n\n");
    }

    return 0;
}
