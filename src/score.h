#ifndef SCORE_H_
#define SCORE_H_

#include "player.h"
#include <map>
#include <vector>

class Score {
public:
  Score();
  void printTopFive();
  void writeToFile();
  void readFromFile();
  void printHighest();
  void addPlayerScore(Player p1);
  bool isNewHighest(int);

private:
  Player getHighest();
  void sortPlayers();
  void filterTopFive();
  std::vector<Player> _players;
};

#endif // SCORE_H_
