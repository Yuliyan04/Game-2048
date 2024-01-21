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
* <Validation functions>
*
*/

#include "Validation.h"




bool isValidCommand(char command)
{
	if (command == 'w' || command == 'd' || command == 's' || command == 'a')
	{
		return true;
	}

	return false;
}

bool isSizeInTheAllowedInterval(int size, int startOfInterval, int endOfInterval)
{
	if (size >= startOfInterval && size <= endOfInterval)
	{
		return true;
	}

	return false;
}

//Function that checks if there is any empty space on the field

bool isFieldFull(int** field, size_t sizeOfField)
{
	for (int i = 0; i < sizeOfField; i++)
	{
		for (int j = 0; j < sizeOfField; j++)
		{
			if (field[i][j] == 0)
			{
				return false;
			}
		}
	}

	return true;
}

//Function that checks if there is any left combinations on the field

bool areThereAnyPossibleMoves(int** field, size_t sizeOfField)
{
	for (int i = 0; i < sizeOfField; i++)
	{
		if (i == sizeOfField - 1)
		{
			for (int j = 0; j < sizeOfField - 1; j++)
			{
				if (field[i][j] == field[i][j + 1])
				{
					return false;
				}
			}
		}
		else if (i < sizeOfField - 1)
		{
			for (int j = 0; j < sizeOfField - 1; j++)
			{

				if (field[i][j] == field[i + 1][j])
				{
					return false;
				}
				else if (field[i][j] == field[i][j + 1])
				{
					return false;
				}
			}
		}
	}

	return true;
}

bool isFieldFullWithoutCombinations(int** field, size_t sizeOfField)
{
	if (areThereAnyPossibleMoves(field, sizeOfField) && isFieldFull(field, sizeOfField))
	{
		return true;
	}

	return false;
}