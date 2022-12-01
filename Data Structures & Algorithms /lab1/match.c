#include "match.h"

#include <stdlib.h>
#include <stdio.h>

struct Match* getMatch()
{
  struct Match* ret = (struct Match*)malloc(sizeof(struct Match));
  ret->player1 = -1;
  ret->player2 = -1;
  ret->winner = -1;
  ret->prevMatch1 = NULL;
  ret->prevMatch2 = NULL;
  return ret;
}

int assignPlayer1(struct Match* match, struct Match* prev, int pno)
{
  if(pno > 0 && match->player1 == -1)
  {
    if(prev == NULL || pno == prev->winner)
    {
      match->prevMatch1 = prev;
      match->player1 = pno;
      return 1;
    }
    else
      return 0;
  }
  else
    return 0;
  return 1;
}


int assignPlayer2(struct Match* match, struct Match* prev, int pno)
{
  if(pno > 0 && match->player2 == -1)
  {
    if(prev == NULL || pno == prev->winner)
    {
      match->prevMatch2 = prev;
      match->player2 = pno;
      return 1;
    }
    else
      return 0;
  }
  else
    return 0;
  return 1;
}

int assignWinner(struct Match *match, int pno)
{
  if(match->player1 <= 0 || match->player2 <= 0)
    return 0;
  if(pno != match->player1 && pno != match->player2)
    return 0;
  match->winner = pno;
  return 1;
}

void printTournament(struct Match *match)
{

// Print tournament details of match 1
// Print tournament details of match 2

// Check if the match info is complete

// Print the names of players and who won the match.

}
