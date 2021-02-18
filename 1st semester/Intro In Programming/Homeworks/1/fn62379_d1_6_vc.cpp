/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Martin Ravanov
* @idnumber 62379
* @task 6
* @compiler VC
*
*/

#include <iomanip> 
#include <iostream>

using namespace std;

float parseFloat(){ // function to parse only valid float values
	float floatNumber;
	bool isFloat = true;

	do{
		isFloat = true;
		cin >> floatNumber;
		if(cin.fail()){
			isFloat = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid float." << endl;
			continue;
		}
	} while(!isFloat);

	return floatNumber;
}


int main(){
	const float SQUARE_HALF_SIDE = 1;
	const float SMALL_CIRCLE_RADIUS = 2;
	const float BIG_CIRCLE_RADIUS = 3;
	
	float x, y;
	
	cout << "Enter coordinates: ";
	x = parseFloat();
	y = parseFloat();
	
	if(x > -SQUARE_HALF_SIDE && x < SQUARE_HALF_SIDE && y > -SQUARE_HALF_SIDE && y < SQUARE_HALF_SIDE){ //checking whether a point is inside the rectange
		cout << "Black";
	} else if(x >= -SQUARE_HALF_SIDE && x <= SQUARE_HALF_SIDE && y >= -SQUARE_HALF_SIDE && y <= SQUARE_HALF_SIDE){ //goes here only if its on border, since if it's inside, it would have gone in the case above
		cout << "Undefined";
	} else if(x*x + y * y < SMALL_CIRCLE_RADIUS * SMALL_CIRCLE_RADIUS){ //checking whether a point is inside the inner circle
		cout << "White";
	} else if(x*x + y * y <= SMALL_CIRCLE_RADIUS * SMALL_CIRCLE_RADIUS){ //same as above, but this time with the inner circle
		cout << "Undefined";
	} else if(x*x + y * y < BIG_CIRCLE_RADIUS * BIG_CIRCLE_RADIUS){ //checking whether a point is inside the outer circle
		cout << "Black";
	} else if(x*x + y * y <= BIG_CIRCLE_RADIUS * BIG_CIRCLE_RADIUS){ //same as above, but this time with the outer circle
		cout << "Undefined";
	} else{ // is obviously not inside the figure
		cout << "Outside";
	}

	return 1;
}
