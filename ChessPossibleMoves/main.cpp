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
    printBoard(chessBoard);
    Position pos = chooseFigure(chessBoard);
    std::cout << pos.x << " " << pos.y << std::endl;
    std::cout << chessBoard[pos.x][pos.y].type << std::endl;
    std::cout << chessBoard[pos.x][pos.y].colour << std::endl;

    //getPossibleMoves(figure);
        //getAllMoves(figure);
        //removeImpossibleMoves(figure);
    //printMoves();

    return 0;
}
