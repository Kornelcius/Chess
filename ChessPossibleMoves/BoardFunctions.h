#pragma once
#include "Piece.h"

void initializeBoard(Piece chessBoard[8][8]);
void printBoard(Piece chessBoard[8][8]);
Position chooseFigure(Piece chessBoard[8][8]);
void getAllMoves(int x, int y, Piece chessBoard[8][8]);
void getAllMovesForType(int x, int y, std::string type);
void getAllMovesForKing(int x, int y);