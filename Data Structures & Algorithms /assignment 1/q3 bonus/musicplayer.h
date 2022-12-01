#ifndef _MY_DLL_H
#define _MY_DLL_H
#include"song.h"
#include<stdlib.h>

struct MusicPlayer
{
    sg root;
    sg tail;
    int size;
    sg current;
};

typedef struct MusicPlayer* mp;

mp createMusicPlayer();
int addSongToQueue(mp p1, sg s);
int removeSongFromQueue(mp p1, int i);
int playSong(mp p1);
sg getCurrentSong(mp p1);


#endif