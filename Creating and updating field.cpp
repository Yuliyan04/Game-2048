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
* <Generating and updating the field>
*
*/

#include "Creating and updating field.h"
#include "Helping functions.h"
#include <iostream>
using namespace std;




const int space = 4;


void printField(int** field, size_t sizeOfField, int number)
{
	for (int i = 0; i < sizeOfField; i++)
	{
		field[i] = new int[sizeOfField];

		for (int j = 0; j < sizeOfField; j++)
		{
			field[i][j] = number;
		}
	}
}


void printSpace(int lenghtOfValue)
{
	//inputSizeOfField - needed spaces = 4
	int spaces = space - lenghtOfValue;

	for (int i = 0; i < spaces; i++)
	{
		cout << " ";
	}
}

void printBoardAndCurrentScore(int sizeOfBoard, int** field, int score)
{
	for (int i = 0; i < sizeOfBoard; i++)
	{
		cout << " ";

		for (int j = 0; j < sizeOfBoard; j++)
		{
			cout << field[i][j];
			printSpace(lenghtOfNumber(field[i][j]));
			cout << " ";
		}
		cout << endl << endl;
	}
	cout << "Score: " << score << endl << endl;
}

void createRandomNumberOnTheBoard(int** field, size_t sizeOfField, int value, int& score)
{
	//generating random coordinates of the number

	srand(time(NULL));

	int firstCoordinateOfTheRandomNumber = rand() % sizeOfField;
	int secondCoordinateOfTheRandomNumber = rand() % sizeOfField;

	while (field[firstCoordinateOfTheRandomNumber][secondCoordinateOfTheRandomNumber] != 0)
	{
		firstCoordinateOfTheRandomNumber = rand() % sizeOfField;
		secondCoordinateOfTheRandomNumber = rand() % sizeOfField;
	}

	field[firstCoordinateOfTheRandomNumber][secondCoordinateOfTheRandomNumber] = value;
	score += value;
}

//Adding logic for random number 

int randomNumber2or4()
{
	//random number generator
	srand(time(NULL));
	return 1 << ((rand() % 2) + 1); //return 2 powered ones or twice
}

int randomNumber2or4or8()
{
	//random number generator
	srand(time(NULL));
	return 1 << ((((rand() % 5) + 1) % 3) + 1); //returns 2 powered ones, twice or three times
}

void deleteField(int** field, size_t sizeOfField)
{
	for (int i = 0; i < sizeOfField; i++)
	{
		delete[] field[i];
	}

	delete[] field;
}