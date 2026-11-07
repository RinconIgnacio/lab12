#include "dungeon_game.h"
#include "dungeon.h"

Dungeon::Dungeon() : Game("Dungeon"), m_times_played(0) {}

void Dungeon::play() {
  int score = play_dungeon();
  set_score(score);
  m_times_played++;
}

int Dungeon::times_played() const {
  return m_times_played;
}
