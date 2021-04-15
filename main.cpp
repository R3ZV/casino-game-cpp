#include <iostream>
#include <string>

struct Player {
  int depositedMoney;
  int betMoney;
  int guess;
  char continueGame;

  void displayDepositMoney() {
    std::cout << "Your current deposited money is: " << depositedMoney << std::endl;
  }
};

class Game {
  public:
    Player player;
    Game() {
      std::cout << "Welcome to Number Guessing Casino!" << std::endl;
      std::cout << "Please enter the amount of money you want to deposit: ";
      std::cin >> player.depositedMoney;
      askForBet();
    }

  private:
    // ####### Main Game Functions #######
    void askForBet() {
      std::cout << "Place your bet: ";
      std::cin >> player.betMoney;
      if(player.betMoney > player.depositedMoney) {
        std::cout << "You dont't have enough money in your deposit" << std::endl;
        player.displayDepositMoney();
        askForBet();
      } else {
        playGame();
      }
    } 

    void askToContinue() {
      std::cout << "Do you want to continue? [Y/N]: ";
      std::cin >> player.continueGame;
      player.continueGame = toupper(player.continueGame);
      if(player.continueGame == 'N') {
        return;
      }
      askForBet();
    }

    void playGame() {
      std::cout << "Pick a number [1-10]: ";
      std::cin >> player.guess;
      if(validGuessInput(player.guess)) {
        determinWinLose();
      }
    }

    private:
      // ####### Utilities Functions #######
      int generateRandomNumber() {
        int number = rand() % 10 + 1;
        return number;
      }

      bool validGuessInput(int guess) {
        if(guess <= 0 || guess > 10) {
          return false;
        }
        return true;
      }

      void determinWinLose() {
        int correctGuess = generateRandomNumber();
        if(player.guess == correctGuess) {
          player.depositedMoney += (player.betMoney * 10);
          std::cout << "Your guess was correct!" << std::endl;
          player.displayDepositMoney();
          askToContinue();
        } else {
          std::cout << "Your guess was wrong you lost " << player.betMoney << "$" << std::endl;
          std::cout << "The correct answer was: " << correctGuess << std::endl;
          player.depositedMoney -= player.betMoney;
          player.displayDepositMoney();
          askToContinue();
        }
      }
};

int main() {
  srand((unsigned) time(NULL));
  Game mainGame;
  // std::cout << "Do you want to continue? [Y/N]: ";
  return 0;
}