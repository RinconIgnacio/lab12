#include "minesweeper_game.h"
#include "minesweeper.h"

Minesweeper::Minesweeper() : Game("Minesweeper"), m_times_played(0) {}

void Minesweeper::play() {
  int score = play_minesweeper();
  set_score(score);
  m_times_played++;
}

int Minesweeper::times_played() const {
  return m_times_played;
}

