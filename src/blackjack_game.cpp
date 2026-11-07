#include "blackjack_game.h"
#include "blackjack.h"

Blackjack::Blackjack() : Game("Blackjack"), m_times_played(0) {}

void Blackjack::play() {
  int score = play_blackjack();
  set_score(score);
  m_times_played++;
}

int Blackjack::times_played() const {
  return m_times_played;
}
