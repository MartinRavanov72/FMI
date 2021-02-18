/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Martin Ravanov
* @idnumber 62379
* @task 4
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const int INPUT_MAX_READABLE_LENGTH = 1000;


char* parseInput(){ // validates input - shouldn't be empty
	char* input = new char[INPUT_MAX_READABLE_LENGTH]{0};
	bool isValid = false;

	cout << "Enter a string with length between 1 and 1000 (if it's more than 999, it will be cut): ";

	do{
		//read input
		cin.getline(input, INPUT_MAX_READABLE_LENGTH);

		isValid = true;
		int length = strlen(input);

		//is empty
		if(length == 0){
			isValid = false;
		}

		if(!isValid){
			cout << "Invalid input. Please enter a valid string: ";
		}
	} while(!isValid);

	return input;
}


bool isValidSymbol(char ch){
	//a valid symbol for a word - capital or small letters, dashes and underscores
	if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '_' || ch == '-'){
		return true;
	}
	return false;
}


int shortestWordCount(char* arr){
	//this array keeps the number of times we have encountered a word with a given length
	//on the nth index we have the number of words with a length of n;
	//we dont use the index 0
	int* lengthData = new int[INPUT_MAX_READABLE_LENGTH]{0};

	//we fill it up with zeros
	for(int i = 0; i < INPUT_MAX_READABLE_LENGTH; i++){
		lengthData[i] = 0;
	}

	char* currentWord = new char[INPUT_MAX_READABLE_LENGTH]{0};
	int currentIndexOfCurrentWord = 0;
	bool thereWereInvalidSymbols = false;

	for(int i = 0; i <= strlen(arr); i++){   //we should be able to reach the index after the end of the array
		//the string has ended
		if(i == strlen(arr)){
			//so if there was a valid word up until the end, we will save it's length
			if(strlen(currentWord) > 0){
				//we add 1 to the total number of words with length, equal to the current word's length
				lengthData[strlen(currentWord)] = lengthData[strlen(currentWord)] + 1;
			}

			break;
		}

		//is a white space (in that case only a space or a tab)
		if(arr[i] == ' ' || arr[i] == '\t'){
			//so we should check if there was a valid word up until now
			if(strlen(currentWord) > 0){
				//add 1 to the total number
				lengthData[strlen(currentWord)] = lengthData[strlen(currentWord)] + 1;

				//we restart the index and start a new word
				currentIndexOfCurrentWord = 0;

				delete[] currentWord;

				currentWord = new char[INPUT_MAX_READABLE_LENGTH]{0};
			}
			// we start a new set of words (valid or invalid), so this shold be set to false, so we can start filling up new words
			thereWereInvalidSymbols = false;
			
		} else if(!thereWereInvalidSymbols && isValidSymbol(arr[i])){ //is a valid symbol and there wasn't an invalid symbol in the current word																                                                                        
			//we add the char to current word
			currentWord[currentIndexOfCurrentWord++] = arr[i];

		} else{ //it isn't valid
			//should set this to true so we will not be able to start filling up a new word in cases like this - asd*asd
			thereWereInvalidSymbols = true;

			//we restart the index and start a new word
			currentIndexOfCurrentWord = 0;

			delete[] currentWord;

			currentWord = new char[INPUT_MAX_READABLE_LENGTH]{0};
		}
	}

	delete[] currentWord;

	//start from the start, so the first non 0 value will be found
	for(int i = 0; i < INPUT_MAX_READABLE_LENGTH; i++){
		if(lengthData[i] > 0){
			//return the number of the smallest words
			int result = lengthData[i];

			delete[] lengthData;
			
			return result;

		}
	}

	delete[] lengthData;

	return 0;
}


int main(){
	//read input
	char* arr = parseInput();

	int result = shortestWordCount(arr);

	//print output
	cout << result << endl;

	delete[] arr;

	return 1;
}