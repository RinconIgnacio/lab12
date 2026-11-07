#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#include "game.h"

class Minesweeper : public Game {
public:
  Minesweeper();

  void play();
  int times_played() const;

private:
  int m_times_played;
};

#endif

