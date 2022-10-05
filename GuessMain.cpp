/*
WORDLE PROJECT
Programmers: Emmanuel & Peter
Date: 3/28/2022
Description: User guesses a word and the computer is tasked to generate a random word for the user to guess. 
			 It must be done in 6 or less trys, if not the user loses. The user stats is then persevred into
			 a seprate txt file with his stats for each game if he won or lost or his current streak and highest streak.
*/



#include <iostream>
#include <fstream>
#include <string>
#include "Guess.h"
#include "Solution.h"
#include "termcolor.hpp"
#include <iomanip>
#include <windows.h>
#include <ctime>
#include <cstdlib>

//Functions and Function Prototypes
void stringToLower(string& anyWord);
void printGuesses(Guess guess1[], int numGuesses);
int  binarySearch(string wordsFromTxt[], int numbersSize, string  key);
void determineStats(int numGusses);
void insertionSort(string wordsFromTxt[], int numbersSize);
using namespace std;

int main() {
	const int MAX_SIZE = 13000;
	const int GUESS_SIZE = 6;
	//Declaration of Variables
	Solution s;
	Guess guess1[GUESS_SIZE];
	bool done = false;

	string wordsFromTxt[MAX_SIZE];
	ifstream txtFile;
	string wordChosen;
	string wordSolution;
	string filename;
	string userGuess;
	string mCheck;
	int numGuesses = 1;
	int timesGuessed = 0;
	int sizeOfWordsArray = 0;
	int indexWordFromTxt = 0;
	int indexForSolution;
	int wordTrue = -1;
	int realNum = 1;
	int num = 0;

	cout << "Please wait we are loading the files." << endl;
	//Opens words.txt file and finds a random word from a random number
	txtFile.open("words.txt");


	if (!txtFile.is_open()) {
		//Output if words.txt is not able to be opened
		cout << "Could not open the file" << endl;
		return -1;
	}
	string wordTxt;
	while (txtFile >> wordTxt)
	{
		//Function if words.txt is able to be opened
		wordsFromTxt[num] = wordTxt;

		num++; // size of the array from the txt file 
	} insertionSort(wordsFromTxt, num);

	cout << endl;

	//Random number function to find a word in words.txt
	int numOfLoops = 0;
	srand(time(0));
	rand();
	indexWordFromTxt = rand() % num;

	//Applies the word to an index and makes that word the solution
	wordSolution = wordsFromTxt[indexWordFromTxt];

	//Outputs the solution word and puts the word into lowercase via the stringToLower function

	stringToLower(wordSolution);
	Sleep(8000);
	system("CLS");

	while ((timesGuessed < 6) && (done != true)) {
		//User loop for amount of user guesses and checks for correctness
		system("CLS");
		printGuesses(guess1, timesGuessed);
		cout << "Enter a guess 5 Letter guess: " << endl;;
		cin >> userGuess;

		stringToLower(userGuess);
		wordTrue = binarySearch(wordsFromTxt, num, userGuess);

		while (wordTrue == -1) { //Output if users word isn't found in list
			cout << "Not in word the list! Please type in a new word.\n";
			cin >> userGuess;
		
			stringToLower(userGuess);
			wordTrue = binarySearch(wordsFromTxt, num, userGuess);
			
		}
	
		stringToLower(userGuess);
		s.setWord(wordSolution);
		guess1[timesGuessed].setGuess(userGuess);

		mCheck = s.checkGuess(userGuess);
		guess1[timesGuessed].setCorrectness(mCheck);

		printGuesses(guess1, timesGuessed);

		done = s.isCorrect(userGuess);
		timesGuessed++;
		realNum++;
		//Loops the function until the timesGuesses is 6, making it have + 1 every time, also breaks if user guess is correct
	}
	
	printGuesses(guess1, timesGuessed);

	//Changes the boolean to true if word matches or if max number of guesses is reached, outputting appropriate responses
	if (done == true) {
		cout << "Congratulations!  You guessed correctly!" << endl;
	}
	else { //Outputs the correct word if user failed to guess it
		cout << "You lost!" << endl;
		cout << "The correct word is: \n" << s.getWord() << endl;
			
		timesGuessed = 0;
	}
	cout << endl;
	//Outputs this data into the determineStats function (statistics.txt) and after adding additional data closes the file
	determineStats(timesGuessed);
	txtFile.close();
	return 0;
}

int binarySearch(string wordsFromTxt[], int numbersSize, string  key) {
	//Binary Search to sort the words in the txt file for the random search
	int mid = 0;
	int low = 0;
	int  high = numbersSize - 1;

	while (high >= low) {
		//While loop with binary search function
		mid = (high + low) / 2;

		if (wordsFromTxt[mid] < key) {
			low = mid + 1;
		}
		else if (wordsFromTxt[mid] > key) {
			high = mid - 1;
		}
		else {
			return mid;
		}
	}
	return -1;
	//Output if word sort isn't found
}

//StringtoLower function to change all characters to lowercase
void stringToLower(string& anyWord) {

	for (int i = 0; i < anyWord.size(); ++i) {
		anyWord.at(i) = tolower(anyWord.at(i));
	}
}

//Printguess function to find array and number of guesses that were made, Printing the word and clearing the screen
void printGuesses(Guess guess1[], int timesGuessed) {
	system("CLS");

	for (int i = 0; i < timesGuessed; ++i) {
		guess1[i].getGuess();
		guess1[i].printGuess(); //Prints numbers on the screen that have been guessed
		
	}
	
}

