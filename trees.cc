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
    cout << node->value << " ";
    inOrderTraversal(node->right);
}

// Pre-order DFS: Root, Left, Right
void preOrderTraversal(TreeNodeInt *node)
{
    if (node == nullptr)
        return;
    cout << node->value << " ";
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
    cout << node->value << " ";
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
    TreeNodeInt *BalanceBinaryTree(TreeNodeInt *node);
    TreeNodeInt *BalanceTree(TreeNodeInt *node);
    TreeNodeInt *LeftRotate(TreeNodeInt *node);
    TreeNodeInt *RightRotate(TreeNodeInt *node);
    int BalanceFactor(TreeNodeInt *node);
};

TreeNodeInt *Tree_TreeNodeInt::Insert(TreeNodeInt *node, TreeNodeInt *newNode)
{
    if (node == nullptr)
    {
        return newNode;
    }
    if (node->value > newNode->value)
    {
        node->left = this->Insert(node->left, newNode);
        return node;
    }
    if (node->value < newNode->value)
    {
        node->right = this->Insert(node->right, newNode);
        return node;
    }
}

TreeNodeInt *Tree_TreeNodeInt::BalanceTree(TreeNodeInt *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }
}

int Tree_TreeNodeInt::BalanceFactor(TreeNodeInt *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    int Lb = 1 + BalanceFactor(node->left);
    int Rb = 1 + BalanceFactor(node->right);
    if (abs(Lb - Rb) > 1)
    {
        // Balancing Logic
    }
    return max(abs(Lb), abs(Rb));
}

TreeNodeInt *Tree_TreeNodeInt::BalanceBinaryTree(TreeNodeInt *node)
{
    int bf = BalanceFactor(node) - 1;
    cout << bf << endl;
    return node;
}

TreeNodeInt *Tree_TreeNodeInt::LeftRotate(TreeNodeInt *node)
{
    TreeNodeInt *temp = node->right->left;
    TreeNodeInt *temp1 = node->right;
    node->right->left = node;
    node->right = temp;
    return temp1;
}

TreeNodeInt *Tree_TreeNodeInt::RightRotate(TreeNodeInt *node)
{
    TreeNodeInt *temp  = node->left->right;
    TreeNodeInt *temp1 = node->left;
    node->left->right = node;
    node->left = temp;
    return temp1;
}

// Tree_::Tree_(/* args */)
// {
// }

// Tree_::~Tree_()
// {
// }

int main()
{
    int a[10] = {90, 80};
    // int a[10] = {20, 10, 40, 50, 60, 30, 90, 80, 71, 70};
    Tree_TreeNodeInt tree;
    TreeNodeInt *root = new TreeNodeInt(100);

    tree.root = root;
    tree.Insert(nullptr, root);

    int arraySize = sizeof(a) / sizeof(int);

    for (int i = 0; i < arraySize; i++)
    {
        TreeNodeInt *newNode = new TreeNodeInt(a[i]);
        tree.Insert(tree.root, newNode);
    }

    inOrderTraversal(tree.root);
    cout << endl;
    preOrderTraversal(tree.root);
    cout << endl;
    postOrderTraversal(tree.root);
    tree.BalanceBinaryTree(tree.root);
    TreeNodeInt *rotated = tree.RightRotate(tree.root);
    tree.BalanceBinaryTree(rotated);

    return 0;
}