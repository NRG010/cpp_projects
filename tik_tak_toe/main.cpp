#include <iostream>
#include <vector>

int main() {
  char gameBoard[3][3];
  int posX, posY;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      gameBoard[i][j] = ' ';
    }
  }

  char inputChar = 'X';
  char isWin = ' ';

  while (isWin != inputChar) {

    for (int i = 0; i < 3; ++i) {
      std::cout << "| ";
      for (int j = 0; j < 3; ++j) {
        std::cout << gameBoard[i][j] << " | ";
      }
      std::cout << '\n';
    }

    std::cout << "Enter the position of input: ";
    std::cin >> posX;
    std::cin >> posY;

    gameBoard[posX][posY] = 'X';

    // For cross win.
    if (((gameBoard[0][0] == inputChar || gameBoard[0][2] == inputChar) &&
         gameBoard[1][1] == inputChar &&
         (gameBoard[2][2] == inputChar || gameBoard[2][0] == inputChar))) {
      isWin = inputChar;
    }

    // For horizantal win.
    for (int i = 0, n = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (gameBoard[i][j] == inputChar) {
          ++n;
        }
      }
      if (n == 3) {
        isWin = inputChar;
        break;
      } else {
        n = 0;
      }
    }

    // For vertical win.
    for (int i = 0, n = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (gameBoard[j][i] == inputChar) {
          ++n;
        }
      }
      if (n == 3) {
        isWin = inputChar;
        break;
      } else {
        n = 0;
      }
    }
  }

  std::cout << isWin << std::endl;
  return 0;
}
