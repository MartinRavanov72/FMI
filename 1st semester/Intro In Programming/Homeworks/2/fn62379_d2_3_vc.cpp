/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Martin Ravanov
* @idnumber 62379
* @task 3
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const int INPUT_MAX_READABLE_LENGTH = 1000;


char* parseInput(){ // validates input - should't be empty
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


char* repeatShorterChArr(char* arr1, char* arr2){
	int arr1Length = strlen(arr1);
	int arr2Length = strlen(arr2);
	char* result = new char[INPUT_MAX_READABLE_LENGTH]{0};

	//repeat the shorter string (the length of the longer string) times
	if(arr1Length > arr2Length){ 
		for(int i = 0; i < arr1Length; i++){ 
			//index on the shorter string goes back to 0 after the last index
			result[i] = arr2[i % arr2Length]; 
		}
	} else if(arr2Length > arr1Length){
		for(int i = 0; i < arr2Length; i++){
			//index on the shorter string goes back to 0 after the last index
			result[i] = arr1[i % arr1Length];
		}
	} 
	return result;
}


int main(){
	//read input
	char* arr1 = parseInput();

	char* arr2 = parseInput();

	//if they're the same length, we read them again
	while(strlen(arr1) == strlen(arr2)){
		cout << "Both strings should have different lengths!" << endl;

		//read input again
		arr1 = parseInput();

		arr2 = parseInput();
	}
	
	char* result = repeatShorterChArr(arr1, arr2);

	//print output
	cout << result << endl;

	delete[] arr1;
	delete[] arr2;
	delete[] result;

	return 1;
}