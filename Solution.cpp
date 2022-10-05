#include "Solution.h"
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

Solution::Solution() { //Default and fallback solution word
	wordGuess = "None";
}

void Solution::stringUpper(string& word) { //Changes all letters to uppercase
	for (int i = 0; i < word.size(); ++i) {
		//For loop until it reaches the end of the word
		word.at(i) = toupper(word.at(i));
	}

}
void Solution::setWord(string userSolution) {
	stringUpper(userSolution);
	wordGuess = userSolution;
}
string Solution::getWord() {
	return wordGuess;
}
 bool Solution::isCorrect(string& usersGuess) { //Checks if the user guess is the same as the word
	 stringUpper(usersGuess);
	 if (wordGuess == usersGuess) {
		return true;
	}
	else {
		return false;
	}
}
 string Solution::checkGuess(string usersGuess) {
	 //Checks users word for correctness and returns it with correctness
	 string temp = wordGuess;
	 string result;
	 int count = 0;
	 int size = usersGuess.size();
	 stringUpper(usersGuess);
	 for (int k = 0; k < size; ++k) { //Replaces the letters with spaces
		 result.append(" ");
	 }
	 for (int i = 0; i < size; ++i) { //Checks for exact match, if exact it outputs E
		 
		 if (usersGuess.at(i) == temp.at(i)) {
			 result.at(i) = 'E';
			 temp.at(i) = ' ';
		 }
		 if (usersGuess.size() != temp.size()) {
			
			 return result;
		 }

	 }
	 
	 for(int i = 0; i < size; ++i){ //Checks for something other then exact match, if its close output M
			 for (int j = 0; j < size; ++j) {
				 if (usersGuess.at(i) == temp.at(j)) {
					 result.at(i) = 'M';
					 temp.at(j) = ' ';
					 j = size;
				 }
		 }
	 }

	 return result;
 }