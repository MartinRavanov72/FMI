/**
*
* Solution to homework assignment 1
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

#include <iomanip> 
#include <iostream>

using namespace std;

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
			cout << "Please enter a valid integer." << endl;
			continue;
		}

		if((intNumber < lowerBound) || (intNumber > upperBound)){
			cout << "Please enter a valid integer." << endl;
		}
	} while(!isInt || (intNumber < lowerBound) || (intNumber > upperBound));

	return intNumber;
}

bool isLeap(int year){
	bool yearIsLeap = false;
	if(year % 4 == 0){
		yearIsLeap = true;
		if((year % 100 == 0) && (year % 400 != 0)){
			yearIsLeap = false;
		}
	}
	return yearIsLeap;
}


int main(){
	const int STARTING_YEAR = 1;
	const int DAYS_IN_A_NON_LEAP_YEAR = 365;
	const int DAYS_IN_A_LEAP_YEAR = 366;

	int days, year = STARTING_YEAR;
	bool yearIsLeap;

	cout << "Enter days: ";
	days = parseInt(1, 1000000);

	while(days >= DAYS_IN_A_NON_LEAP_YEAR){
		yearIsLeap = isLeap(year);

		if(yearIsLeap){
			if(days > DAYS_IN_A_LEAP_YEAR){
				year++;
			}
			days -= DAYS_IN_A_LEAP_YEAR;
		} else{
			if(days > DAYS_IN_A_NON_LEAP_YEAR){
				year++;
			}
			days -= DAYS_IN_A_NON_LEAP_YEAR;
		}
	}

	cout << year << endl;

	return 1;
}
