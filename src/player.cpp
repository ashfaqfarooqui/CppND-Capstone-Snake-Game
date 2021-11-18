#include "player.h"

Player::Player(std::string n) : name(n), score(0) {}
Player::Player(std::string n, int s) : name(n), score(s) {}
Player::Player() : name("nameless"), score(0) {}
std::string Player::getName() { return name; }

int Player::getScore() { return score; }

void Player::setScore(int s) { score = s; }
void Player::incrementScore() { score++; }
