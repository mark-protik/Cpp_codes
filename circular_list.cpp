#include <iostream>

using namespace std;

struct ListNode
{
    int value;
    ListNode *nextPtr;
};

ListNode *head = NULL;
ListNode *tail = NULL;

ListNode *createListNode(int data)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    temp->value = data;
    temp->nextPtr = NULL;
    return temp;
}

void insertLast(int data)
{
    if (head == NULL)
    {
        head = createListNode(data);
        tail = head;
        head->nextPtr = head;  
    }
    else
    {
        ListNode *temp = createListNode(data);
        tail->nextPtr = temp;
        tail = tail->nextPtr;
        tail->nextPtr = head;  
        temp = NULL;
    }
}

void insertFirst(int data)
{
    if (head == NULL)
    {
        head = createListNode(data);
        tail = head;
        head->nextPtr = head;  
    }
    else
    {
        ListNode *temp = createListNode(data);
        temp->nextPtr = head;
        head = temp;
        tail->nextPtr = head;  
        temp = NULL;
    }
}

void printList()
{
    for (ListNode *i = head; i != tail; i = i->nextPtr)  
    {
        printf("%d ", i->value);
    }
    printf("%d\n", tail->value);  
}

ListNode *linearSearch(int key)
{
    for (ListNode *i = head; i != tail; i = i->nextPtr) 
    {
        if (i->value == key)
            return i;
    }
    return NULL;
}

void insertMiddle(int data, int insertAfter)
{
    ListNode *loc = linearSearch(insertAfter);
    if (loc == NULL)
        return;

    ListNode *temp = createListNode(data);
    temp->nextPtr = loc->nextPtr;
    loc->nextPtr = temp;
    temp = NULL;
}

int main()
{
    insertLast(1);
    insertLast(2);
    insertLast(3);
    insertFirst(0);
    printList();  
    return 0;
}