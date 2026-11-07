#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
public:
  explicit Game(std::string title);
  ~Game();

  const std::string &title() const;
  int last_score() const;
  void play();

protected:
  void set_score(int score);
  bool ask_play_again() const;

private:
  std::string m_title;
  int m_last_score;
};

#endif

