#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H

#include "game.h"

class Hangman : public Game {
public:
  Hangman();

  void play();
  int times_played() const;

private:
  int m_times_played;
};

#endif

