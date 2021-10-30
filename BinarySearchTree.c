#include <stdlib.h>
#include <stdio.h>

struct BstNode
{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

struct BstNode *GetNewNode(int data)
{
    struct BstNode *newNode = (struct BstNode *)malloc(sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BstNode *Insert(struct BstNode *root, int data)
{
    if (root == NULL)
    {
        root = GetNewNode(data);
    }
    else if (data <= root->data)
    {
        root->left = Insert(root->left, data);
    }
    else
    {
        root->right = Insert(root->right, data);
    }
    return root;
}

int Search(struct BstNode *root, int data)
{
    if (root == NULL)
        return 0;
    if (root->data == data)
        return root->data;
    else if (data <= root->data)
        return Search(root->left, data);
    else
        return Search(root->right, data);
}

int FindMin(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is Empty\n");
        return -1;
    }
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}
int FindMax(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error: Tree is Empty\n");
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int FindMaxRecursive(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error: The Tree is Empty\n");
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return FindMaxRecursive(root->right);
}
int FindMinRecursive(struct BstNode *root)
{
    if (root == NULL)
    {
        printf("Error: The Tree is Empty\n");
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return FindMinRecursive(root->left);
}

int FindHeight(struct BstNode *root)
{
    if (root == NULL)
        return -1;
    if (FindHeight(root->left) > FindHeight(root->right))
    {
        return FindHeight(root->left) + 1;
    }
    else
    {
        return FindHeight(root->right) + 1;
    }
}

int main()
{
    struct BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    root = Insert(root, 25);
    root = Insert(root, 8);
    root = Insert(root, 12);
    int number;
    printf("Enter Number Be Searched = ");
    scanf("%d", &number);
    if (Search(root, number) != 0)
    {
        printf("Found\n");
    }
    else
    {
        printf("Not Found");
    }
    printf("The Minimum is = %d\n", FindMinRecursive(root));
    printf("The Maximum is = %d\n", FindMaxRecursive(root));
    printf("Height Of Tree is = %d\n", FindHeight(root));
}