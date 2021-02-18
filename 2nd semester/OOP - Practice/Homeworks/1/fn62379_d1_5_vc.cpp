/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Martin Ravanov
* @idnumber 62379
* @task 5
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
	float a, b, c, x1, x2, discriminant;
	bool hasNoRealRoots = false;
	
	cout << "Enter a, b and c: "; 
	a = parseFloat();
	b = parseFloat();
	c = parseFloat();

	//if a is 0, we continue reading input
	while(a==0){
		cout << "Please enter a valid float." << endl;
		a = parseFloat();
		b = parseFloat();
		c = parseFloat();
	}
	
	discriminant = b * b - 4 * a * c;
	
	if(discriminant > 0){
		x1 = (-b + sqrt(discriminant)) / (2 * a);
		x2 = (-b - sqrt(discriminant)) / (2 * a);
	} else if(discriminant == 0){
		x1 = -b / (2 * a);
		x2 = -b / (2 * a);
	} else{
		hasNoRealRoots = true;
	}
	
	// for presenting roots
	int numberOfRoots = 0;
	if(!hasNoRealRoots){
		if(x1 == 0){
			cout << "The equation's roots are: x1=0, x2=0";
			numberOfRoots += 2;
		} else if(x1 >= 0) {
			cout << "The equation's roots are: x1=" << sqrt(x1) << ", x2=" << -sqrt(x1);  
			numberOfRoots += 2;
		}
		if(x1 != x2){
			if(x2 == 0){
				cout << ", x" << numberOfRoots + 1 << "=0, x" << numberOfRoots + 2 << "=0";
				numberOfRoots += 2;
			} else if(x2 >= 0){
				cout << ", x" << numberOfRoots + 1 << "=" << sqrt(x2) << ", x" << numberOfRoots + 2 << "=" << -sqrt(x2) << endl;
				numberOfRoots += 2;
			}
		}
		
	}
	
	if(hasNoRealRoots || numberOfRoots == 0){
		cout << "The equation has no real roots." << endl;
	}

	return 1;
}
