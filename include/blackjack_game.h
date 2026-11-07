#ifndef ARCADE_BLACKJACK_GAME_H
#define ARCADE_BLACKJACK_GAME_H

#include "game.h"

class Blackjack : public Game {
public:
  Blackjack();
  void play();
  int times_played() const;

private:
  int m_times_played;
};

#endif // ARCADE_BLACKJACK_GAME_H
