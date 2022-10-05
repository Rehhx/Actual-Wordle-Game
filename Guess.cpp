#include "Guess.h"
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;
Guess::Guess() {
	//Initial guess variables
	guess = "N/A";
	correctness = "   ";
}

//Void function to change lowercase to uppercase for letters
void Guess::stringUpper(string& word) {
	for (int i = 0; i < word.size(); ++i) {
	//For loop until it reaches the end of the word
	word.at(i) = 	toupper(word.at(i));
	}
}

//Uses the all caps user string and then sets it equal to guess
void Guess::setGuess(string userGuess) {
	stringUpper(userGuess);
	guess = userGuess;
}

//Checks the length of the users string to check if it's correct
void Guess::setCorrectness(string userCorrectness) {
	stringUpper(userCorrectness);
	correctness = userCorrectness;
}

//Output of users guess onto the screen and then a void function to validate it
string Guess::getGuess() {
	return guess;
}
void Guess::printGuess() {
	int count = 0;
	//For loop in void function to check how close it is to the actual word
	for (int i = 0; i < guess.size(); ++i) {
		//If function to check for correctness to the actual word, then outputs it in colors
		if (correctness.at(i) == 'E') {
			//If letter guess is exact, it outputs green
			cout << green << guess.at(i) << reset <<" ";
		}
				//If letter is close but not exact, it outputs it in yellow
				else if (correctness.at(i) == 'M') {
					cout << yellow << guess.at(i) << reset <<  " ";
				}
				//If letter is not close, output the text in white
				else {
					cout << white << guess.at(i)  << reset <<   " ";
				}
	}
	cout << endl;
}