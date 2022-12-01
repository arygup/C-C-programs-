#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "musicplayer.h"
#include "song.h"
mp createMusicPlayer()
{
    mp t = malloc(sizeof(struct MusicPlayer));
    t->root = NULL;
    t->size = -1;
    t->current = NULL;
    return t;
}
int addSongToQueue(mp p1, sg s)
{
    if(p1->root != NULL)
    {
        sg t = p1->root;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = s;
        s->next = NULL;
        p1->size = p1->size + 1;
        return 0;
    }
    if(p1->root == NULL)
    {
        p1->size = 1;
        p1->root = s;
        p1->tail = s;
        return 0;
    }
    return 1;
}
int removeSongFromQueue(mp p1, int i)
{
    if(p1->root == NULL) return 1;

    if(i == 0)
    {
        if(p1->size < 0)
        {
            if(p1->root == NULL) return 1;
            p1->root = NULL; 
            return 0;
        }
        p1->size = p1->size - 1;
        p1->root = p1->root->next;
        return 0;
    }
    sg t1, t2, t = p1->root;
    for (int j = 0; j < i; j++)
    {
        t1 = t;
        t = t->next;
    }
    t2 = t->next;    /// t1 t t2
    t1->next = t2;
    if(t2 == NULL) p1->tail = t2;
    p1->size = p1->size - 1;
    return 0;
}
int playSong(mp p1)
{
    if(p1->root == NULL) return 1;
    p1->current = p1->root;
    p1->root = p1->root->next;
    p1->current->next = NULL;
    p1->size = p1->size - 1;
    return 0;
}
sg getCurrentSong(mp p1)
{
    return p1->current;
}


/*

ADD S1 A1 1.1
ADD S2 A2 2.2
ADD S3 A3 3.3
INSERT S1
INSERT S2
INSERT S3
PLAY
GET
REMOVE 0
PLAY
GET
EXIT

*/