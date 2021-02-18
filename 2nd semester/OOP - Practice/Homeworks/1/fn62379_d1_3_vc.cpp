/**
*
* Solution to homework assignment 1
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

#include <iomanip> 
#include <iostream>

using namespace std;


bool isValidSymbol(char symbol){
	//valid mathematical symbols
	if((symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '%')){
		return true;
	}
	return false;
}

bool isValidHex(char numHex){
	//numbers 48-57 are for digits 0-9 and numbers 65-70 are for capital letters A-F(all found in the ASCII table)
	if(((int(numHex) >= 48) && (int(numHex) <= 57)) || ((int(numHex) >= 65) && (int(numHex) <= 70))){
		return true;
	}
	return false;
}

char parseCharHex(){  // function for parsing only valid hex characters
	char ch;
	bool isChar = true, isValid;

	do{
		isChar = true;
		cin >> ch;
		if(cin.fail()){
			isChar = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid expression." << endl;
			continue;
		}
		isValid = isValidHex(ch);
	} while(!isChar || !isValid);

	return ch;
}

char parseCharSymbol(){  // function for parsing only valid symbols
	char ch;
	bool isChar = true, isValid;

	do{
		isChar = true;
		cin >> ch;
		if(cin.fail()){
			isChar = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid expression." << endl;
			continue;
		}
		isValid = isValidSymbol(ch);
	} while(!isChar || !isValid);

	return ch;
}

int parseHexToDecimal(char chHex){
	if((int(chHex) >= 48) && (int(chHex) <= 57)){ //is a digit
		return int(chHex) - 48; //parsing to int so i.e 51(ascii) becomes 3(char), because 0(char) is 48(ascii)
	} else{
		return int(chHex) - 55; //is a letter, the same as above, but A(char) is 55(ascii)
	}
}


int main(){
	// variable of type char with a value = X, means it is empty
	char symbol, firstNumHex, secondNumHex, resultDigitHex1, resultDigitHex2 = 'X';
	int firstNumDecimal, secondNumDecimal, resultDecimal;
	bool isNegativeResult = false;
	
	cout << "Enter expression: ";
	symbol = parseCharSymbol();
	firstNumHex = parseCharHex();
	secondNumHex = parseCharHex();
	
	firstNumDecimal = parseHexToDecimal(firstNumHex);
	secondNumDecimal = parseHexToDecimal(secondNumHex);
	
	if(symbol == '+'){
		resultDecimal = firstNumDecimal + secondNumDecimal;
	} else if(symbol == '-'){
		resultDecimal = firstNumDecimal - secondNumDecimal;
	} else if(symbol == '/'){			
		resultDecimal = firstNumDecimal / secondNumDecimal;
	} else if(symbol == '*'){
		resultDecimal = firstNumDecimal * secondNumDecimal;
	} else{
		resultDecimal = firstNumDecimal % secondNumDecimal;
	}
	
	if(resultDecimal < 0){ // continuing, but keeping the possible minus in a bool
		isNegativeResult = true;
		resultDecimal = abs(resultDecimal);
	}

	//here we fill the first hex digit out
	if(resultDecimal % 16 < 10){  //is a digit
		resultDigitHex1 = resultDecimal % 16 + 48; 
	} else{ //is a letter
		resultDigitHex1 = resultDecimal % 16 + 55;
	}
	
	if(resultDecimal > 15){ //is 2 digit hex number
		resultDecimal /= 16;

		//filling the second hex digit out
		if(resultDecimal % 16 < 10){ //is a digit
			resultDigitHex2 = resultDecimal % 16 + 48; 
		} else{  //is a letter
			resultDigitHex2 = resultDecimal % 16 + 55; 
		}
	}
	
	//printing, bearing in mind the possible minus
	isNegativeResult ? cout << "-" : cout << "";
	//here's the possibly empty variable if it's value is X
	if(resultDigitHex2 == 'X'){
		cout << resultDigitHex1 << endl;
	} else{
		//the second digit is printed first since we started converting numbers from last digit to first
		//second digits represents 16 ^ 1 and the first : 16 ^ 0
		cout << resultDigitHex2 << resultDigitHex1 << endl; 
	}

	return 1;
}
