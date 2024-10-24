#include <bits/stdc++.h>

using namespace std;

struct TreeNodeInt
{
    int value;
    TreeNodeInt *left;
    TreeNodeInt *right;

    TreeNodeInt(int v)
    {
        value = v;
        left = right = nullptr;
    }
};

// In-order DFS: Left, Root, Right
void inOrderTraversal(TreeNodeInt *node)
{
    if (node == nullptr)
        return;
    inOrderTraversal(node->left);
    cout << node->value << endl;
    inOrderTraversal(node->right);
}

// Pre-order DFS: Root, Left, Right
void preOrderTraversal(TreeNodeInt *node)
{
    if (node == nullptr)
        return;
    cout << node->value << endl;
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

// Post-order DFS: Left, Right, Root
void postOrderTraversal(TreeNodeInt *node)
{
    if (node == nullptr)
        return;
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    cout << node->value << endl;
}

void insertInBinaryTree()

int main()
{
    TreeNodeInt *root = new TreeNodeInt(100);

    TreeNodeInt *node1 = new TreeNodeInt(80);
    TreeNodeInt *node2 = new TreeNodeInt(50);
    TreeNodeInt *node3 = new TreeNodeInt(40);

    TreeNodeInt *node4 = new TreeNodeInt(120);
    TreeNodeInt *node5 = new TreeNodeInt(130);
    TreeNodeInt *node6 = new TreeNodeInt(110);

    root->left = node1;
    root->right = node4;

    node1->left = node3;
    node3->right = node2;

    node4->left = node6;
    node4->right = node5;

    preOrderTraversal(root);
    free(root);
    root = nullptr;
    return 0;
}