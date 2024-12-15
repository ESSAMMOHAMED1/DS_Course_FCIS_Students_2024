#include <iostream>

using namespace std;

// Define a Node structure
struct Node
{
    int key;
    Node *left;
    Node *right;

    // Constructor to initialize a Node
    Node(int item) : key(item), left(nullptr), right(nullptr) {}
};

// Inorder Traversal
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " -> ";
        inorder(root->right);
    }
}

// Insert a node
Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Find the node with the smallest key (inorder successor)
Node *minValueNode(Node *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}

// Delete a node
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return nullptr;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        // Node with only one child or no child
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node *temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

// Free the entire tree (memory cleanup)
void freeTree(Node *root)
{
    if (root)
    {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

// Driver code
int main()
{
    Node *root = nullptr;

    // Insert nodes
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    cout << "After deleting 10\n";
    root = deleteNode(root, 10);
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    // Free memory allocated for the tree
    freeTree(root);

    return 0;
}
