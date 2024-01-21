/**
*
* Solution to course project # <4>
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2023/2024
*
* @author <Yuliyan Palov>
* @idnumber <0MI0600384>
* @compiler <VC>
*
* <Commands for moving to the leff, to the right, upwards, downwards and gameplay>
*
*/

#include "Move commands.h"
#include "Validation.h"
#include "Creating and updating field.h"
#include "PlayersData.h"
#include <iostream>
using namespace std;





const int generate4and8 = 512;
const int numberZero = 0;


//With following functions I initialize the command A (moving left).


void summingTheSameLeftNumbers(int** field, size_t sizeOfField, int currentRow, int currentColl, int currentNumber)
{
	for (int coll = currentColl + 1; coll < sizeOfField; coll++)
	{
		int neighbourNumber = field[currentRow][coll];

		if (neighbourNumber == 0)
		{
			continue;
		}
		else if (neighbourNumber == currentNumber)
		{
			field[currentRow][currentColl] += neighbourNumber;
			field[currentRow][coll] = 0;
			break;
		}
		else
		{
			break;
		}
	}
}

void moveNumber_ToTheLeftSide_OfTheField(int** field, size_t sizeOfField, int currentRow, int currentColl)
{
	for (int coll = 0; coll < currentColl; coll++)
	{
		if (field[currentRow][coll] == 0)
		{
			field[currentRow][coll] = field[currentRow][currentColl];
			field[currentRow][currentColl] = 0;
			break;
		}
	}
}

void sumTheSameNumbers_and_MoveToTheLeftSide(int** field, size_t sizeOfField, int row)
{
	for (int coll = 0; coll < sizeOfField; coll++)
	{
		int number = field[row][coll];

		if (number == 0)
		{
			continue;
		}

		summingTheSameLeftNumbers(field, sizeOfField, row, coll, number);
		moveNumber_ToTheLeftSide_OfTheField(field, sizeOfField, row, coll);
	}
}

void command_A(int** field, size_t sizeOfField)
{
	for (int row = 0; row < sizeOfField; row++)
	{
		sumTheSameNumbers_and_MoveToTheLeftSide(field, sizeOfField, row);
	}
}


//With the following functions I initialize the command D (moving right).


void summingTheSameRightNumbers(int** field, size_t sizeOfField, int currentRow, int currentColl, int currentNumber)
{
	for (int coll = currentColl - 1; coll >= 0; coll--)
	{
		int neighbourNumber = field[currentRow][coll];

		if (neighbourNumber == 0)
		{
			continue;
		}
		else if (neighbourNumber == currentNumber)
		{
			field[currentRow][currentColl] += neighbourNumber;
			field[currentRow][coll] = 0;
			break;
		}
		else
		{
			break;
		}
	}
}

void moveNumber_ToTheRightSide_OfTheField(int** field, size_t sizeOfField, int currentRow, int currentColl)
{
	for (int coll = sizeOfField - 1; coll > currentColl; coll--)
	{
		if (field[currentRow][coll] == 0)
		{
			field[currentRow][coll] = field[currentRow][currentColl];
			field[currentRow][currentColl] = 0;
			break;
		}
	}
}

void sumTheSameNumbers_and_MoveToTheRightSide(int** field, size_t sizeOfField, int row)
{
	for (int coll = sizeOfField - 1; coll >= 0; coll--)
	{
		int number = field[row][coll];

		if (number == 0)
		{
			continue;
		}

		summingTheSameRightNumbers(field, sizeOfField, row, coll, number);
		moveNumber_ToTheRightSide_OfTheField(field, sizeOfField, row, coll);
	}
}

void command_D(int** field, size_t sizeOfField)
{
	for (int row = 0; row < sizeOfField; row++)
	{
		sumTheSameNumbers_and_MoveToTheRightSide(field, sizeOfField, row);
	}
}


//With the following functions I initialize the command W (moving upwards).


void summingTheSameUpperNumbers(int** field, size_t sizeOfField, int currentRow, int currentColl, int currentNumber)
{
	for (int row = currentRow + 1; row < sizeOfField; row++)
	{
		int neighbourNumber = field[row][currentColl];

		if (neighbourNumber == 0)
		{
			continue;
		}
		else if (neighbourNumber == currentNumber)
		{
			field[currentRow][currentColl] += neighbourNumber;
			field[row][currentColl] = 0;
			break;
		}
		else
		{
			break;
		}

	}
}

