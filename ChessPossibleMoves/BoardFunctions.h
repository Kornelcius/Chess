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
void getAllMovesForQueen(int x, int y);
void getAllMovesForRook(int x, int y);
void getAllMovesForBishop(int x, int y);
void getAllMovesForKnight(int x, int y);
void getAllMovesForPawn(int x, int y);