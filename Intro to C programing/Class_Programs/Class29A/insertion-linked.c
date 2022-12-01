#include <stdio.h>

typedef struct node_rec
{ // struct node == Node
    int key;
    struct node_rec *next;
} Node;

Node *head = NULL;

Node *allocateNode()
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

void insertNode(int key)
{
    Node *N;
    N = allocateNode(key);

    //base -1 case (list empty)
    if (head == NULL)
    {
        head = allocateNode(key);
        return;
    }
    // base case
    if(key < head->key)
    {
        N->next = head;
        head = N;
        return;
    }

    // inductive c ase
    Node *pnode, *cnode;
    pnode = head;
    cnode = head->next;
    while (cnode!= NULL)
    {
        if(key < cnode->key)
        {
            pnode->next = N;
            N->next=cnode;
            return;
        }
        pnode = cnode;

    }
    
}

void deleteNode(int key)
{
    Node *pnode = NULL, *cnode = head;
    // base case

    if (head == NULL)
        return;

    if (cnode->key == key)
    {
        head = cnode->next;
        freeNode(cnode);
        return;
    }

    // inductive case
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
}

void printList(int key)
{
    printf("===\n");
    for (Node *cnode = head; cnode != NULL; cnode = cnode->next)
    {
        printf("%d\n", cnode->key);
    }
    printf("===\n");
}

void main()
{
}