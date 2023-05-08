int value;
    cout << "enter node value : ";
    cin >> value;
    Node *temp = insertion(root, value);
    if (value < temp->data)
        temp->left = create_node(value);
    else
        temp->right = create_node(value);