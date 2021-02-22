#pragma once
#include "Piece.h"

extern Piece ChessBoard[8][8];
void initializeBoard();
void printBoard();
Position chooseFigure();
void getAllMoves(int x, int y);
void getAllMovesForType(int x, int y, std::string type);
void getAllMovesForKing(int x, int y);