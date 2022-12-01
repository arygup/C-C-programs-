#include <stdio.h>
#include <stdlib.h>

typedef struct node_rec
{ // Two equivalent types: "struct node" is equivalent to "Node"
    // char *name;
    int key;
    struct node_rec *next;
    // Node *next;
} Node;

Node *head = NULL;

// Invariant: N->next == NULL
Node *allocateNode(int key)
{
    Node *N;

    N = (Node *)malloc(sizeof(Node));
    N->key = key;
    N->next = NULL;

    return N;
}

void freeNode(Node *node)
{
    free(node);
}

// do insertion so that the list is sorted
void insertNode(int key)
{

    Node *N;

    N = allocateNode(key);

    // Base -1 case
    if (head == NULL)
    {
        head = N;
        return;
    }

    // Base case
    if (key < head->key)
    {
        N->next = head;
        head = N;
        return;
    }

    // Inductive Case
    Node *pnode, *cnode;
    pnode = head;
    cnode = head->next;
    while (cnode != NULL)
    {
        if (key < cnode->key)
        {
            pnode->next = N;
            N->next = cnode;
            return;
        }
        pnode = cnode;
        cnode = cnode->next;
    }

    // Inductive Case +1
    pnode->next = N;
}

void deleteNode(int key)
{
    Node *pnode = NULL, *cnode;

    // Base Case -1

    if (head == NULL)
        return;

    cnode = head;
    // Base Case
    if (cnode->key == key)
    {
        head = cnode->next;
        freeNode(cnode);
        return;
    }

    // Inductive Case
    pnode = cnode;
    cnode = cnode->next;
    while (cnode != NULL)
    {
        if (cnode->key == key)
        {
            pnode->next = cnode->next;
            freeNode(cnode);
            return;
        }
        pnode = cnode;
        cnode = cnode->next;
    }
}

Node *searchNode(int key)
{
    for (Node *cnode = head; cnode != NULL; cnode = cnode->next)
    {
        if (cnode->key == key)
            return cnode;
    }
    return NULL;
}

void printList(int key)
{
    printf("======\n");
    for (Node *cnode = head; cnode != NULL; cnode = cnode->next)
    {
        printf("%d\n", cnode->key);
    }
    printf("======\n");
}

void main(int argc, char *argv[])
{
    FILE *fp;
    int key;

    fp = fopen(argv[1], "r");

    while (fscanf(fp, "%d", &key) != EOF)
    {
        insertNode(key);
    }
}