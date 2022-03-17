#include "Hangman.h"
// function definitions
/*************************************************************
 * Function: openInputFile()
 * Date Created: 04/01/19
 * Date Last Modified: 04/01/19
 * Description: This function opens an input file.
 * Input parameters: nothing
 * Returns: nothing
 * Pre: nothing
 * Post: Input file is opened.
 *************************************************************/
void openInputFile(ifstream& inputFile) {

	inputFile.open("Hangmanwords.txt");
	
	if (inputFile.fail()) {
		cout << "Failed to open file." << endl;
		exit(-1);
	}
}
/*************************************************************
 * Function: getLengthOfList()
 * Date Created: 04/01/19
 * Date Last Modified: 04/01/19          
 * Description: This function counts the number of words in a 
 *				file.
 * Input parameters: The input file.
 * Returns: The length of the list as an integer.
 * Pre: The input file had to have been scanned in by the user.
 * Post: The length of the list as an integer is returned.
 *************************************************************/
int getLengthOfList(ifstream& inputFile) {

	int lengthOfList = 0;
	string numOfWords = "";
	
	while (!inputFile.eof() && inputFile.good()) {
			getline(inputFile, numOfWords);
	 	    lengthOfList++;
	}
	
	return lengthOfList;		
}
/*************************************************************
 * Function: pickRandomWord()
 * Date Created: 04/01/19
 * Date Last Modified: 04/01/19          
 * Description: This function randomly picks a number
 *              depending on how many words a file has.
 * Input parameters: The length of the list of words.
 * Returns: A randomly chosen number with the function rand().
 * Pre: The length of the input file list had to have been
 *            	scanned in by the user.
 * Post: A randomly chosen number with the function rand() is 
 *				returned.
 *************************************************************/
int pickRandomWord(int lengthOfList) {

	int randomWord = 0;
	
	randomWord = rand() % lengthOfList;
	
	return randomWord;
}
/*************************************************************
 * Function: displayGuessMessage()
 * Date Created: 04/01/19
 * Date Last Modified: 04/01/19          
 * Description: This function displays messages throughout 
 *				game.
 * Input parameters: The booleans for if a letter matches and 
 *				if it was not already guessed, the letter that 
 *				was guessed, and number of remaining guesses.
 * Returns: nothing
 * Pre: The booleans for if a letter matches and if it was not 
 * 				already guessed, the letter that was guessed, 
 *				and number of remaining guesses had to have 
 *            	been scanned in by the user.
 * Post: A message is displayed.
 *************************************************************/
void displayGuessMessage(bool letterMatch, bool charNotGuessed, char letterGuess, int guessesRemaining) {
	if (letterMatch == true && charNotGuessed == true) {
		cout << "Right on! " << letterGuess << " is in the word!" << endl << endl;
	}
	
	else if (letterMatch == false && charNotGuessed == true) {
		cout << letterGuess << " is not in the word unfortunately:( " << guessesRemaining << " incorrect guesses remaining." << endl << endl;
	}
	
	else if (charNotGuessed == false) {
		cout << "You already guessed that letter. Guess another one." << endl << endl;
	}
}
