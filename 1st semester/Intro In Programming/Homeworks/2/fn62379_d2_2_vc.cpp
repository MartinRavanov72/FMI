/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Martin Ravanov
* @idnumber 62379
* @task 2	
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const int INPUT_MAX_READABLE_LENGTH = 1000;


char* parseInput(){ // validates input - length 1 to 100
	char* input = new char[100]{0};
	bool isValid = false;

	cout << "Enter a string with length between 1 and 100: ";

	do{
		//read input
		cin.getline(input, INPUT_MAX_READABLE_LENGTH);

		isValid = true;
		int length = strlen(input);

		//is empty or is too long
		if(length == 0 || length > 100){
			isValid = false;
		}

		if(!isValid){
			cout << "Invalid input. Please enter a valid string: ";
		}
	} while(!isValid);

	return input;
}


int parseInt(int lowerBound, int upperBound){  // fixed version of the one in the slides, lower- and upperBound added
	int intNumber;
	bool isInt = true;

	do{
		isInt = true;
		cin >> intNumber;
		if(cin.fail()){
			isInt = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid integer: ";
			continue;
		}

		if((intNumber < lowerBound) || (intNumber > upperBound)){
			cout << "Please enter a valid integer: ";
		}
	} while(!isInt || (intNumber < lowerBound) || (intNumber > upperBound));

	return intNumber;
}


bool hasInvalidSymbols(char* str){
	int length = strlen(str);

	for(int i = 0; i < length; i++){
		//has symbols not between 32 and 126
		if(str[i] < ' ' || str[i] > '~'){
			return true;
		}
	}
	return false;
}


char* encryptString(char* str, int m, int l){
	int arrLength = strlen(str);
	char nextElement;
	int indexOfArr = 0;

	//there is no point in shifting the array more times than it's length - 1
	l = l % arrLength;

	for(int counter = 0; counter < l*arrLength; counter++){  //l*arrLength is the number of shifts we have to do (each element shifted l times)

		//see the posotion on the array
		indexOfArr = counter % arrLength;

		if(indexOfArr == 0){ //we are on the first element here
			if(indexOfArr + 1 == arrLength){ // the length is obviously 1, so nothing should be changed
				break;
			} else{
				//either the previously last element's value is now on the start of the array, or we have just started the for loop.
				//Either way, we start changing the next element's value with the value of the current element (later, the previously changed value),
				//but we're storing the value of the next element before it is changed, so we can use it on the next iteration
				nextElement = str[indexOfArr + 1];
				str[indexOfArr + 1] = str[indexOfArr];
			}
		} else{
			if(indexOfArr + 1 == arrLength){ //next index is outside the array boundries
				//the element's value to be changed is the first element, since we're shifting the array and now it comes the first element
				char temp = str[0]; 
				//we change the first element's value with the kept value of the previous element
				str[0] = nextElement;
				//we keep the value of the element before it was changed, so we can, later change the value of the next element
				nextElement = temp;
			} else{ //next index is within the array
				//same logic as above, but the element-to-be-changed's value is within the array
				char temp = str[indexOfArr + 1];
				str[indexOfArr + 1] = nextElement;
				nextElement = temp;
			}
		}
		
	}

	//change each char with a new element with a ASCII code, which is the original char + m
	for(int i = 0; i < arrLength; i++){
		str[i] = char(str[i] + m);
	}
	return str;
}


int main(){
	//read input
	char* str = parseInput();

	cout << "Enter a positive integer - m: ";
	int m = parseInt(1, 20);

	cout << "Enter a positive integer - l: ";
	int l = parseInt(1, strlen(str) - 1);

	//check if it has symbols not between 32 and 126
	bool isUnEncryptable = hasInvalidSymbols(str);

	if(isUnEncryptable){
		//stays unchanged
		cout << str << endl;
	} else{
		str = encryptString(str, m, l);

		// print output
		cout << str << endl;
	}

	delete[] str;

	return 1;
}