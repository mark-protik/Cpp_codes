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
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void pre_order_print_tree(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    pre_order_print_tree(root->left);
    pre_order_print_tree(root->right);
}

void post_order_print_tree(Node *root)
{
    if (root == NULL)
        return;

    post_order_print_tree(root->left);
    post_order_print_tree(root->right);
    cout << root->data << " ";
}

void in_order_print_tree(Node *root)
{
    if (root == NULL)
        return;

    in_order_print_tree(root->left);
    cout << root->data << " ";
    in_order_print_tree(root->right);
}

int main()
{
    //! level 1
    Node *root = create_node(1);

    //! level 2
    root->left = create_node(2);
    root->right = create_node(3);

    //! level 3
    root->left->left = create_node(4);
    root->left->right = create_node(5);
    root->right->left = create_node(6);
    root->right->right = create_node(7);

    //! level 4
    root->left->right->left = create_node(9);
    root->right->right->left = create_node(15);

    //? printing tree
    cout << "Pre Order : ";
    pre_order_print_tree(root);
    cout << endl;
    cout << "Post Order : ";
    post_order_print_tree(root);
    cout << endl;
    cout << "In Order : ";
    in_order_print_tree(root);
}