#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 10
#define MAXNAME_SIZE 20


typedef struct {
    char *name;
    int marks;
} student_record;

student_record student_db[MAX_STUDENTS]; //global variable

void readStudentsDB()
{
    char tempname[MAXNAME_SIZE];

    for (int i = 0; i <MAX_STUDENTS; i++)
    {
        scanf("%s %d", tempname, &student_db[i].marks);
        student_db[i].name = (char *)malloc(strlen(tempname)+1);
        strcpy(student_db[i].name, tempname);
    }
}
void printStudentsDB()
{
    printf("===\n");

    for (int i = 0; i <MAX_STUDENTS; i++)
    {
        printf("%s\t\t%d\n", student_db[i].name, student_db[i].marks);
    }
    printf("===\n");
}

int main()
{
    readStudentsDB();
    printStudentsDB();

    return 0;
}


// this one prints 10 names.
// if u give less number of names itll print the last name
// enough times to print 10 names.
