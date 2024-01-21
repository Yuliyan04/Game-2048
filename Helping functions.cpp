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
* <Helper functions that I used to initialize the impoortant functions>
*
*/

#include "Helping functions.h"





int convertFromSymbolToNumber(char symbol)
{
	return symbol - '0';
}

char convertFromNumberToSymbol(int number)
{
	return number + '0';
}

int lenghtOfNumber(int number)
{
	int countOfDigits = 0;

	if (number == 0)
	{
		countOfDigits = 1;
	}

	while (number != 0)
	{
		number /= 10;
		countOfDigits++;
	}

	return countOfDigits;
}

int lenghtOfString(const char* input)
{
	if (!input)
	{
		return 0;
	}

	int lenght = 0;

	while (*input)
	{
		lenght++;
		input++;
	}

	return lenght;
}

void copyString(const char* source, char* destination)
{
	if (!source || !destination)
	{
		return;
	}

	while (*source)
	{
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
}