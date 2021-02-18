/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Martin Ravanov
* @idnumber 62379
* @task 1
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const int INPUT_MAX_READABLE_LENGTH = 1000;


char* parseInput(){ // validates input - only capital letters, length 1 to 3
	char* input = new char[INPUT_MAX_READABLE_LENGTH]{0};
	bool isValid = false;

	cout << "Enter column name with length between 1 and 3: " << endl;

	do{
		//read input
		cin.getline(input, INPUT_MAX_READABLE_LENGTH);

		isValid = true;
		int length = strlen(input);
		
		for(int i = 0; i < length; i++){
			if((input[i] < 'A') || input[i] > 'Z'){   //to be a valid symbol, it should be a capital letter
				isValid = false;
			}
		}

		//is empty or is too long
		if(length == 0 || length > 3){
			isValid = false;
		}

		if(!isValid){
			cout << "Invalid input. Please enter a valid column name: " << endl;
		}
	} while(!isValid);

	return input;
}


int getNumberOfColumnFromItsName(char* str){
	int result = 0;
	int cnt = 0;

	int length = strlen(str);

	for(int i = length - 1; i >= 0; i--){    //start from the last element
		// the current char is a capital letter so this way
		// we transform the ascii code of the current char to its number value in the column

		// ! we think of the numeration of the columns as a base 26 numerical system
		result += int(str[i] - 'A' + 1) * pow(26, cnt++);  
	}

	return result;
}


int main(){
	//read input
	char* str = parseInput();

	int numberOfColumn = getNumberOfColumnFromItsName(str);

	//print result
	cout << "The column's number is: " << numberOfColumn << endl;

	delete[] str;

	return 1;
}