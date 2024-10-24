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

TreeNodeInt *returnBST()
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

    return root;
}

class Tree_TreeNodeInt
{
public:
    TreeNodeInt *root = nullptr;
    // Tree_(/* args */);
    // ~Tree_();
    TreeNodeInt *Insert(TreeNodeInt *node, TreeNodeInt *newNode);
};

TreeNodeInt *Tree_TreeNodeInt::Insert(TreeNodeInt *node, TreeNodeInt *newNode)
{
    if (node == nullptr)
    {
        return newNode;
    }
    if (node->value > newNode->value)
    {
        node->right = this->Insert(node->right, newNode);
    }
    if (node->value < newNode->value)
    {
        node->left = this->Insert(node->left, newNode);
    }
}

// Tree_::Tree_(/* args */)
// {
// }

// Tree_::~Tree_()
// {
// }

int main()
{
    int a[10] = {20, 10, 40, 50, 60, 30, 90, 80, 100, 70};
    Tree_TreeNodeInt tree;
    TreeNodeInt *root = new TreeNodeInt(100);
    TreeNodeInt *root1 = new TreeNodeInt(200);
    TreeNodeInt *root2 = new TreeNodeInt(50);
    TreeNodeInt *root3 = new TreeNodeInt(600);
    tree.root = root;
    tree.Insert(nullptr,root);
    tree.Insert(tree.root,root1);
    tree.Insert(tree.root,root2);
    tree.Insert(tree.root,root3);
    inOrderTraversal(tree.root);

    return 0;
}