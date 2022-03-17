#ifndef HANGMAN_H
#define HANGMAN_H
/*
Name: Milee Owen
Class: CPSC 121, Spring 2019
Date: March 30, 2019
Programming Assignment: PA7
Description: Create a program that plays the game hangman. The program will pick at random from a list of 10 to 100 words and the user has to guess the word.
*/
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
// function prototypes
void openInputFile(ifstream&);
int getLengthOfList(ifstream&);
int pickRandomWord(int);
int getLengthOfWord(string);
void displayGuessMessage(bool, bool, char, int);
#endif
