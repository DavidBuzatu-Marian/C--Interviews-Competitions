#include <iostream>

struct Node
{
    int value;
    Node *left, *right;
};

Node *createMinimalBST(int array[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int middle = (start + end) / 2;
    Node *root = new Node;
    root->value = array[middle];
    root->left = createMinimalBST(array, start, middle - 1);
    root->right = createMinimalBST(array, middle + 1, end);
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        std::cout << root->value << " ";
        inorder(root->right);
    }
}

int main()
{
    int arr[100];
    for (int i = 0; i < 8; ++i)
    {
        arr[i] = i;
    }
    Node *root = createMinimalBST(arr, 0, 7);
    inorder(root);
}