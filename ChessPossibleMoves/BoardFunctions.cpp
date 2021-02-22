#include "Piece.h"
#include <iostream>

void initializeBoard(Piece chessBoard[8][8])
{
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            chessBoard[i][j].colour = NULL;
            chessBoard[i][j].type = "";
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