#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX(X, Y) ((X > Y) ? X : Y)

struct node
{
    char name[21];
    char phone[11];
    int height;
    int balanceFactor;
    struct node *left;
    struct node *right;
};

/* for generating new node in insertion */
struct node *newNode(char *name, char *phone) // for generating new node in insertion
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    strcpy(node->name, name);
    strcpy(node->phone, phone);
    node->height = 0;
    node->balanceFactor = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
};

int getHeight(struct node *node)
{
    //int leftHeight = 0, rightHeight = 0;

    if (node == NULL)
        return -1;
    return node->height;
    /*
    if (node->left == NULL && node->right == NULL) // can be modified by deleting this part,
        return 0;                                  // and removing the conditions of belowwing part

    if (node->left != NULL)
        leftHeight = getHeight(node->left);

    if (node->right != NULL)
        rightHeight = getHeight(node->right);

    return MAX(leftHeight, rightHeight) + 1;
*/
}

int getBalanceFactor(struct node *node)
{
    if (node == NULL)
        return 0;
    return (getHeight(node->left) - getHeight(node->right));
}

struct node *LeftRotation(struct node *node)
{
    struct node *tmp = node->right;
    struct node *tmp2 = tmp->left;
    node->right = tmp2;
    tmp->left = node;

    node->height = MAX(getHeight(node->left), getHeight(node->right)) + 1;
    node->balanceFactor = getBalanceFactor(node);
    tmp->height = MAX(getHeight(tmp->left), getHeight(tmp->right)) + 1;
    tmp->balanceFactor = getBalanceFactor(tmp);
    return tmp;
}

struct node *RightRotation(struct node *node)
{
    //int L_height = node->left->height;
    //int R_height = node->right->height;
    struct node *tmp = node->left;
    struct node *tmp2 = tmp->right;
    node->left = tmp2;
    tmp->right = node;

    node->height = MAX(getHeight(node->left), getHeight(node->right)) + 1;
    node->balanceFactor = getBalanceFactor(node);
    tmp->height = MAX(getHeight(tmp->left), getHeight(tmp->right)) + 1;
    tmp->balanceFactor = getBalanceFactor(tmp);
    return tmp;
}

/* insert the node containing the data */
struct node *insert(struct node *node, char *name, char *phone)
{
    if (node == NULL)
        return newNode(name, phone);

    else if (strcmp(name, node->name) < 0)
    {
        //if (node->left == NULL && node->right == NULL)
        //    node->balanceFactor++;
        node->left = insert(node->left, name, phone);
    }

    else if (strcmp(name, node->name) > 0)
    {
        //if (node->left == NULL && node->right == NULL)
        //    node->balanceFactor--;
        node->right = insert(node->right, name, phone);
    }
    /* update height of this node */
    node->height = MAX(getHeight(node->left), getHeight(node->right)) + 1;

    /* update BF of this node */
    node->balanceFactor = getBalanceFactor(node);
    //printf("Before: %s:%d %d\n", node->name, node->height, node->balanceFactor);

    /* Balance the tree */
    if (node->balanceFactor == 2) // Left unbalanced
    {
        if (node->left->balanceFactor == 1) //LL
            return RightRotation(node);
        else if (node->left->balanceFactor == -1) // LR
        {
            node->left = LeftRotation(node->left);
            return RightRotation(node);
        }
    }

    else if (node->balanceFactor == -2) // Right unbalanced
    {
        if (node->right->balanceFactor == -1) // RR
            return LeftRotation(node);
        else if (node->right->balanceFactor == 1) //RL
        {
            node->right = RightRotation(node->right);
            return LeftRotation(node);
        }
    }
    //printf("After: %s:%d %d\n", node->name, node->height, node->balanceFactor);
    return node;
}

int print_cnt = 0, input_cnt = 0;

void printPreorder(struct node *node)
{
    if (node == NULL)
        return;
    print_cnt++;
    if (print_cnt < input_cnt)
        printf("%s ", node->name);
    else if (print_cnt == input_cnt)
        printf("%s", node->name);
    //printf("\n%d %d\n", node->height, node->balanceFactor);
    printPreorder(node->left);
    printPreorder(node->right);
}

void searchAndPrint(struct node *node, char *searchWho)
{
    if (node == NULL)
    {
        printf("\n%s null", searchWho);
        return;
    }
    if (strcmp(searchWho, node->name) == 0)
        printf("\n%s %s", searchWho, node->phone);

    else if (strcmp(searchWho, node->name) > 0)
        searchAndPrint(node->right, searchWho);

    else if (strcmp(searchWho, node->name) < 0)
        searchAndPrint(node->left, searchWho);
}

int main()
{
    char action[2];
    char tmp[21];
    char name[21];
    char phone[11];
    char searchWho[21];
    scanf("%s", action);

    struct node *root = NULL;

    while (true)
    {
        scanf("%s", tmp);
        input_cnt++;
        if (strcmp(tmp, "S") == 0) // Start of Search
        {
            input_cnt--;
            break;
        }
        strcpy(name, tmp);
        scanf("%s", phone);

        /* build a tree */
        root = insert(root, name, phone);
    }

    /* print the node name in preorder */
    printPreorder(root);

    while (true)
    {
        scanf("%s", tmp);
        if (strcmp(tmp, "E") == 0) // End of Input
            break;

        strcpy(searchWho, tmp);
        /* search */
        searchAndPrint(root, searchWho);
    }

    return 0;
}