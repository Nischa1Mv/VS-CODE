#include <stdio.h>
#include <malloc.h>
#include <conio.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL, *n;
void inorder(struct node *);
struct node *insert(struct node *r, int data);
struct node *del(struct node *, int data);
struct node *findmin(struct node *);
void main()
{
    int i, n, v, e, ch;
    clrscr();
    do
    {
        printf("\n1. Creation of BST\n");
        printf("\n2. Insertion\n");
        printf("\n3. Deletion\n");
        printf("\n4. Display(Inorder Traversal)\n");
        printf("\n5. Exit\n");
        printf("\nEnter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nHow many Node\n");
            scanf("%d", &n);
            for (i = 0; i < n; i++)
            {
                printf("\nData %d:", i + 1);
                scanf("%d", &v);
                root = insert(root, v);
            }
            break;
        case 2:
            printf("\nEnter Element to Insert\n");
            scanf("%d", &e);
            root = insert(root, e);
            break;
        case 3:
            printf("\nEnter Element to delete\n");
            scanf("%d", &e);
            root = del(root, e);
            break;
        case 4:
            printf("\nInorder Traversal of Binary Tree\n");
            inorder(root);
            break;
        case 5:
            exit(0);
        }
    } while (ch != 5);
}
struct node *insert(struct node *r, int v)
{
    if (r == NULL)
    {
        r = (struct node *)malloc(sizeof(struct node));
        r->data = v;
        r->left = NULL;
        r->right = NULL;
    }
    else if (v < r->data)
        r->left = insert(r->left, v);
    else
        r->right = insert(r->right, v);
    return r;
}
void inorder(struct node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf("%4d", temp->data);
        inorder(temp->right);
    }
}
int search(struct node *root, int val)
{
    if (root == NULL)
        return 0;
    else if (root->data == val)
        return 1;
    else if (val < root->data)
        search(root->left, val);
    else if (val > root->data)
        search(root->right, val);
}
struct node *del(struct node *root, int val)
{
    int c;
    struct node *temp;
    c = search(root, val);
    if (root == NULL)
        return root;
    else if (val < root->data)
        root->left = del(root->left, val);
    else if (val > root->data)
        root->right = del(root->right, val);
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
            return root;
        }
        else if (root->left == NULL)
        {
            struct node *temp = root;
            root = root->right;
            free(temp);
            return root;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root;
            root = root->left;
            free(temp);
            return root;
        }
        else
        {
            temp = findmin(root->right);
            root->data = temp->data;
            root->right = del(root->right, temp->data);
        }
    }
    return root;
}
struct node *findmin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}