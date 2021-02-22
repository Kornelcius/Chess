#include "Piece.h"
#include "ReadFile.h"
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

void printBoard(Piece chessBoard[8][8])
{
    for (size_t i = 0; i < 8; ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            std::cout << " A[" << i << "][" << j << "] = " << chessBoard[i][j].colour << " " << chessBoard[i][j].type;
        }
        std::cout << std::endl;
    }
}

Position chooseFigure(Piece chessBoard[8][8])
{
    char coordinate;
    std::cout << "Type x coordinate (A - H): " << std::endl;
    std::cin >> coordinate;
    int x = getPieceXCoordinate(coordinate);
    std::cout << "Type y coordinate (1 - 8): " << std::endl;
    std::cin >> coordinate;
    int y = getPieceYCoordinate(coordinate);

    if (!chessBoard[x][y].pieceIsPresent){
        std::cout << "Coordinate invalid" << std::endl;
        return {};
    }

    Position result;
    result.x = x;
    result.y = y;
    result.isValid = true;

    return result;


}