#include "ReadFile.h"
#include "Piece.h"
#include "BoardFunctions.h"

#include <iostream>

Piece ChessBoard[8][8];

int main()
{
    bool koniec = false;

    while (!koniec) {
        initializeBoard();
        printBoard();
        readFile("Pieces.txt");
        printBoard();
        Position pos = chooseFigure();

        if (!pos.isValid)
        {
            continue;
        }

        std::cout << pos.x << " " << pos.y << std::endl;
        std::cout << ChessBoard[pos.x][pos.y].type << std::endl;
        std::cout << ChessBoard[pos.x][pos.y].colour << std::endl;
        std::vector<Position> allMoves = getAllMoves(pos.x, pos.y);

        for (auto i : allMoves)
        {
            std::cout << i.x << i.y << std::endl;
        }

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
