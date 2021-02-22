#include "ReadFile.h"

#include <fstream>
#include <iostream>


void readFile(std::string filePath, Piece tablica[8][8]) 
{
    std::string input;
	std::fstream file;

	file.open(filePath);

    //obs³uga braku bliku
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
      int xCoordinate = getPieceXCoordinate(input[2]);
      int yCoordinate = getPieceYCoordinate(input[3]);

      char pieceColour = getPieceColour(input[0]);
      std::string pieceType = getPieceType(input[1]);

      tablica[xCoordinate][yCoordinate].colour = pieceColour;
      tablica[xCoordinate][yCoordinate].type = pieceType;
      //get piece location in array coordinates - from [0][0] to [7][7]
    }

    std::cout << "Succesful read!" << std::endl;

    file.close();
}

char getPieceColour(char colour)
{
    if (colour != 'b' && colour != 'w') 
    {
      return 0;
    }
    return colour;
}

std::string getPieceType(char type)
{
  std::string result = "";
  int pieceType = type;
  switch (pieceType)
    {
    case 107: //k
        result = "King";
        break;
    case 113: //q
        result = "Queen";
        break;
    case 114: //r
        result = "Rook";
        break;
    case 98: //b
        result = "Bishop";
        break;
    case 110: //n
        result = "Knight";
        break;
    case 112: //p
        result = "Pawn";
        break;
    default:
        std::cout << "Wrong values - ignore" << std::endl;
        break;
    }
  return result;
}

int getPieceXCoordinate(char x)
{
    int result;
    int positionX = x;
    switch (positionX)
    {
    case 65: //A
        result = 0;
        break;
    case 66: //B
        result = 1;
        break;
    case 67: //C
        result = 2;
        break;
    case 68: //D
        result = 3;
        break;
    case 69: //E
        result = 4;
        break;
    case 70: //F
        result = 5;
        break;
    case 71: //G
        result = 6;
        break;
    case 72: //H
        result = 7;
        break;
    default:
        std::cout << "Wrong values - ignore" << std::endl;
        break;
    }
    return result;
}

int getPieceYCoordinate(char y)
{
    int result;
    int positionY = y;
    switch (positionY)
    {
    case 49: //1
        result = 0;
        break;
    case 50: //2
        result = 1;
        break;
    case 51: //3
        result = 2;
        break;
    case 52: //4
        result = 3;
        break;
    case 53: //5
        result = 4;
        break;
    case 54: //6
        result = 5;
        break;
    case 55: //7
        result = 6;
        break;
    case 56: //8
        result = 7;
        break;
    default:
        std::cout << "Wrong values - ignore" << std::endl;
        break;
    }
    return result;
}

