#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR_LEN 100

/*
These form the different nodes in linked lists.
*/
typedef struct LinkedListNode
{
    char* datastr;
    int datanum;
    struct LinkedListNode* next;
} Node;


/*
This is the initial value of head pointer pointing to NULL.
When we declare several nodes, the head pointer points to the very first node.
While the last node stores the pointer to NULL.
*/
Node* head = NULL;


void readLinkedList()
{
    char tempstr[MAX_STR_LEN];
    int tempnum;
    // tempnode points to the current node in which data is going to be stored.
    Node* tempnode;

    while (scanf("%s", tempstr) != EOF)
    {
        scanf("%d", &tempnum);
        // Allocating memory to tempnode.
        tempnode = (Node*) malloc(sizeof(Node));
        // Allocating memory to char pointer inside the Node structure to be able to store strings.
        tempnode->datastr = (char*) malloc(strlen(tempstr) + 1);
        strcpy(tempnode->datastr, tempstr);
        tempnode->datanum = tempnum;
        // Making the current Node point to older head node.
        tempnode->next = head;
        // Making the head node point to the new node.
        head = tempnode;
    }
}

void printLinkedList()
{
    printf("========================================================\n");
    for (Node* currnode = head; currnode != NULL; currnode = currnode->next)
    {
        printf("%-10s%10d\n", currnode->datastr, currnode->datanum);
    }
    printf("========================================================\n");
}


int main()
{
    readLinkedList();
    printLinkedList();

    return 0;
}
