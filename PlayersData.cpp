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
* <Data inputed by players>
*
*/

#include "PlayersData.h"
#include "Helping functions.h"
#include "Validation.h"
#include <iostream>
using namespace std;





const int MIN_sizeOfField = 4;
const int MAX_sizeOfField = 10;
const int sizeOfBUFF = 500;

//Menu options

void printMenu()
{
	cout << "Options: " << endl;

	cout << "1. Start game " << endl;
	cout << "2. Leaderboard " << endl;
	cout << "3. Quit game " << endl;
}

int chooseOption()
{
	cout << "Choose 1,2 or 3:" << endl;

	int option = 0;

	while (true)
	{
		char buff[sizeOfBUFF];
		cin.getline(buff, sizeOfBUFF);

		if (lenghtOfString(buff) == 1)
		{
			option = convertFromSymbolToNumber(buff[0]);
		}
		if (option >= 1 && option <= 3)
		{
			break;
		}

		cout << "Incorrect command. Enter a new one: ";
	}

	return option;
}

//The player enters a nickname

char* inputNickname()
{
	cout << "Enter nickname: ";

	char buff[sizeOfBUFF];
	cin.getline(buff, sizeOfBUFF);

	char* input = new char[lenghtOfString(buff) + 1];
	copyString(buff, input);

	return input;
}

//The player enters a field size

int inputSizeOfField()
{
	cout << "Enter the size of the field: ";
	int sizeOfField;
	cin >> sizeOfField;

	while (!isSizeInTheAllowedInterval(sizeOfField, MIN_sizeOfField, MAX_sizeOfField))
	{
		cout << "The size you have choosen is wrong. Enter a new one: ";
		cin >> sizeOfField;
	}

	return sizeOfField;
}

//The player chooses a move command

char inputCommand()
{
	cout << "Make a move: ";

	char command;

	while (true)
	{
		char buff[sizeOfBUFF];
		cin.getline(buff, sizeOfBUFF);

		if (lenghtOfString(buff) == 1)
		{
			command = buff[0];

			if (isValidCommand(command))
			{
				break;
			}
		}

		cout << "Invalid move. Enter a new one: ";
	}

	return command;
}

//If option 2 is choosen

int inputLeaderboard()
{
	cout << "Choose the size of the Leaderboard: ";

	int command = 0;

	while (true)
	{
		char buff[sizeOfBUFF];
		cin.getline(buff, sizeOfBUFF);
		int lenghtOfBuff = lenghtOfString(buff);

		if (lenghtOfBuff == 1) //for one digit
		{
			command = convertFromSymbolToNumber(buff[0]);
		}
		else if (lenghtOfBuff == 2) //for ten
		{
			command = convertFromSymbolToNumber(buff[0]) * 10 + convertFromSymbolToNumber(buff[1]);
		}
		if (command >= 4 && command <= 10)
		{
			break;
		}

		cout << "The command isn't correct. Enter a new one: ";
	}

	return command;
}
