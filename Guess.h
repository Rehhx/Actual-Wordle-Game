
#ifndef GUESS_H
#define GUESS_H
#include <string>
using namespace std;
class Guess
{
public: 
	Guess();
	
	void setGuess(string userGuess);	//Sets the guess to the users guess
	void  setCorrectness(string userCorrectness);	//Checks the string length correctness
	string getGuess();	//Gets what the user guessed
	void printGuess();	//Prints the users guess
	

private:
		
		string correctness; // userguess
		string guess; // the users guess
		void stringUpper(string& word); //Function to change all letters to uppercase
};
#endif