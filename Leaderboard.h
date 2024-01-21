#pragma once


char* inputLeaderboardNickname(char*&);

int inputScore(const char*);

void inputNicknamesAndScore(char*, char**, int*);

void inputLeaderboard(const char*, char**, int*);

int countOfPlayersInTheLeaderboard(int*, int);

void fillTheLeaderboard(char**, int*, int, char*);

void swapPoints(int*, int, int);

void swapPlayers(char**, int, int);

void leaderboardRanking(char**, int*, int);

void deleteNicknames(char**, size_t);

void inputNameOfFile(int, char*);

void changeRankingInLeaderboard(int, int, char*, bool&);

void leaderboardMenu();

void showLeaderboard(const char*);

void showEnteredLeaderboard(int);
