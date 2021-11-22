#include "controller.h"
#include "game.h"
#include "player.h"
#include "renderer.h"
#include "score.h"
#include <iostream>
int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  std::string playerName1;
  std::string playerName2;
  std::cout << "enter player1 name: ";
  std::cin >> playerName1;
  std::cout << "enter player2 name: ";
  std::cin >> playerName2;
  std::cout << "\n\n ";
  Player p1(playerName1, 0);

  Player p2(playerName2, 0);
  Score score;
  while (true) {
    Game game(kGridWidth, kGridHeight, &p1, &p2);

    game.Run(controller, renderer, kMsPerFrame);
    //    p.setScore(game.GetScore());
    std::cout << p1.getName() << "   "
              << "Score: " << p1.getScore() << "\n";
    std::cout << p2.getName() << "   "
              << "Score: " << p2.getScore() << "\n";

    if (score.isNewHighest(p1.getScore()) && p1.getScore() > p2.getScore()) {
      std::cout << "new highest for player 1!\n";
    }
    if (score.isNewHighest(p2.getScore()) && p2.getScore() > p1.getScore()) {
      std::cout << "new highest for player 2!\n";
    }
    score.addPlayerScore(p1);
    score.addPlayerScore(p2);
    std::string s;
    std::cout << "do you want to play again? (y/N)?"
              << "\n";
    std::cin >> s;
    if (s == "n")
      break;
  }
  score.printTopFive();
  score.writeToFile();

  std::cout << "Game has terminated successfully!\n";
  return 0;
}