void determineStats(int numGusses) {
	int num = 0;
	int wins = 0;
	int gamesPlayed = 0;
	int highestStreak = 0;
	int currentStreak = 0;
	float winPercentage = 0;
	int wins1 = 0;
	int wins2 = 0; 
	int wins3 = 0;
	int wins4 = 0;
	int wins5 = 0;
	int wins6 = 0;
	ofstream myfile;
	ifstream myfile2;
	//Variables here because easier to find for determining stats and txt purposes
	//Has integers for wins, games, streaks and what line you solved the game on
	myfile2.open("statistics.txt");

	if (!myfile2.is_open()) {


		int wins = 0;
		int gamesPlayed = 0;
		int highestStreak = 0;
		int currentStreak = 0;
		double winPercentage = 0;
		//Ints below for what line you got the answer on
		int wins1 = 0;
		int wins2 = 0;
		int wins3 = 0;
		int wins4 = 0;
		int wins5 = 0;
		int wins6 = 0;
	}
	int dataFromFile;

	//While loop to check for data, validate if found, 
	while (myfile2 >> dataFromFile) {
		if (num == 0) {
			gamesPlayed = dataFromFile;
		}
		else if (num == 1) {
			 currentStreak = dataFromFile;
		}
		else if (num == 2) {
			 highestStreak = dataFromFile;
		}
		else if (num == 3) {
			 wins = dataFromFile;
		}
		else if (num == 4) {
			wins1 = dataFromFile;
		}
		else if (num == 5) {
			 wins2 = dataFromFile;
		}
		else if (num == 6){
			wins3 = dataFromFile;
		}
		else if (num == 7) {
			 wins4 = dataFromFile;
		}
		else if (num == 8) {
			 wins5 = dataFromFile;
		}
		else if (num == 9) {
			 wins6 = dataFromFile;
		}
		num++;
	}
	
	myfile2.close();

	//Closes and reopens file with the new data

	
	gamesPlayed = gamesPlayed + 1;
	//Function to show what line you solved it on, then output it properly to the line with + 1 in the txt file
	if (numGusses == 0) {
		
		currentStreak = 0;
	}
	else if (numGusses == 1) {
		wins1 += 1;
		wins += 1;
		currentStreak += 1;
	}
	else if (numGusses == 2) {
		wins2 += 1;
		wins += 1;
		currentStreak += 1;
	}
	else if (numGusses == 3) {
		wins3 += 1;
		wins += 1;
		currentStreak += 1;
	}
	else if (numGusses == 4)
	{
		wins4 += 1;
		wins += 1;
		currentStreak += 1;
	}
	else if (numGusses == 5) {
		wins5 += 1;
		wins += 1;
		currentStreak += 1;
	}
	else if (numGusses == 6) {
		wins6 += 1;
		wins += 1;
		currentStreak += 1;
	}
	//Function to ensure current streak, if higher then higheststreak, will then be higheststreak
	if (currentStreak > highestStreak) {
		highestStreak = currentStreak;
	}
	winPercentage = 0.0;
	if (wins >= 1) {
		winPercentage = (double) wins / gamesPlayed * 100.0;
	}
	
	//Cout portion - outputs text with variables
	
	cout << "User Statistics:\n";
	cout << "Played: " << gamesPlayed << endl;

	//Equation to calculate win percentage

	cout << "Win %: " << fixed << setprecision(0) <<winPercentage << endl;

	//Function to output streak to file, both highest and users current streak
	cout << "Current Streak: " << currentStreak << endl; //If userGuess right, then set add to possible streak
	cout << "Max Streak: " << highestStreak << endl;

	//Which line you solved the win on and closes the file
	cout << "1\t" << wins1 << endl;
	cout << "2\t" << wins2 << endl;
	cout << "3\t" << wins3 << endl;
	cout << "4\t" << wins4 << endl;
	cout << "5\t" << wins5 << endl;
	cout << "6\t" << wins6 << endl;



	//Equation to calculate win percentage
	myfile.open("statistics.txt");
	
	myfile << gamesPlayed << endl;
	

	//Function to output streak to file, both highest and users current streak
	myfile << currentStreak << endl; //If userGuess right, then set add to possible streak
	myfile << highestStreak << endl;
	myfile << wins << endl;
	//Which line you solved the win on and closes the file
	myfile << wins1 << endl;
	myfile << wins2 << endl;
	myfile << wins3 << endl;
	myfile << wins4 << endl;
	myfile << wins5 << endl;
	myfile << wins6 << endl;
	
	myfile.close();

}

//Insertion sort to find the words properly in words.txt
void insertionSort(string wordsFromTxt[], int numbersSize) {
	int i = 0;
	int j = 0;
	string  temp =  " "; // Temporary variable for swap

	for (i = 1; i < numbersSize; ++i) {
		j = i;
		// Insert numbers[i] into sorted part
		// stopping once numbers[i] in correct position
		while (j > 0 && wordsFromTxt[j] < wordsFromTxt[j - 1]) {

			// Swap numbers[j] and numbers[j - 1]
			temp = wordsFromTxt[j];
			wordsFromTxt[j] = wordsFromTxt[j - 1];
			wordsFromTxt[j - 1] = temp;
			--j;
		}
	}
}