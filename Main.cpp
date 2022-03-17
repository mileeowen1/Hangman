#include "Hangman.h"
// main function
int main () {
	// assign variables with data types
	ifstream inputFile;
	int lengthOfList = 0;
	int randomWord = 0;
	string guessTheWord = "";
	int lengthOfWord = 0;
	char availableLettersReset[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char availableLetters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int m = 0;
	int n = 0;
	int o = 0;
	int p = 0;
	int guessesRemaining = 7;
	int correctlyGuessed = 0;
	int wordGuessed = 0;
	int roundPlayed = 0;
	int wrongGuesses = 0;
	bool playerWins = false;
	bool letterMatch = false;
	bool alreadyGuessed = false;
	bool runOnce = false;
	bool charNotGuessed = false;
	char letterGuess = ' ';
	char playerChoice = ' ';
	// seed random generator
	srand(time(0));
	// open input file
	openInputFile(inputFile);
	// call funtion to get the number of words in the file
	lengthOfList = getLengthOfList(inputFile);
	// create an array that is the length of the number of words
	string wordArray[lengthOfList];
	// close file to reset cursor
	inputFile.close();
	// open input file
	openInputFile(inputFile);
	// loop to read words
	while (!inputFile.eof()) {
		getline(inputFile, wordArray[i]);
		i++;
	}
	// pick a random word from list
	guessTheWord = wordArray[pickRandomWord(lengthOfList)];
	
/*	if (guessTheWord == " ") {
		while (guessTheWord == " ") {
			guessTheWord = wordArray[pickRandomWord(lengthOfList)];
		}
	}
*/
	// delete words that are randomly chosen
	for (j = 0; j < lengthOfList; j++) {
		if (guessTheWord == wordArray[j]) {
			wordArray[j] = " ";
		}
	}
	// get the length of the word
	lengthOfWord = guessTheWord.length();
	cout << "The word to guess has " << lengthOfWord << " letters." << endl << endl;
	// main game loop
	while (guessesRemaining != 0 && playerWins == false) {
		char visibleLetters[lengthOfWord];
		char unavailableLetters[26];
		// output word as blanks
		for (k = 0; k < lengthOfWord && runOnce == false; k++) {
			visibleLetters[k] = '-';
			cout << visibleLetters[k];
		}
		// display letters that are correctly guessed
		for (p = 0; p < lengthOfWord && runOnce == true; p++) {
			cout << visibleLetters[p];
		}
		runOnce = true;
		cout << endl;
		// display available letters and incorrect guesses
		cout << "Available letters: ";
		for (l = 0; l < 26; l++) {
			cout << availableLetters[l];
		}
		cout << endl;
		cout << guessesRemaining << " incorrect guesses remaining." << endl;
		cout << "Please enter your guess: " << endl;
		cin >> letterGuess;
		// loop for player guesses
		while (m < lengthOfWord) {
			for (n = 0; n < 26 && charNotGuessed == false; n++) {
				if (letterGuess == availableLetters[n]) {
					charNotGuessed = true;
				}
			}
			if (charNotGuessed == true) {
				availableLetters[n - 1] = ' ';
			}
			// statements that increment or decrement according to correct or wrong answers
			if (letterGuess == guessTheWord.at(m) && charNotGuessed == true) {
				letterMatch = true;
				correctlyGuessed++;
				visibleLetters[m] = letterGuess;
			}
			else if (m == lengthOfWord - 1 && charNotGuessed == true && letterMatch == false) {
				guessesRemaining--;
			}
			m++;
		}
		// call function to display according to guess
		displayGuessMessage(letterMatch, charNotGuessed, letterGuess, guessesRemaining);
		// no more guesses left
		if (guessesRemaining == 0) {
			cout << "Sorry, you've run out of guesses. The word was " << guessTheWord << "." << endl;
		}
		// guessed the word correctly
		if (correctlyGuessed == lengthOfWord) {
			wordGuessed++;
			cout << "Congratulations! You guessed the word " << guessTheWord << "!" << endl << endl << "Would you like to play another round? (y,n): ";
			cin >> playerChoice;
			// statements for steps taken after player decides
			if (playerChoice == 'n') {
				cout << "See you again." << endl;
				playerWins = true;
			}
			else {
				cout << "Picking another word..." << endl << endl;
				correctlyGuessed = 0;
				guessesRemaining = 7;
				runOnce = false;
				m = 0;
				// end program if all words are guessed
				if (wordGuessed == lengthOfList) {
					cout << "There are no more words to guess. Great job sport!" << endl;
					playerWins = true;
					break;
				}
				// reset available letter array
				for (o = 0; o < 26; o++) {
					availableLetters[o] = availableLettersReset[o];
				}
				// pick another random word
				guessTheWord = wordArray[pickRandomWord(lengthOfList)];
				// choose another word if already guessed and reset
				if (guessTheWord == " ") {
					while (guessTheWord == " ") {
						guessTheWord = wordArray[pickRandomWord(lengthOfList)];
					}
				}
				for (j = 0; j < lengthOfList; j++) {
					if (guessTheWord == wordArray[j]) {
						wordArray[j] = " ";
					}
				}
				lengthOfWord = guessTheWord.length();
				cout << "The word to guess has " << lengthOfWord << " letters." << endl << endl;
			}
		}
	// reset variables
	m = 0;
	letterMatch = false;
	charNotGuessed = false;
	}
	// close input file
	inputFile.close();
	return 0;
}
