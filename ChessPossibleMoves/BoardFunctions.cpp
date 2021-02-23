#include "Piece.h"
#include "ReadFile.h"
#include "BoardFunctions.h"
#include <iostream>

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

std::vector<Position> getAllMoves(int x, int y)
{
    std::string pieceType = ChessBoard[x][y].type;
    getAllMovesForType(x, y, pieceType);
}

std::vector<Position> getAllMovesForType(int x, int y, std::string type)
{
    std::vector<Position> result;

    if (type == "King")
    {
       result = getAllMovesForKing(x, y);
    }
    else if (type == "Queen")
    {
        getAllMovesForQueen(x, y);
    }
    else if (type == "Rook")
    {
        getAllMovesForRook(x, y);
    }
    else if (type == "Bishop")
    {
        getAllMovesForBishop(x, y);
    }
    else if (type == "Knight")
    {
        getAllMovesForKnight(x, y);
    }
    else if (type == "Pawn")
    {
        getAllMovesForPawn(x, y);
    }

    return result;
}

std::vector<Position> getAllMovesForKing(int x, int y)
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

   return allMoves;
}

void getAllMovesForQueen(int x, int y)
{
    std::vector<Position> allMoves;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            bool validBorders = (i >= 0 && i <= 7) && (j >= 0 && j <= 7);
            bool samePosition = (i == x && j == y);
            bool getPos = validBorders && !samePosition;
            if (getPos) {
                allMoves.push_back({ i, j });
            }
        }
    }
}

void getAllMovesForRook(int x, int y)
{
    std::vector<Position> allMoves;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            bool validBorders = (i >= 0 && i <= 7) && (j >= 0 && j <= 7);
            bool samePosition = (i == x && j == y);
            bool getPos = validBorders && !samePosition;
            if (getPos) {
                allMoves.push_back({ i, j });
            }
        }
    }
}

void getAllMovesForBishop(int x, int y)
{
    std::vector<Position> allMoves;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            bool validBorders = (i >= 0 && i <= 7) && (j >= 0 && j <= 7);
            bool samePosition = (i == x && j == y);
            bool getPos = validBorders && !samePosition;
            if (getPos) {
                allMoves.push_back({ i, j });
            }
        }
    }
}

void getAllMovesForKnight(int x, int y)
{
    std::vector<Position> allMoves;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            bool validBorders = (i >= 0 && i <= 7) && (j >= 0 && j <= 7);
            bool samePosition = (i == x && j == y);
            bool getPos = validBorders && !samePosition;
            if (getPos) {
                allMoves.push_back({ i, j });
            }
        }
    }
}

void getAllMovesForPawn(int x, int y)
{
    std::vector<Position> allMoves;

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            bool validBorders = (i >= 0 && i <= 7) && (j >= 0 && j <= 7);
            bool samePosition = (i == x && j == y);
            bool getPos = validBorders && !samePosition;
            if (getPos) {
                allMoves.push_back({ i, j });
            }
        }
    }
}