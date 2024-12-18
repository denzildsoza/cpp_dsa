#include <bits/stdc++.h>

using namespace std;

struct TreeNodeInt
{
    int value;
    TreeNodeInt *left;
    TreeNodeInt *right;
    int depth;

    TreeNodeInt(int v)
    {
        value = v;
        left = right = nullptr;
        depth = 0;
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
    TreeNodeInt *Delete(TreeNodeInt *node, int key);
    TreeNodeInt *LeftRotate(TreeNodeInt *node);
    TreeNodeInt *RightRotate(TreeNodeInt *node);
    int BalanceFactor(TreeNodeInt *node);
};
int getDepth(TreeNodeInt *node)
{
    if (node == nullptr)
    {
        return 0;
    }
    return node->depth;
}
TreeNodeInt *Tree_TreeNodeInt::Insert(TreeNodeInt *node, TreeNodeInt *newNode)
{
    if (node == nullptr)
    {
        return newNode;
    }
    if (node->value > newNode->value)
    {
        node->left = this->Insert(node->left, newNode);
    }
    if (node->value < newNode->value)
    {
        node->right = this->Insert(node->right, newNode);
    }
    this->BalanceFactor(node);
    int bf = getDepth(node->left) - getDepth(node->right);

    // right right rotation
    if (bf > 1 && newNode->value < node->left->value)
    {
        return RightRotate(node);
    }

    // // left right rotate
    if (bf > 1 && newNode->value > node->left->value)
    {
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }
    // left left rotation
    if (bf < -1 && newNode->value > node->right->value)
    {
        return LeftRotate(node);
    }
    // right left rotation
    if (bf < -1 && newNode->value < node->right->value)
    {
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}

TreeNodeInt *getSuccessor(TreeNodeInt *curr)
{
    // 		to get inordersuccessor simply find
    // 		extreme left of right subtree of node
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

TreeNodeInt *Tree_TreeNodeInt::Delete(TreeNodeInt *node, int key)
{
    if (node == nullptr)
    {
        return nullptr;
    }
    if (node->value > key)
    {
        node->left = Delete(node->left, key);
        return node;
    }
    if (node->value < key)
    {
        node->right = Delete(node->right, key);
        return node;
    }
    if (node->left == nullptr && root->right == nullptr)
    {
        return nullptr;
    }
    if (node->left == nullptr)
    {
        return node->right;
    }
    if (node->right == nullptr)
    {
        return node->left;
    }
    if (node->left != nullptr && root->right != nullptr)
    {
        TreeNodeInt *succ = getSuccessor(root);
        root->value = succ->value;
        root->right = Delete(root->right, succ->value);
        return node;
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
    int depth = max(Lb, Rb);
    node->depth = depth;
    return depth;
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
    TreeNodeInt *temp = node->left->right;
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
    // int a[] = {100,90, 80};
    int a[] = {100, 20, 10, 40, 50, 60, 30, 90, 80, 71, 70, 5, 6, 89};
    Tree_TreeNodeInt tree;
    int arraySize = sizeof(a) / sizeof(int);
    for (int i = 0; i < arraySize; i++)
    {
        TreeNodeInt *newNode = new TreeNodeInt(a[i]);
        tree.root = tree.Insert(tree.root, newNode);
    }
    tree.BalanceFactor(tree.root);
    inOrderTraversal(tree.root);
    cout << endl;
    // preOrderTraversal(tree.root);
    // cout << endl;
    // postOrderTraversal(tree.root);
    tree.root = tree.Delete(tree.root, 50);
    inOrderTraversal(tree.root);
    cout << "end" << endl;
    return 0;
}