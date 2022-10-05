#ifndef SOLUTION_H
#define SOLUTION_H
#include <string>
using namespace std;
class Solution
{
public:

	Solution();
	string getWord(); //string for the solutions word
	void setWord(string solution); //function to set string
	bool isCorrect(string& userGuess ); //Checks word passed to it to check if it matches the solution
	string checkGuess(string userGuess); //Passed user guess and returns a string representing its correctness


private: 
	
	// word needs to be guessed 
	string wordGuess;
	void stringUpper(string& word);
};



#endif