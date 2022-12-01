#ifndef _MUSICPLAYER_H
#define _MUSICPLAYER_H
#include"song.h"
#include<stdlib.h>
#include"musicplayer.h"
struct User
{
    char* name;
    mp player;
    sg liked;
};
typedef struct User* usr;

usr createUser(char* user);
int removeSongFromQueueUser(usr u, int i);
int  playSongUser(usr u);
sg getCurrentSongUser(usr u);
int addLikedSong(usr u, sg s);
int removeLikedSong(usr u, sg s);
int userCompatibility(usr u1, usr u2);
int addSongToQueueUser(usr u, sg s);
#endif