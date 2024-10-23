class Node_Int
{
public:
    int value;
    struct Node_Int *left;
    struct Node_Int *right;

    Node_Int *createNode(int value)
    {
        Node_Int node;
        node.value = value;
        node.left = nullptr;
        node.right = nullptr;
    }
};

class Binary_Tree
{
public:
    Node_Int *root;

    struct Node_Int *Insert(int value);
    void preOrderTraversal(Node_Int *root);
};

void Binary_Tree::preOrderTraversal(Node_Int *root)
{
}

int main()
{

    return 0;
}