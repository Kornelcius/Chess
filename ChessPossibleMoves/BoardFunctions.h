#pragma once
#include "Piece.h"

extern Piece ChessBoard[8][8];
void initializeBoard();
void printBoard();
Position chooseFigure();
void getAllMoves(int x, int y);
void getAllMovesForType(int x, int y, std::string type);
void getAllMovesForKing(int x, int y);
void getAllMovesForQueen(int x, int y);
void getAllMovesForRook(int x, int y);
void getAllMovesForBishop(int x, int y);
void getAllMovesForKnight(int x, int y);
void getAllMovesForPawn(int x, int y);