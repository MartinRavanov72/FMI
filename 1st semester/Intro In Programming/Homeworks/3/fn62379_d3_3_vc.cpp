/**
*
* Solution to homework assignment 3
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
#include <string.h>

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
			cout << "Please enter a valid integer: ";
			continue;
		}

		if((intNumber < lowerBound) || (intNumber > upperBound)){
			cout << "Please enter a valid integer: ";
		}
	} while(!isInt || (intNumber < lowerBound) || (intNumber > upperBound));

	return intNumber;
}


bool isValidWord(char* str){
	bool result = false;
	int length = strlen(str);

	// base cases
	if(strcmp(str, "") == 0){
		return true;
	}
	if(length > 64){
		return false;
	}

	// <w>C<w> and <w>D<w> are possible only in this case
	if(length % 2 == 1){
		bool isTheSameWord = true;

		for(int i = 0; i < (length - 1) / 2; i++){ //checks if in a case like this: <w>M<w1>, <w> is the same as <w1>
			if(str[i] != str[(length - 1) / 2 + i + 1]){
				isTheSameWord = false;
				break;
			}
		}

		// <w>C<w> and <w>D<w>: <w> should be the same word
		if(isTheSameWord){
			if(str[(length - 1) / 2] == 'C' || str[(length - 1) / 2] == 'D'){
				char word[100]{0};

				//store <w>
				for(int i = 0; i < (length - 1) / 2; i++){
					word[i] = str[i];
				}
				//check if <w> is valid
				result = isValidWord(word);
			}
		}
	}

	//the case for AA<w>B
	if(!result && (str[0] == 'A' && str[1] == 'A' && str[length - 1] == 'B')){
		char word[100]{0};

		//store <w>
		for(int i = 2; i < length - 1; i++){
			word[i - 2] = str[i];
		}
		//check if <w> is valid
		result = isValidWord(word);
	}

	//find the first 'C' in the string
	char * pch = strchr(str, 'C');

	if(!result && (pch != NULL)){
		bool hasTwoValidWords = false;

		//find all the 'C'-s in the string
		//if we don't find the two valid words, we will check with the next 'C' (if the is such)
		while(pch != NULL){
			char word1[100]{0};
			char word2[100]{0};

			//store <w1>
			for(int i = 0; i < pch - str; i++){
				word1[i] = str[i];
			}
			
			int cnt = 0;
			//store <w2>
			for(int i = pch - str + 1; i < length; i++){
				word2[cnt++] = str[i];
			}

			//both should be valid words
			hasTwoValidWords = isValidWord(word1) && isValidWord(word2);

			//both are valid
			if(hasTwoValidWords){
				result = true;
				break;
			}

			//find next 'C'
			pch = strchr(pch + 1, 'C');
		}
	}
	
	return result;
}


int main(){
	char str[256]{0};

	//read how many words are to be read from the console
	int n = parseInt(1, 10);
	cin.ignore();

	//check each word
	for(int i = 0; i < n; i++){
		cin.getline(str, 1000);
		cout << isValidWord(str) << endl;
	}

	system("pause");

	return 1;
}