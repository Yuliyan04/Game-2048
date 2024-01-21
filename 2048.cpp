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
* <Game start, Leaderboard and Main>
*
*/



#include "Creating and updating field.h"
#include "PlayersData.h"
#include "Leaderboard.h"
#include "Move commands.h"
#include <iostream>
using namespace std;




void startGame()
{
	bool isNicknameInNicknames = false;
	char* nickname = inputNickname();

	int sizeOfField = inputSizeOfField();
	int** field = new int* [sizeOfField];

	int score = 0;
	cin.ignore();

	gameplay(field, sizeOfField, score);

	printBoardAndCurrentScore(sizeOfField, field, score);

	changeRankingInLeaderboard(sizeOfField, score, nickname, isNicknameInNicknames);
	if (!isNicknameInNicknames)
	{
		delete[] nickname;
	}
}

void Leaderboard()
{
	leaderboardMenu();
	int chosenLeaderboard = inputLeaderboard();
	showEnteredLeaderboard(chosenLeaderboard);
}

int main()
{
	printMenu();
	int command = chooseOption();

	while (command != 3)
	{
		if (command == 1)
		{
			startGame();
		}
		else if (command == 2)
		{
			Leaderboard();
		}

		printMenu();
		command = chooseOption();
	}
}

