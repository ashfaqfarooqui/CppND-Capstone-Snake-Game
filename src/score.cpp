#include "score.h"
#include "player.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

Score::Score() { readFromFile(); }

void Score::addPlayerScore(Player p) { _players.push_back(p); }

void Score::filterTopFive() { return; }
void Score::sortPlayers() {
  sort(_players.begin(), _players.end(),
       [](Player p1, Player p2) { return p1.getScore() > p2.getScore(); });
}
void Score::printTopFive() {
  int top;
  if (_players.size() > 5) {
    top = 5;
  } else {
    top = _players.size();
  }
  sortPlayers();

  for (int i = 0; i < top; i++) {
    std::cout << _players[i].getName() << " " << _players[i].getScore() << "\n";
  }
}
bool Score::isNewHighest(int s) {
  if (s > getHighest().getScore()) {
    return true;
  } else
    return false;
}

Player Score::getHighest() {
  int high = 0;
  Player highestPlayer;
  for (auto p : _players) {
    if (p.getScore() > high) {
      high = p.getScore();
      highestPlayer = p;
    }
  }
  return highestPlayer;
}
void Score::printHighest() {
  Player highestPlayer = getHighest();

  std::cout << highestPlayer.getName() << " => " << highestPlayer.getScore()
            << '\n';
}

void Score::writeToFile() {
  std::ofstream out_file;
  out_file.open("score.txt");
  int top;
  if (_players.size() > 5) {
    top = 5;
  } else {
    top = _players.size();
  }
  sortPlayers();

  for (int i = 0; i < top; i++) {

    out_file << _players[i].getName() << " " << _players[i].getScore() << "\n";
  }
}

void Score::readFromFile() {
  std::string line;
  std::ifstream myfile("score.txt");
  std::string player;
  int s;
  std::vector<Player> players;
  if (myfile.is_open()) {
    while (getline(myfile, line)) {
      std::istringstream lineStream(line);
      lineStream >> player >> s;
      _players.push_back(Player(player, s));
    }
    myfile.close();
  }
}
