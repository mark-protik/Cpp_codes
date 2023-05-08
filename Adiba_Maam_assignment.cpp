#include <stdio.h>
#include <stdlib.h>

struct node // make node for linked list using structure
{
    int value;         // value part of node contains the element
    struct node *next; // the next part of node contains the address of next element of list
};

struct node *head; // contains the address of first element of linked list

void init()
{
    head = NULL; // initialize the beginning(head) of list to NULL
}

void insertfirst(int element) // inserts element in linked list
{
    struct node *New;
    New = (struct node *)malloc(sizeof(struct node)); // New named node declared with size of node declared before
    New->value = element;                             // inserts the new element to the value part of node New
    New->next = NULL;                                 // makes the next part of node New NULL so that no garbage value remains
    New->next = head;                                 // the address of previously first node, which was stored in head is now assigned to next part of node New
    head = New;                                       // the address of new first element which is present in node New is assigned to head node
}

void print()
{
    if (head == NULL) // condition to check whether list is empty
    {
        printf("list is empty\n");
        return;
    }
    struct node *cur = head;
    int count;
    count = 0;
    while (cur != NULL) // the loop traverse until it gets any NULL node
    {
        printf("%d->", cur->value);
        count++;         // counts the number of nodes or elements present in list
        cur = cur->next; // moves cur pointer to next node to check and get value
    }
    printf("NULL\n");
    printf("number of nodes %d\n", count);
}

void deleteitem(int ele)
{
    if (head == NULL)
        printf("list is empty and nothing to delete\n");
    struct node *cur = head;
    struct node *prev = NULL;
    while (cur->value != ele)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev != NULL)
        prev->next = cur->next; // the address of next node after the node containing element to be deleted is assigned to the previous node of the node containing the element to be deleted
    free(cur);                  // memory of the structure cur is deallocated
}

int searchitem(int ele)
{
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        if (temp->value == ele)
            return 1; // element is found
        temp = temp->next;
    }
    return 0;
}

void insertlast(int ele) // insert at the last of linked list
{
    struct node *New, *temp;
    New = (struct node *)malloc(sizeof(struct node));
    if (New == NULL)
    {
        printf("Unable to allocate memory.");
        return;
    }
    else
    {
        New->value = ele;
        New->next = NULL;
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = New;
        printf("DATA INSERTED SUCCESSFULLY\n");
    }
}

void deletelast() // delete the last element
{
    if (head == NULL)
    {
        printf("list is empty and nothing to delete\n");
    }
    struct node *cur = head;
    struct node *prev = NULL;
    while (cur->next != NULL)
    {
        prev = cur;
        cur = cur->next;
    }
    if (prev->next != NULL)
        prev->next = NULL;
    free(cur);
}

void deletefirst() // delete the first element
{
    struct node *cur;
    if (head == NULL)
        printf("list is empty and nothing to delete\n");
    cur = head;
    head = head->next;
    free(cur);
}

void insertafter(int elem, int num) // inserts element for any given element present in linked list
{
    struct node *New;
    New = (struct node *)malloc(sizeof(struct node));
    New->value = elem;
    New->next = NULL;
    struct node *prev = head;
    while (prev->value != num)
    {
        prev = prev->next;
    }
    New->next = prev->next;
    prev->next = New;
}

void printReverse(struct node *head) // print the linked list in reverse way using recursion
{
    if (head == NULL)
        return;
    printReverse(head->next);
    printf("%d->", head->value);
}

void reverselist() // reverse the linked list
{
    struct node *prev = NULL;
    struct node *cur = head;
    struct node *nxt;
    while (cur != NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev; // points the head pointer to prev as it the new head or beginning in reverse list
}

void sum() // sum of elements of the linked list
{
    int s;
    struct node *cur = head;
    s = 0;
    while (cur != NULL)
    {
        s += cur->value;
        cur = cur->next;
    }
    printf("Sum of elements is %d\n", s);
}

void remove_duplicate()
{
    struct node *current = head;
    struct node *next_node = NULL;

    struct node *temp = NULL;
    int flag = 0;
    while (current != NULL)
    {
        struct node *prev = current;
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
        // tail = prev;
        // cout << tail->value << endl;
        current = current->next;
    }
}
void sort_ascending()
{
    if (head == NULL)
        return;
    else
    {
        struct node *Temp = head;

        while (Temp->next != NULL)
        {
            struct node *temp = Temp;
            struct node *min_loc = temp;
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
    remove_duplicate();
}

void destructor()
{
    struct node *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    init();

    // insertfirst(1);
    // insertlast(2);
    // insertlast(3);
    // insertlast(4);
    // insertlast(5);
    // insertlast(6);
    // insertlast(7);
    // insertlast(8);
    // sort_ascending();
    // destructor();
    // print();

    int ch, element;
    while (1)
    {
        printf("\n1. Insert new item. \n2. Delete item. \n3. Search item. \n4. Insert Last. \n5. Print. \n6. Delete Last \n7. Delete First \n8. Insert After \n9. Print Linked List in Reverse way. \n10. Sum. \n11. Make the linked list reverse. \n12. Destructor. \n13. Exit\n--------------------------------------------------------------------------------------\n");
        printf("enter choice of input: ");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("enter element to list: ");
            scanf("%d", &element);
            insertfirst(element);
        }
        else if (ch == 2)
        {
            int de;
            printf("enter element to delete ");
            scanf("%d", &de);
            deleteitem(de);
        }
        else if (ch == 3)
        {
            int se, reply;
            printf("enter element to search ");
            scanf("%d", &se);
            reply = searchitem(se);
            if (reply == 1)
                printf("element found\n");
            else
                printf("element not found\n");
        }
        else if (ch == 4)
        {
            int le;
            printf("enter element to insert at last ");
            scanf("%d", &le);
            insertlast(le);
        }
        else if (ch == 5)
        {
            print();
        }
        else if (ch == 6)
        {
            deletelast();
        }
        else if (ch == 7)
        {
            deletefirst();
        }
        else if (ch == 8)
        {
            int ie, p;
            printf("enter element to insert: ");
            scanf("%d", &ie);
            printf("enter after which element to insert: ");
            scanf("%d", &p);
            insertafter(ie, p);
        }
        else if (ch == 9)
        {
            printReverse(head);
        }
        else if (ch == 10)
        {
            sum();
        }
        else if (ch == 11)
        {
            reverselist();
        }
        else if (ch == 12)
            destructor();
        else if (ch == 13)
            return 0;
        else
            return 0;
    }
    return 0;
}
