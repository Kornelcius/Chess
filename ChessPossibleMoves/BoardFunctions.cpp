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

std::vector<Position> getMoves(int x, int y)
{
    std::string pieceType = ChessBoard[x][y].type;
    std::vector<Position> allMoves = getMovesForType(x, y, pieceType);
    return allMoves;
}

std::vector<Position> getMovesForType(int x, int y, std::string type)
{
    std::vector<Position> result;

    if (type == "King")
    {
       result = getMovesForKing(x, y);
    }
    else if (type == "Queen")
    {
       result = getMovesForQueen(x, y);
    }
    else if (type == "Rook")
    {
       result = getMovesForRook(x, y);
    }
    else if (type == "Bishop")
    {
       result = getMovesForBishop(x, y);
    }
    else if (type == "Knight")
    {
       result = getMovesForKnight(x, y);
    }
    else if (type == "Pawn")
    {
       result = getMovesForPawn(x, y);
    }

    return result;
}

std::vector<Position> getMovesForKing(int x, int y)
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

std::vector<Position> getMovesForQueen(int x, int y)
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

    return allMoves;
}

std::vector<Position> getMovesForRook(int x, int y)
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

    return allMoves;
}

std::vector<Position> getMovesForBishop(int x, int y)
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

    return allMoves;
}

std::vector<Position> getMovesForKnight(int x, int y)
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

    return allMoves;
}

std::vector<Position> getMovesForPawn(int x, int y)
{
    std::vector<Position> allMoves{};
    char colour = ChessBoard[x][y].colour;
    int xPos;
    int yPos;

    if (colour == 'w') 
    {
        //check forward
        xPos = x;
        yPos = y + 1;
        bool validBorders = ( yPos <= 7 && yPos >= 0);
        if (validBorders) {
            bool forwardBlocked = ChessBoard[xPos][yPos].pieceIsPresent;
            if (!forwardBlocked) {
                allMoves.push_back({ xPos, yPos });
            }
            //capture check
            xPos = x + 1;
            bool canCapture = (ChessBoard[xPos][yPos].pieceIsPresent && ChessBoard[xPos][yPos].colour == 'b');
            if (canCapture)
            {
                allMoves.push_back({ xPos, yPos });
            }
            xPos = x - 1;
            bool canCapture2 = (ChessBoard[xPos][yPos].pieceIsPresent && ChessBoard[xPos][yPos].colour == 'b');
            if (canCapture2)
            {
                allMoves.push_back({ xPos, yPos });
            }
        }
       

    }
    else if (colour == 'b') {
        xPos = x;
        yPos = y - 1;
        bool validBorders = (yPos >= 0);
        bool forwardBlocked = ChessBoard[xPos][yPos].pieceIsPresent;
        if (validBorders && !forwardBlocked) {
            allMoves.push_back({ xPos, yPos });
        }
    }
    
    return allMoves;
}

void printPositionInChessBoardCoordinates(Position pos)
{
    char x;
    int y = pos.y;

    switch (pos.x)
    {
    case 0:
        x = 'A';
        break;
    case 1:
        x = 'B';
        break;
    case 2:
        x = 'C';
        break;
    case 3:
        x = 'D';
        break;
    case 4:
        x = 'E';
        break;
    case 5:
        x = 'F';
        break;
    case 6:
        x = 'G';
        break;
    case 7:
        x = 'H';
        break;
    default:
        x = NULL;
        break;
    }
    std::cout << x << y + 1 << std::endl;
}