/**
*
* Solution to homework assignment 3
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
#include <string.h>

using namespace std;


//gets rid of the '-' on the 0th index of a string
char* makePositive(char* str){
	char* positiveChArr = new char[1000]{0};
	int cnt = 0;

	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] != '-'){
			positiveChArr[cnt++] = str[i];
		}
	}
	return positiveChArr;
}


//adds a '-' on the 0th index of a string
char* makeNegative(char* str){
	char* negativeChArr = new char[1000]{0};
	negativeChArr[0] = '-';

	for(int i = 0; str[i] != '\0'; i++){
		negativeChArr[i+1] = str[i];
	}
	return negativeChArr;
}


//reverse char array
void reverseCharArray(char* arr, int start, int end){
	while(start < end){
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}


//reverse int array
void reverseArrayInt(int* arr, int start, int end){
	while(start < end){
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}


//swap char arrays
void swapCharArrays(char *&str1, char *&str2){
	char *one = str1;
	str1 = str2;
	str2 = one;
}


//function for the '-' operation, both strings will be positive numbers
//since we might have used the makePositive or makeNegative functions, we have to delete if needed
void findDifference(char* str1, char* str2, bool deleteString1, bool deleteString2){
	bool isPositive = true;

	//the second num has more digits(is bigger), so the result is negative, and to get its value we will swap them and after finding their difference we will add a '-' in front of the result
	if(strlen(str1) < strlen(str2)){
		swapCharArrays(str1, str2);

		//swaps the bools, since we've swapped the strings
		bool temp = deleteString1;
		deleteString1 = deleteString2;
		deleteString2 = temp;

		isPositive = false;
	} else if(strlen(str1) == strlen(str2)){
		//the second num is bigger, same as above
		if(strcmp(str1, str2) < 0){
			swapCharArrays(str1, str2);

			//swaps the bools, since we've swapped the strings
			bool temp = deleteString1;
			deleteString1 = deleteString2;
			deleteString2 = temp;

			isPositive = false;
		}
	}

	//the numbers are the same
	if(strcmp(str1, str2) == 0){
		cout << "0" << endl;
		return;
	}

	int num1[1000], num2[1000], result[1000];

	reverseCharArray(str1, 0, strlen(str1) - 1);
	reverseCharArray(str2, 0, strlen(str2) - 1);

	for(int i = 0; str1[i] != '\0'; i++){
		num1[i] = str1[i] - '0';
	}

	for(int i = 0; str2[i] != '\0'; i++){
		num2[i] = str2[i] - '0';
	}

	//reverse both s
	reverseCharArray(str1, 0, strlen(str1) - 1);
	reverseCharArray(str2, 0, strlen(str2) - 1);

	int borrow = 0;
	int difference = 0;
	int digit1 = 0;
	int digit2 = 0;

	//str1 is the bigger number
	for(int i = 0; i < strlen(str1); i++){
		//we do it as we would on paper
		digit1 = num1[i];

		if(i >= strlen(str2)){
			digit2 = 0;
		} else{
			digit2 = num2[i];
		}

		difference = (digit1 - digit2 - borrow);

		if(difference < 0){
			difference += 10;
			borrow = 1;
		} else{
			borrow = 0;
		}

		result[i] = difference;
	}

	//result will be reversed, so we reverse it
	reverseArrayInt(result, 0, strlen(str1) - 1);

	if(!isPositive){
		cout << "-";
	}

	int lastDigit = 0;
	bool print = false;

	//print number without leading zeros
	for(int i = 0; i < strlen(str1); i++){

		if(result[i] != 0 || lastDigit != 0 || print){
			print = true;
		}
		lastDigit = result[i];

		if(print && result[i] <= 9){
			cout << result[i];
		}
	}

	cout << endl;

	if(deleteString1){
		delete[] str1;
	}
	if(deleteString2){
		delete[] str2;
	}
}


//function for the operation '*', there will be two positive numbers or one positive and one negative
void multiply(char* str1, char* str2, bool deleteString1, bool deleteString2){
	//if any of numbers are 0, result is zero
	if(strcmp(str1, "0") == 0 || strcmp(str2, "0") == 0){
		cout << "0" << endl;
		return;
	}

	bool isPositive = true;

	//check if there are negative numbers
	if(str1[0] == '-' || str2[0] == '-'){
		isPositive = false;
		if(str1[0] == '-' && str2[0] != '-'){
			str1 = makePositive(str1);
		} else if(str1[0] != '-' && str2[0] == '-'){
			str2 = makePositive(str2);
		}
	}

	//fill result string with zeros
	int result[10000];
	for(int i = 0; i < 10000; i++){
		result[i] = 0;
	}

	//strings should be reversed
	reverseCharArray(str1, 0, strlen(str1) - 1);
	reverseCharArray(str2, 0, strlen(str2) - 1);


	//we do it as we would on paper
	for(int i = 0; i < strlen(str1); i++){
		for(int j = 0; j < strlen(str2); j++){
			result[i + j] += (str1[i] - '0') * (str2[j] - '0');
			result[i + j + 1] = result[i + j + 1] + result[i + j] / 10;
			result[i + j] %= 10;
		}
	}

	//result is reversed so we should reverse it back
	reverseArrayInt(result, 0, 10000 - 1);

	int lastDigit = 0;
	bool print = false;

	//add minus if any of the nums are negative
	if(!isPositive){
		cout << "-";
	}

	//we print the result without the leading zeros
	for(int i = 0; i < 10000; i++){
		if(result[i] != 0 || lastDigit != 0 || print){
			print = true;
		}
		lastDigit = result[i];
		if(print){
			cout << result[i];
		}
	}

	cout << endl;

	if(deleteString1){
		delete[] str1;
	}
	if(deleteString2){
		delete[] str2;
	}
}


//function for the operation '+', strings are both either positive, or negative numbers
void findSum(char* str1, char* str2, bool deleteString1, bool deleteString2){
	int num1[1000], num2[1000], sum[2000];
	int num1Length, num2Length;
	bool isPositive = true;

	//if both are negative, result will be the same as their sum as positive numbers but with a '-' in front of it
	if(str1[0] == '-' && str2[0] == '-'){
		isPositive = false;
		str1 = makePositive(str1);
		str2 = makePositive(str2);
	}

	//fill nums
	for(num1Length = 0; str1[num1Length] != '\0'; num1Length++){
		num1[num1Length] = str1[num1Length] - '0';
	}

	for(num2Length = 0; str2[num2Length] != '\0'; num2Length++){
		num2[num2Length] = str2[num2Length] - '0';
	}

	int carry = 0;
	int currentIndex = 0;
	int lastIndexOfNum1 = num1Length - 1;
	int lastIndexOfNum2 = num2Length - 1;

	//we do it as we would on paper
	for(; lastIndexOfNum1 >= 0 && lastIndexOfNum2 >= 0; lastIndexOfNum1--, lastIndexOfNum2--, currentIndex++){
		sum[currentIndex] = (num1[lastIndexOfNum1] + num2[lastIndexOfNum2] + carry) % 10;
		carry = (num1[lastIndexOfNum1] + num2[lastIndexOfNum2] + carry) / 10;
	}

	if(num1Length >= num2Length){
		while(lastIndexOfNum1 >= 0){
			sum[currentIndex++] = (num1[lastIndexOfNum1] + carry) % 10;
			carry = (num1[lastIndexOfNum1--] + carry) / 10;
		}
	} else if(num1Length < num2Length){
		while(lastIndexOfNum2 >= 0){
			sum[currentIndex++] = (num2[lastIndexOfNum2] + carry) % 10;
			carry = (num2[lastIndexOfNum2--] + carry) / 10;
		}
	}
	if(carry > 0){
		sum[currentIndex++] = carry;
	}

	//add a '-' is necessary
	if(!isPositive){
		cout << "-";
	}

	//print sum
	for(currentIndex--; currentIndex >= 0; currentIndex--){
		cout << sum[currentIndex];
	}
	cout << endl;

	if(deleteString1){
		delete[] str1;
	}
	if(deleteString2){
		delete[] str2;
	}
}


//calls the appropriate functions
void distributeFunctions(char* str1, char* str2, const char* operation){
	//all the cases there is a negative number
	if(str1[0] == '-' || str2[0] == '-'){
		//first num is negative, second num is positive
		if(str1[0] == '-' && str2[0] != '-'){
			//for instances like -4 and 3, we call the following functions
			if(strcmp(operation, "plus") == 0){
				findDifference(str2, makePositive(str1), false, true);
			} else if(strcmp(operation, "minus") == 0){
				findSum(str1, makeNegative(str2), false, true);
			} else if(strcmp(operation, "multiply") == 0){
				multiply(str1, str2, false, false);
			}
			
		} else if(str1[0] != '-' && str2[0] == '-'){ //first num is positive, second one is negative
			//for instances like 4 and -3, we call the following functions
			if(strcmp(operation, "plus") == 0){
				findDifference(str1, makePositive(str2), false, true);
			} else if(strcmp(operation, "minus") == 0){
				findSum(str1, makePositive(str2), false, true);
			} else if(strcmp(operation, "multiply") == 0){
				multiply(str1, str2, false, false);
			}
		} else{  //both nums are negative
			//for instances like -4 and -3, we call the following functions
			if(strcmp(operation, "plus") == 0){
				findSum(str1, str2, false, false);
			} else if(strcmp(operation, "minus") == 0){
				findDifference(makePositive(str2), makePositive(str1), true, true);
			} else if(strcmp(operation, "multiply") == 0){
				multiply(makePositive(str1), makePositive(str2), true, true);
			}
		}
	} else{ //both nums are positive
		//for instances like 4 and 3, we call the following functions
		if(strcmp(operation, "plus") == 0){
			findSum(str1, str2, false, false);
		} else if(strcmp(operation, "minus") == 0){
			findDifference(str1, str2, false, false);
		} else if(strcmp(operation, "multiply") == 0){
			multiply(str1, str2, false, false);
		}
	}
}


int main(){
	char str1[1000]{0};
	char str2[1000]{0};
	char operation[1000]{0};
	
	//read input
	cin >> operation >> str1 >> str2;

	//call the distributor of functions
	if(operation[0] == '-'){
		distributeFunctions(str1, str2, "minus");
	} else if(operation[0] == '+'){
		distributeFunctions(str1, str2, "plus");
	} else if(operation[0] == '*'){
		distributeFunctions(str1, str2, "multiply");
	}
	
	system("pause");
	return 1;
}