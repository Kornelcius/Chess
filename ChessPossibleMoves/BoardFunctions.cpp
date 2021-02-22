#include "Piece.h"
#include "ReadFile.h"
#include "BoardFunctions.h"
#include <iostream>
#include <vector>

void initializeBoard()
{
    for (auto i = 0; i < 8; i++) {
        for (auto j = 0; j < 8; j++) {
            ChessBoard[i][j].colour = NULL;
            ChessBoard[i][j].type = "";
        }
    }
}

void printBoard()
{
    for (size_t i = 0; i < 8; ++i)
    {
        for (size_t j = 0; j < 8; ++j)
        {
            std::cout << " A[" << i << "][" << j << "] = " << ChessBoard[i][j].colour << " " << ChessBoard[i][j].type;
        }
        std::cout << std::endl;
    }
}

Position chooseFigure()
{
    char coordinate;
    std::cout << "Type x coordinate (A - H): " << std::endl;
    std::cin >> coordinate;
    int x = getPieceXCoordinate(coordinate);
    std::cout << "Type y coordinate (1 - 8): " << std::endl;
    std::cin >> coordinate;
    int y = getPieceYCoordinate(coordinate);

    if (!ChessBoard[x][y].pieceIsPresent){
        std::cout << "Coordinate invalid" << std::endl;
        return {};
    }

    Position result;
    result.x = x;
    result.y = y;
    result.isValid = true;

    return result;
}

void getAllMoves(int x, int y)
{
    std::string pieceType = ChessBoard[x][y].type;
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
            bool validBorders = (i >= 0 && i <= 7) && (j >= 0 && j <= 7);
            bool samePosition = (i == x && j == y);
            bool getPos = validBorders && !samePosition;
            if (getPos) {
                allMoves.push_back({i, j});
            }
        }
    }

   for (auto i : allMoves)
    {
        std::cout << i.x << i.y << std::endl;
    }



}

//bool validPosition(int x, int y);