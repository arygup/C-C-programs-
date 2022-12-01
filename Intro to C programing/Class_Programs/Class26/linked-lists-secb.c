#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXNAME_SIZE 20

typedef struct sr {
    char *name;
   // char name[30];
    int marks;
    struct sr *next; // student_record *next;
} student_record;

student_record *head = NULL;

void readStudentDB(FILE *fp)
{
    char tempname[MAXNAME_SIZE];
    int marks;
    student_record *srecord, temprecord;

    // temprecord.name

    while(fscanf(fp, "%s", tempname) != EOF) {
        fscanf(fp, "%d", &marks);

        srecord = (student_record *) malloc(sizeof(student_record));
        srecord->name = (char *) malloc(strlen(tempname)+1);   // Get your apartment allocated    
        strcpy(srecord->name, tempname);
        srecord->marks = marks; 

        srecord->next = head;
        head = srecord;
    }
}

void printStudentDB()
{
    printf("====\n");
    for(student_record *currnode = head; currnode!= NULL; currnode = currnode->next){
        printf("%s\t\t%d\n", currnode->name, currnode->marks);
    }
    printf("====\n");
}

student_record *searchDB(char *searchkey)
{
    for(student_record *currnode = head; currnode!= NULL; currnode = currnode->next){
        if(strcmp(currnode->name, searchkey) == 0) {
            return currnode;
        }
    }
    return NULL;
}

int main(int argc, char *argv[])
{
   student_record *record;
   char searchkey[100];
   FILE *fp;

    fp = fopen(argv[1], "r");
    readStudentDB(fp);
 
    while(1) {
        printf("> ");
        scanf("%s", searchkey);
        if(strcmp(searchkey, "quit") == 0) {
            break;
        }
        if(strcmp(searchkey, "ls") == 0) {
            printStudentDB();
            continue;
        }
        record = searchDB(searchkey);
        if(record == NULL) {
            printf("%s not found in the database\n", searchkey);
            continue;
        }
        printf("%s\t\t%d\n", record->name, record->marks);
    }

    fclose(fp);
    return 0;
}