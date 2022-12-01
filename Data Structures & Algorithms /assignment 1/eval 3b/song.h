#ifndef SONG_H
#define SONG_H
#include<stdlib.h>

#include<stdlib.h>

struct Song
{
    struct Song* next;
    char * name;
    char * artist;
    float duration;
};

typedef struct Song* sg ; 

sg makeSong(char* name, char* artist, float duration);

#endif
