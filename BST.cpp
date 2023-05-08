#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *create_node(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void in_order(Node *root)
{
    if (root == NULL)
        return;
    in_order(root->left);
    cout << root->data << " ";
    in_order(root->right);
}

Node *search(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    else if (root->data == key)
        return root;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

Node *insertion(Node *root, int data)
{
    Node *prev = NULL;

    if (root->left == NULL && root->right == NULL)
    {
        return root;
    }
    else
    {
        while (root != NULL)
        {
            if (data < root->data)
            {
                prev = root;
                root = root->left;
            }
            else
            {
                prev = root;
                root = root->right;
            }
        }
        return prev;
    }
}

Node *FindMax(Node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Function to search a delete a value from tree.
Node *Delete(Node *root, int data)
{
    if (root == NULL)
        return root;
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    // Wohoo... I found you, Get ready to be deleted
    else
    {
        // Case 1:  No child
        if (root->left == NULL && root->right == NULL)
        {
            delete root; // now root's address has freed but the address is till allocated there so we have to manually set it to NULL
            root = NULL;
        }
        // Case 2: One child
        else if (root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        // case 3: 2 children
        else
        {
            Node *temp = FindMax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left, temp->data);
        }
    }
    return root;
}

int main()
{
    Node *root = create_node(50);

    root->left = create_node(40);
    root->right = create_node(60);

    root->left->left = create_node(15);
    root->left->right = create_node(45);
    root->right->left = create_node(55);
    root->right->right = create_node(70);

    root->left->left->left = create_node(10);
    root->left->left->right = create_node(20);
    root->left->right->right = create_node(47);

    in_order(root);
    cout << endl;

    //! searching .....

    // Node *tempNode = search(root, 50);
    // if (tempNode == NULL)
    //     cout << "not in the BST";
    // else
    //     cout << tempNode->data << " has found";

    //! insertion .....

    int value;
    cout << "enter node value : ";
    cin >> value;
    Node *temp = insertion(root, value);
    if (value < temp->data)
        temp->left = create_node(value);
    else
        temp->right = create_node(value);

    //! deletion .....

    Delete(root, 45);
    Delete(root, 47);
    Delete(root, 50);

    in_order(root);

    return 0;
}