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

  bool hasMoney() {
    return depositedMoney != 0;
  }
};

class Game {
  public:
    Player player;
    Game() {
      std::cout << "Welcome to Number Guessing Casino!" << std::endl;
      std::cout << "Please enter the amount of money you want to deposit: ";
      std::cin >> player.depositedMoney;
      playGame();
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
      }
    } 

    void askToContinue() {
      if(player.hasMoney()) {
        std::cout << "Do you want to continue? [Y/N]: ";
        std::cin >> player.continueGame;
        player.continueGame = toupper(player.continueGame);
        if(player.continueGame == 'N') {
          sayGoodBye();
          return;
        }
        playGame();
      } else {
        std::cout << "It looks like you ran out of money." << std::endl;
        sayGoodBye();
        return;
      }
    }

    void askForGuess() {
      std::cout << "Pick a number [1-10]: ";
      std::cin >> player.guess;
      if(!validGuessInput(player.guess)) {
        std::cout << "Invalid input." << std::endl;
        std::cout << "Please enter a number between [1-10]" << std::endl;
        askForGuess();
      }
    }

    void playGame() {
      askForBet();
      askForGuess();
      determinWinLose();
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
        } else {
          std::cout << "Your guess was wrong you lost " << player.betMoney << "$" << std::endl;
          std::cout << "The correct answer was: " << correctGuess << std::endl;
          player.depositedMoney -= player.betMoney;    
        }
        player.displayDepositMoney();
        askToContinue();
      }

      void sayGoodBye() {
        std::cout << "Thanks for playing the game!" << std::endl;
        std::cout << "Good bye! 💚" << std::endl;
      }
};

int main() {
  srand((unsigned) time(NULL));
  Game mainGame;
  return 0;
}