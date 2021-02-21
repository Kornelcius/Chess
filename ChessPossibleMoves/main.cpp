#include "ReadFile.h"

#include <iostream>

void initializeBoard(int chessBoard[8][8])
{
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            chessBoard[i][j] = 0;
        }
    }
    //return &chessBoard[0][0];
}
void printBoard(int *A, size_t width, size_t height)
{
    for (size_t i = 0; i < height; ++i)
    {
      for (size_t j = 0; j < width; ++j)
      {
          std::cout << " A[" << i << "][" << j << "] = " << A[i * width + j];
      }
      std::cout << std::endl;
    }
}

int main()
{
    int chessBoard[8][8];
    initializeBoard(chessBoard);
    printBoard(&chessBoard[0][0], 8, 8);
    readFile("Pieces.txt");
}
