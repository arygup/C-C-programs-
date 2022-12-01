#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAME_SIZE 20

typedef struct sr {
    char *name;
    //char name[30];
    int marks;
    struct sr *next; // student_record *next;
} student_record;

student_record *head = NULL, *tail = NULL;

void readStudentDB(FILE *fp)
{
    char tempname[MAXNAME_SIZE];
    int marks;
    student_record *srecord, temprecord;

    // temprecord.name

    while(fscanf(fp, "%s", tempname) != EOF) {
        fscanf(fp, "%d", &marks);
        srecord = (student_record *) malloc(sizeof(student_record));
        srecord->name = (char *) malloc(strlen(tempname)+1);  // (*srecord).name 
        strcpy(srecord->name, tempname);
        srecord->marks = marks;
        srecord->next = NULL;

        if(head == NULL) {
            head = srecord;
            tail = srecord;
            continue;
        }
        tail->next = srecord;
        tail = srecord; 
    }
}

void printStudentDB()
{
    printf("=====\n");
    for(student_record *currnode = head; currnode!=NULL; currnode = currnode->next) {
        printf("%s\t\t%d\n", currnode->name, currnode->marks);
    }
    printf("=====\n");
}

student_record *searchDB(char *name)
{
    for(student_record *currnode = head; currnode!=NULL; currnode = currnode->next) {
        if(strcmp(name, currnode->name) == 0) 
            return currnode;
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char searchkey[100];
    student_record *record;

    fp = fopen(argv[1], "r");

    readStudentDB(fp);
    printStudentDB();
    while(1) {
        printf("> ");
        scanf("%s", searchkey);
        if(strcmp(searchkey, "quit") == 0) 
            break;
        record = searchDB(searchkey);

        if(record == NULL) 
            printf("%s not found in the database\n", searchkey);
        else
            printf("%s\t\t%d\n", record->name, record->marks);
    }
    fclose(fp);
    return 0;
}