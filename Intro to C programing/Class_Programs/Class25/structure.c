#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 10
#define MAXNAME_SIZE 20


struct student_record
{
    char *name;
    int marks;
};

void displayRecord(struct student_record s)
{
    printf("===\n");
    printf("%s ---> %d\n", s.name, s.marks);
    printf("===\n");
}

void manageRecord()
{
    struct student_record s1;
    char tempname[MAXNAME_SIZE];

    printf("Student:");
    scanf("%s %d", tempname, &s1.marks);

    s1.name = (char *)malloc(strlen(tempname)+1);
    strcpy(s1.name, tempname);

    displayRecord(s1);
    free(s1.name);
}

int main()
{
    manageRecord();

    //displayRecord(s1);
}
