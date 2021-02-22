#include "ReadFile.h"
#include "Piece.h"
#include "BoardFunctions.h"

#include <iostream>

int main()
{
    bool koniec = false;
    Piece chessBoard[8][8];

    while (!koniec) {
        initializeBoard(chessBoard);
        printBoard(chessBoard);
        readFile("Pieces.txt", chessBoard);
        printBoard(chessBoard);
        Position pos = chooseFigure(chessBoard);

        if (!pos.isValid)
        {
            continue;
        }

        std::cout << pos.x << " " << pos.y << std::endl;
        std::cout << chessBoard[pos.x][pos.y].type << std::endl;
        std::cout << chessBoard[pos.x][pos.y].colour << std::endl;
        getAllMoves(pos.x, pos.y, chessBoard);

        char end = NULL;
        std::cout << "Do you want to end? Press 1 to end;" << std::endl;
        std::cin >> end;

        if (end == '1')
        {
            koniec = true;
        }
    }

    //getPossibleMoves(figure);
        //getAllMoves(figure);
        //removeImpossibleMoves(figure);
    //printMoves();

    return 0;
}
