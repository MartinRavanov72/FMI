/**
*
* Solution to homework assignment 1
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


int main(){
	int number;
	
	cout << "Enter number: ";
	number = parseInt(1, 65535);
	
	while(number >= 0){
		system("cls"); //clears console
		cout << number;
	
		//slow loop to simulate timer
		for(int i = 0; i < 200000000; i++){
			int slowInt = i % 12;
			int slowInt2 = i % 79;
			int slowResult = slowInt + slowInt2;
		}
		number--;
	}
	cout << endl;

	return 1;
}
