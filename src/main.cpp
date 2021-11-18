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
  std::string playerName;
  std::cout << "enter player name: ";
  std::cin >> playerName;
  Player p(playerName, 0);
  Score score;
  while (true) {
    Game game(kGridWidth, kGridHeight);
    game.Run(controller, renderer, kMsPerFrame);
    p.setScore(game.GetScore());
    std::cout << p.getName() << "Score: " << p.getScore() << "\n";
    std::cout << "Size: " << game.GetSize() << "\n";
    std::cout << "do you want to play again? (y/N)?"
              << "\n";
    if (score.isNewHighest(p.getScore())) {
      std::cout << "new highest!\n";
    }
    score.addPlayerScore(p);
    std::string s;
    std::cin >> s;
    if (s == "n")
      break;
  }
  score.printTopFive();
  score.writeToFile();

  std::cout << "Game has terminated successfully!\n";
  return 0;
}
