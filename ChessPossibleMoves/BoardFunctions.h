#pragma once
#include "Piece.h"
#include <vector>

extern Piece ChessBoard[8][8];
void initializeBoard();
void printBoard();
Position chooseFigure();
std::vector<Position> getMoves(int x, int y);
std::vector<Position> getMovesForType(int x, int y, std::string type);
std::vector<Position> getMovesForKing(int x, int y);
std::vector<Position> getMovesForQueen(int x, int y);
std::vector<Position> getMovesForRook(int x, int y);
std::vector<Position> getMovesForBishop(int x, int y);
std::vector<Position> getMovesForKnight(int x, int y);
std::vector<Position> getMovesForPawn(int x, int y);