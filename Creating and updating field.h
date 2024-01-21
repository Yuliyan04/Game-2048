#pragma once


void printMenu();

void printField(int**, size_t, int);

void printSpace(int);

void printBoardAndCurrentScore(int, int**, int);

void createRandomNumberOnTheBoard(int**, size_t, int, int&);

int randomNumber2or4();

int randomNumber2or4or8();

void deleteField(int**, size_t);
