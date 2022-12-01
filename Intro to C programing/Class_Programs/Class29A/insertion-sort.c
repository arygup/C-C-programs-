#include <stdio.h> //sir's code

typedef struct node_rec {      // Two equivalent types: "struct node" is equivalent to "Node"
    int key;
    struct node_rec *next;
    // Node *next;
} Node;

Node *head = NULL;

Node *allocateNode()
{
    return (Node *) malloc(sizeof(Node));
}

void freeNode(Node *node)
{
    free(node);
}

// do insertion so that the list is sorted
void insertNode(int key)
{

    pnode->next = newnode;
    newnode->next = cnode;
}

void deleteNode(int key)
{
    Node *prevnode = NULL;

    for(Node *cnode = head; cnode != NULL; ) {
        if(cnode->key == key) { 
            // Case 1: key is found in the first node of the list;
            if(prevnode == NULL) {
                head = cnode->next;
                freeNode(cnode);
                return;
            }
            // Case 2
            prevnode->next = cnode->next; 
            freeNode(cnode);
            return;
        }
        prevnode = cnode; 
        cnode = cnode->next;
    }
}

Node *searchNode(int key)
{
    for(Node *cnode = head; cnode != NULL; cnode = cnode->next) {
        if(cnode->key == key) 
            return cnode;
    }
    return NULL;
}

main()
{

}