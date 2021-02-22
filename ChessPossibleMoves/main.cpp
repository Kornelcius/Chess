#include "ReadFile.h"
#include "Piece.h"
#include "BoardFunctions.h"

#include <iostream>

int main()
{
    Piece chessBoard[8][8];
    initializeBoard(chessBoard);
    printBoard(chessBoard);
    readFile("Pieces.txt", chessBoard);

    return 0;
}
