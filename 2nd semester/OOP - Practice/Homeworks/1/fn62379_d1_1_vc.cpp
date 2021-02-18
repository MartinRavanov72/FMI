/**
*
* Solution to homework assignment 1
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

#include <iomanip> 
#include <iostream>

using namespace std;

int parseInt(){ // fixed version of the one in the slides
	int intNumber;
	bool isInt = true;

	do{
		isInt = true;
		cin >> intNumber;
		if(cin.fail()){
			isInt = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid integer." << endl;
			continue;
		}
	} while(!isInt);

	return intNumber;
}


bool hasTwoEqualDigits(int number){
	int tempNumber;
	while(number > 0){
		int currentDigit1 = number % 10;
		number /= 10;
		tempNumber = number;
		while(tempNumber > 0){
			int currentDigit2 = tempNumber % 10;
			if(currentDigit1 == currentDigit2){
				return true;
			}
			tempNumber /= 10;
		}
	}
	return false;
}


int main(){
	int number;
	bool numHasTwoEqualDigits;

	cout << "Enter number: ";

	number = abs(parseInt()); // getting rid of the minus, because when comparing digits, it's irrelevant

	if(number < 0){ //abs seems to be broken when the number is int's min value, so, fixing it
		number = 2147483647; //not quite the fix, but int's max value has two equal digits, so... (abs(int's min value) isn't the same as int's max value)
	}

	numHasTwoEqualDigits = hasTwoEqualDigits(number);

	if(numHasTwoEqualDigits){
		cout << "It has two equal digits." << endl;
	} else{
		cout << "It doesn't have two equal digits." << endl;
	}

	return 1;
}