#include "ReadFile.h"
#include "Piece.h"

#include <iostream>

void initializeBoard(Piece chessBoard[8][8])
{
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            chessBoard[i][j].colour = "0";
            chessBoard[i][j].type = "0";
        }
    }
}

void printBoard(Piece A[8][8])
{
    for (size_t i = 0; i < 8; ++i)
    {
      for (size_t j = 0; j < 8; ++j)
      {
          std::cout << " A[" << i << "][" << j << "] = " << A[i][j].colour << " " << A[i][j].type;
      }
      std::cout << std::endl;
    }
}

int main()
{
    Piece chessBoard[8][8];
    initializeBoard(chessBoard);
    printBoard(chessBoard);
    std::string zmienna = "dupa";
    std::cout << zmienna[0];
    //readFile("Pieces.txt", chessBoard);

    return 0;
}
