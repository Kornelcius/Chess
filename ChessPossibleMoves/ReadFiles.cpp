#include "ReadFile.h"

#include <fstream>
#include <iostream>


void readFile(std::string filePath, Piece tablica[8][8]) 
{
    std::string input;
	std::fstream file;

	file.open(filePath);

    //obs�uga braku bliku
    if (!file)
    {
      std::cout << "Error cannot open file!" << std::endl;
      return;
    }

    while (getline(file, input))
    {

      if (input.size() != 4) 
      {
        continue;
      }

      std::cout << "line: " << input << std::endl;
      //get piece color
      //get piece type
      switchDependingOnPieceColour(input[0]);
      switchDependingOnPieceType(input[1]);
      switchDependingOnPiecePosition(input[2], input[3]);
      //get piece location in array coordinates - from [0][0] to [7][7]
      
     // std::cout << "input[0]: " << input[0] << std::endl;

    }

    std::cout << "Succesful read!" << std::endl;

    file.close();
}

void switchDependingOnPieceColour(char colour)
{
    if (colour != 'b' && colour != 'w') 
    {
      return;
    }
    std::cout << "Piece colour: " << colour << std::endl;


}
void switchDependingOnPieceType(int type)
{
  std::cout << "Piece type: ";
  switch (type)
    {
    case 107: //k
        std::cout << "King" << std::endl;
        break;
    case 113: //q
        std::cout << "Queen" << std::endl;
        break;
    case 114: //r
        std::cout << "Rook" << std::endl;
        break;
    case 98: //b
        std::cout << "Bishop" << std::endl;
        break;
    case 110: //n
        std::cout << "Knight" << std::endl;
        break;
    case 112: //p
        std::cout << "Pawn" << std::endl;
        break;
    default:
        std::cout << "Wrong values - ignore" << std::endl;
        break;
    }
}

void switchDependingOnPiecePosition(int a, int b)
{
    std::cout << "Piece coordinates: ";
    switch (a)
    {
    case 65: //A
        std::cout << "0" << b - 49 << std::endl; // - 49 means that from ascii b we subtract asci 1, getting proper coordinate
        break;
    case 66: //B
        std::cout << "1" << b - 49 << std::endl;
        break;
    case 67: //C
        std::cout << "2" << b - 49 << std::endl;
        break;
    case 68:  //D
        std::cout << "3" << b - 49 << std::endl;
        break;
    case 69: //E
        std::cout << "4" << b - 49 << std::endl;
        break;
    case 70: //F
        std::cout << "5" << b - 49 << std::endl;
        break;
    case 71: //G
        std::cout << "6" << b - 49 << std::endl;
        break;
    case 72: //H
        std::cout << "7" << b - 49 << std::endl;
        break;
    default:
        std::cout << "Wrong values - ignore" << std::endl;
        break;
    }

}
