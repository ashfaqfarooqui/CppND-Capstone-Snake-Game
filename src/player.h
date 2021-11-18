#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
class Player {
public:
  Player(std::string n);
  Player(std::string n, int s);
  Player();
  std::string getName();
  int getScore();
  void setScore(int s);
  void incrementScore();

private:
  std::string name;
  int score;
};

#endif // PLAYER_H_