void moveNumber_ToTheUpperSide_OfTheField(int** field, size_t sizeOfField, int currentRow, int currentColl)
{
	for (int row = 0; row < currentRow; row++)
	{
		if (field[row][currentColl] == 0)
		{
			field[row][currentColl] = field[currentRow][currentColl];
			field[currentRow][currentColl] = 0;
			break;
		}
	}
}

void sumTheSameNumbers_and_MoveToTheUpperSide(int** field, size_t sizeOfField, int coll)
{
	for (int row = 0; row < sizeOfField; row++)
	{
		int number = field[row][coll];

		if (number == 0)
		{
			continue;
		}

		summingTheSameUpperNumbers(field, sizeOfField, row, coll, number);
		moveNumber_ToTheUpperSide_OfTheField(field, sizeOfField, row, coll);
	}
}

void command_W(int** field, size_t sizeOfField)
{
	for (int coll = 0; coll < sizeOfField; coll++)
	{
		sumTheSameNumbers_and_MoveToTheUpperSide(field, sizeOfField, coll);
	}
}


//With the following functions I initialize the command S (moving downwards).


void summingTheSameDownNumbers(int** field, size_t sizeOfField, int currentRow, int currentColl, int currentNumber)
{
	for (int row = currentRow - 1; row >= 0; row--)
	{
		int neighbourNumber = field[row][currentColl];

		if (neighbourNumber == 0)
		{
			continue;
		}
		else if (neighbourNumber == currentNumber)
		{
			field[currentRow][currentColl] += neighbourNumber;
			field[row][currentColl] = 0;
			break;
		}
		else
		{
			break;
		}
	}
}

void moveNumber_ToTheDownSide_OfTheField(int** field, size_t sizeOfField, int currentRow, int currentColl)
{
	for (int row = sizeOfField - 1; row > currentRow; row--)
	{
		if (field[row][currentColl] == 0)
		{
			field[row][currentColl] = field[currentRow][currentColl];
			field[currentRow][currentColl] = 0;
			break;
		}
	}
}

void sumTheSameNumbers_and_MoveToTheDownSide(int** field, size_t sizeOfField, int coll)
{
	for (int row = sizeOfField - 1; row >= 0; row--)
	{
		int number = field[row][coll];

		if (number == 0)
		{
			continue;
		}

		summingTheSameDownNumbers(field, sizeOfField, row, coll, number);
		moveNumber_ToTheDownSide_OfTheField(field, sizeOfField, row, coll);
	}
}

void command_S(int** field, size_t sizeOfField)
{
	for (int coll = 0; coll < sizeOfField; coll++)
	{
		sumTheSameNumbers_and_MoveToTheDownSide(field, sizeOfField, coll);
	}
}



//Now let's build the game


void gameplay(int** field, int sizeOfField, int& score)
{
	//Here we mark the empty boxes with zeroes so in the beggining we fill the field with zeroes.

	printField(field, sizeOfField, numberZero);

	score = 0;

	int randomNumber = randomNumber2or4();
	createRandomNumberOnTheBoard(field, sizeOfField, randomNumber, score);

	while (true)
	{
		if (!(isFieldFullWithoutCombinations(field, sizeOfField)))
		{
			printBoardAndCurrentScore(sizeOfField, field, score);
		}

		char moveCommand = inputCommand();

		switch (moveCommand)
		{
		case 'w':command_W(field, sizeOfField); break;
		case 'a':command_A(field, sizeOfField); break;
		case 's':command_S(field, sizeOfField); break;
		case 'd':command_D(field, sizeOfField); break;
		}

		//Generating bigger number during the game process.
		//I observed the game and I concluded that bigger numbers must start to generate after you have 512 points.

		if (score > generate4and8)
		{
			randomNumber = randomNumber2or4or8();
		}
		else
		{
			randomNumber = randomNumber2or4();
		}
		createRandomNumberOnTheBoard(field, sizeOfField, randomNumber, score);

		//end game

		if (isFieldFullWithoutCombinations(field, sizeOfField))
		{
			cout << "Game over!" << endl;
			cout << "Your score is: " << score << endl;
			break;
		}
	}
}