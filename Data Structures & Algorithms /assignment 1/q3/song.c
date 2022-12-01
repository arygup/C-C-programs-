#include<stdlib.h>
#include"song.h"
#include<string.h>


sg makeSong(char* name, char* artist, float duration)
{
    sg t = malloc(sizeof(struct Song));
    t->artist = malloc(strlen(artist) + 1);
    t->name = malloc(strlen(name) + 1);
    t->duration = duration;
    strcpy(t->artist, artist);
    strcpy(t->name, name);
    t->next = NULL;
    return t;
}
