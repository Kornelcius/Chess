#pragma once
#include "Piece.h"
#include <string>


void readFile(std::string fileName, Piece tablica[8][8]);
void switchDependingOnPieceColour(char colour);
void switchDependingOnPieceType(char type);
void switchDependingOnPiecePosition(char x, char y);
