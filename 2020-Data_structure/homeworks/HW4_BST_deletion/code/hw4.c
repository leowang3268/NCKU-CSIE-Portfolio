#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

/* for generating new node in insertion */
struct node *newNode(int data) // for generating new node in insertion
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return node;
};

/* insert the node containing the data */
struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return newNode(data);

    if (data == node->key) // repeated
        return node;       //unsure

    else if (data < node->key)
        node->left = insert(node->left, data);

    else
        node->right = insert(node->right, data);
}

/* find smallest node in right subtree */
struct node *minNode(struct node *node)
{
    struct node *tmp_node = node;
    while (tmp_node != NULL && tmp_node->left != NULL)
        tmp_node = tmp_node->left;
    return tmp_node;
}

/* delete the node containing specific data */
struct node *delete (struct node *node, int data)
{
    if (node == NULL) // tree is already empty
        return NULL;

    if (data == node->key) //
    {
        /* node with only one child or no child */
        if (node->left == NULL)
        {
            struct node *tmp_node = node->right;
            free(node);
            return tmp_node;
        }
        else if (node->right == NULL)
        {
            struct node *tmp_node = node->left;
            free(node);
            return tmp_node;
        }

        /* node with two children: Get inorder successor (smallest in the right tree) */
        struct node *tmp_node = minNode(node->right);
        node->key = tmp_node->key;
        node->right = delete (node->right, tmp_node->key); //set right child as temp root, and find the min in this subtree

        /*
        struct node *min_node = node->right;
        struct node *min_node_parent = node;
        
        while (min_node->left != NULL)
        {
            min_node_parent = min_node;
            min_node = min_node->left;
        }
        node->key = min_node->key;
        min_node_parent->left = NULL; //?????? 當right沒有child時會出問題
        free(min_node);
        */
    }

    else if (data < node->key)
        node->left = delete (node->left, data);

    else
        node->right = delete (node->right, data);

    return node;
}

/*
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
*/

struct queue
{
    struct node *data;
    struct queue *link;
};
struct queue *front;
struct queue *rear;

void enqueue(struct node *node)
{
    struct queue *tmp = malloc(sizeof(*tmp));
    tmp->data = node;
    tmp->link = NULL;
    if (front != NULL)
        rear->link = tmp;
    else
        front = tmp;
    rear = tmp;
}

struct node *dequeue()
{
    struct queue *tmp = front;
    struct node *node;
    if (tmp == NULL)
        fprintf(stderr, "The queue is empty.\n");
    node = tmp->data;
    front = tmp->link;
    free(tmp);
    return node;
}

/* Level Order Traversal by using queue */
void printLevelOrder(struct node *root)
{
    struct node *tmp_node = root;
    while (tmp_node != NULL)
    {
        if (tmp_node == root)
            printf("%d", tmp_node->key);
        else
            printf("\n%d", tmp_node->key);
        if (tmp_node->left != NULL)
            enqueue(tmp_node->left);
        if (tmp_node->right != NULL)
            enqueue(tmp_node->right);
        if (front != NULL)
            tmp_node = dequeue();
        else
            break;
    }
}

int main()
{
    int data;
    // read the root
    scanf("%d", &data);
    struct node *root = NULL;
    root = insert(root, data);

    char str[MAX_LENGTH];
    const char *delim = " ";

    /* Insertion */
    fgets(str, MAX_LENGTH, stdin);

    for (char *pch = strtok(str, delim); pch != NULL; pch = strtok(NULL, delim))
    {
        int data = atoi(pch);
        if (data >= 1 && data <= 100)
            root = insert(root, data);
    }

    /* Deletion */
    fgets(str, MAX_LENGTH, stdin); // Deletion

    for (char *pch = strtok(str, delim); pch != NULL; pch = strtok(NULL, delim))
    {
        int data = atoi(pch);
        if (data >= 1 && data <= 100)
        {
            root = delete (root, data);
            //inorder(root);
            //printf("\n");
        }
    }

    printLevelOrder(root);

    return 0;
}