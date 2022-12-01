#include<stdio.h>
#include<stdlib.h>
#include"user.h"
#include<string.h>
#include <assert.h>

usr createUser(char* user)
{
    usr t = malloc(sizeof(struct User));
    t->name = user;
    t->player = createMusicPlayer();
    t->liked = NULL;
    return t;
}
int removeSongFromQueueUser(usr u, int i)
{
    return removeSongFromQueue(u->player, i);
}
int  playSongUser(usr u)
{
    return playSong(u->player);
}
sg getCurrentSongUser(usr u)
{
    return getCurrentSong(u->player);
}
int addSongToQueueUser(usr u, sg s)
{
    return addSongToQueue(u->player, s);
}
int addLikedSong(usr u, sg s0)   //
{
    assert(s0 != NULL);
    sg s = makeSong(s0->name, s0->artist, s0->duration);
    if(u->liked != NULL)
    {
        sg t = u->liked;
        while (t->next != NULL)
        {
            t = t->next;
        }
        t->next = s;
        s->next = NULL;
        return 0;
    }
    if(u->liked == NULL)
    {
        u->liked = s;
        s->next = NULL;
        return 0;
    }
    return 1;
}
int removeLikedSong(usr u, sg s)
{
    if(u->liked == NULL) return 1;
    sg t = u->liked;
    if(t == s)
    {
        u->liked = t->next;
        return 0;
    }
    while (t->next != NULL)
    {
        if(t->next == s)
        {
            t->next = s->next;
            return 0;
        }
        t = t->next;
    }
    return 1;
}
int userCompatibility(usr u1, usr u2)
{
    int x = 0;
    sg t1 = u1->liked;
    sg t2 = u2->liked;
    while (t1->next != NULL)
    {
        while(t2->next != NULL)
        {
            if(t1->name == t2->name && t1->artist == t2->artist)x++;
            t2 = t2->next;
        }
        t1 = t1->next;
        t2 = u2->liked;
    }
    return x;
}