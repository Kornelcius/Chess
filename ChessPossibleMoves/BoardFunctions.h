#pragma once
#include "Piece.h"
#include <vector>

extern Piece ChessBoard[8][8];
void initializeBoard();
void printBoard();
Position chooseFigure();
std::vector<Position> getAllMoves(int x, int y);
std::vector<Position> getAllMovesForType(int x, int y, std::string type);
std::vector<Position> getAllMovesForKing(int x, int y);
std::vector<Position> getAllMovesForQueen(int x, int y);
std::vector<Position> getAllMovesForRook(int x, int y);
std::vector<Position> getAllMovesForBishop(int x, int y);
std::vector<Position> getAllMovesForKnight(int x, int y);
std::vector<Position> getAllMovesForPawn(int x, int y);