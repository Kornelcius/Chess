#include "Piece.h"
#include "ReadFile.h"
#include "BoardFunctions.h"
#include <iostream>
#include <vector>

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

void getAllMoves(int x, int y, Piece chessBoard[8][8])
{
    std::string pieceType = chessBoard[x][y].type;
    getAllMovesForType(x, y, pieceType);
}

void getAllMovesForType(int x, int y, std::string type)
{
    if (type == "King")
    {
        getAllMovesForKing(x, y);
    }
}

void getAllMovesForKing(int x, int y)
{
    std::vector<Position> allMoves;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (!(i == x && j == y)) {

                allMoves.push_back({i, j});
            }
        }
    }

   /* for (auto i : allMoves)
    {
        std::cout << i.x << i.y << std::endl;
    }*/



}