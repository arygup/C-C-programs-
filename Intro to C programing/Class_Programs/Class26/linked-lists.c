#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAME_SIZE 20

typedef struct sr {
    char *name;
    int marks;
    struct sr *next; // pointer to a student_record datatype.
} student_record;

student_record *head = NULL;

void readStudentDB()
{
    char tempname[MAXNAME_SIZE];
    int marks;
    student_record *srecord;

    while (scanf("%s", tempname) != EOF)
    {
        scanf("%d", &marks);
        //create space for an entire record
        srecord =  (student_record *)malloc(sizeof(student_record));
        //store name at given pointer(name's) location
        srecord->name = malloc(strlen(tempname)+1);
        strcpy(srecord->name, tempname);
        //store marks at int
        srecord->marks = marks;

        srecord->next = head;
        head = srecord;

        // this arrow operator says the same thing as
        // (*srecord).name
        // meaning = gives base address of name.
        // marks are at an offset of 8 from base address of srecord.
    }   
}

void printStudentDB()
{
    printf("===\n");
    for (student_record *currnode = head; currnode != NULL; )
    {
        printf("%s\t\t%d\n", currnode->name, currnode->marks);
    }
    printf("===\n");

}

int main(int argc, char *argv[])
{
    readStudentDB();
    printStudentDB();
    return 0;
}


        