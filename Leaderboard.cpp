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
* <Leaderboard>
*
*/

#include "Leaderboard.h"
#include "Helping functions.h"
#include <iostream>
#include <fstream>
using namespace std;




const int count_of_players_RANKING = 5;
const int sizeOfBUFF = 1024;
const int FILE_NAME_SIZE = 7;

char* inputLeaderboardNickname(char*& line)
{
	char buff[sizeOfBUFF];
	int indexOfBuff = 0;

	while (*line != ':')
	{
		buff[indexOfBuff] = *line;
		line++;
	}
	buff[indexOfBuff] = '\0';

	line += 2;

	char* nickname = new char[lenghtOfString(buff) + 1];
	copyString(buff, nickname);

	return nickname;
}

int inputScore(const char* line)
{
	int points = 0;

	while (*line)
	{
		points = points * 10 + convertFromSymbolToNumber(*line);
		line++;
	}

	return points;
}

void inputNicknamesAndScore(char* line, char** nickname, int* scores)
{
	*nickname = inputLeaderboardNickname(line);
	*scores = inputScore(line);
}

void inputLeaderboard(const char* nameOfFile, char** nicknames, int* scores)
{
	ifstream inFile;
	inFile.open(nameOfFile);

	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			char buff[sizeOfBUFF];
			inFile.getline(buff, sizeOfBUFF);

			char* line = new char[lenghtOfString(buff) + 1];
			copyString(buff, line);

			inputNicknamesAndScore(line, nicknames, scores);
			delete[] line;
			nicknames++;
			scores++;
		}
	}
	else
	{
		cout << "The file can't be opened " << endl;
	}

	inFile.close();
}

int countOfPlayersInTheLeaderboard(int* points, int maxPlayers)
{
	int players = 0;

	for (int i = 0; i < maxPlayers; i++)
	{
		if (points[i] == 0)
		{
			break;
		}

		players++;
	}

	return players;
}

void fillTheLeaderboard(char** nicknames, int* scores, int players, char* nameOfFile)
{
	ofstream outFile;
	outFile.open(nameOfFile);

	if (outFile.is_open())
	{
		for (int i = 0; i < players; i++)
		{
			if (i == players - 1)
			{
				outFile << nicknames[i] << ": " << scores[i];
				break;
			}

			outFile << nicknames[i] << ": " << scores[i] << endl;
		}
	}
	else
	{
		cout << "The file can't be opened " << endl;
	}

	outFile.close();
}

void swapPoints(int* scores, int firstNumber, int secondNumber)
{
	int temp = scores[firstNumber];
	scores[firstNumber] = scores[secondNumber];
	scores[secondNumber] = temp;
}

void swapPlayers(char** nicknames, int firstNumber, int secondNumber)
{
	char* temp = nicknames[firstNumber];
	nicknames[firstNumber] = nicknames[secondNumber];
	nicknames[secondNumber] = temp;
}

void leaderboardRanking(char** nicknames, int* scores, int players)
{
	//I decided to use bubble sort

	for (int i = 0; i < players - 1; i++)
	{
		for (int j = 0; j < players - i - 1; j++)
		{
			if (scores[j] < scores[j + 1])
			{
				swapPoints(scores, j, j + 1);
				swapPlayers(nicknames, j, j + 1);
			}
		}
	}
}

void deleteNicknames(char** nicknames, size_t sizeOfMatrix)
{
	for (size_t i = 0; i < sizeOfMatrix; i++)
	{
		delete[] nicknames[i];
	}

	delete[] nicknames;
}

void changeRankingInLeaderboard(int sizeOfField, int currentScore, char* currentNickname, bool& isNicknameInNicknames)
{
	char nameOfFile[FILE_NAME_SIZE];
	inputNameOfFile(sizeOfField, nameOfFile);

	char** nicknames = new char* [count_of_players_RANKING];
	int scores[count_of_players_RANKING] = { 0 };
	inputLeaderboard(nameOfFile, nicknames, scores);
	int playersOnLeaderboard = countOfPlayersInTheLeaderboard(scores, count_of_players_RANKING);

	if (playersOnLeaderboard < count_of_players_RANKING)
	{
		scores[playersOnLeaderboard] = currentScore;
		nicknames[playersOnLeaderboard] = currentNickname;

		leaderboardRanking(nicknames, scores, playersOnLeaderboard + 1); //Ranking in the leadeboard
		fillTheLeaderboard(nicknames, scores, playersOnLeaderboard + 1, nameOfFile); //Save in the text file

		isNicknameInNicknames = true;
	}
	else
	{
		if (scores[count_of_players_RANKING - 1] < currentScore)
		{
			delete[] nicknames[count_of_players_RANKING - 1];

			scores[count_of_players_RANKING - 1] = currentScore;
			nicknames[count_of_players_RANKING - 1] = currentNickname;

			leaderboardRanking(nicknames, scores, playersOnLeaderboard);

			fillTheLeaderboard(nicknames, scores, playersOnLeaderboard, nameOfFile);

			isNicknameInNicknames = true;
		}
	}

	deleteNicknames(nicknames, playersOnLeaderboard);
}

void leaderboardMenu()
{
	cout << "Which leaderboard do you want to choose? " << endl;
	cout << "Leaderboards: " << endl;

	cout << "@ Leaderboard for size 4x4" << endl;
	cout << "@ Leaderboard for size 5x5" << endl;
	cout << "@ Leaderboard for size 6x6" << endl;
	cout << "@ Leaderboard for size 7x7" << endl;
	cout << "@ Leaderboard for size 8x8" << endl;
	cout << "@ Leaderboard for size 9x9" << endl;
	cout << "@ Leaderboard for size 10x10" << endl;
}

void showLeaderboard(const char* nameOfFile)
{
	ifstream inFile;
	inFile.open(nameOfFile);

	if (inFile.is_open())
	{
		while (!inFile.eof())
		{
			char buff[sizeOfBUFF];
			inFile.getline(buff, sizeOfBUFF);
			cout << buff << endl;
		}
	}
	else
	{
		cout << "The file can't be opened " << endl;
	}

	inFile.close();
}

void inputNameOfFile(int currentLeaderboard, char* nameOfFile)
{
	if (currentLeaderboard == 10)
	{
		nameOfFile[0] = '1';
		nameOfFile[1] = '0';
		copyString(".txt", nameOfFile + 2);
	}
	else
	{
		nameOfFile[0] = convertFromNumberToSymbol(currentLeaderboard);
		copyString(".txt", nameOfFile + 1);
	}
}

void showEnteredLeaderboard(int enteredLeaderboard)
{
	char nameOfFile[FILE_NAME_SIZE];
	inputNameOfFile(enteredLeaderboard, nameOfFile);
	showLeaderboard(nameOfFile);
}