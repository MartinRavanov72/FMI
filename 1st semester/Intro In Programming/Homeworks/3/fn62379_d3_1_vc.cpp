/**
*
* Solution to homework assignment 3
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

#include <iostream>
#include <cstdlib> 
#include <string.h>

using namespace std;


struct Question{
	char title[100], answer1[100], answer2[100], answer3[100], answer4[100];
	int trueAnswerNumber;
};


// questions database
Question questions[11] = {{"Solve: 1 - 2 = ?", "1", "-1", "0", "yes", 2}, {"Solve: 10 - 8 = ?", "2", "3", "0", "no", 1}, {"Solve: 1 - 50 = ?", "1000", "-1", "-49", "-4a", 3},
{"Solve: 1 - 0 = ?", "0", "-1", "yes", "1", 4}, {"Solve: 0 * 123123 = ?", "0", "123123", "321321", "0123123", 1}, {"Solve: 7 + 1991 = ?", "1998", "71991", "7991", "all of the answers", 1},
{"Whats 9 plus 10 ?", "21", "21", "21", "19", 4}, {"Is Israel a legitimate country?", "no", "I said no", "NO!", "yes", 4},
{"How many hours are there in a day", "34", "43", "00001200", "24", 4}, {"Solve: 7/3 = ?", "7/3?", "7", "2", "+9", 1}};


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


char parseChar(char lowerBound, char upperBound){  // function for parsing only valid symbols
	char ch;
	bool isChar = true, isValid;

	do{
		isChar = true;
		cin >> ch;
		if(cin.fail()){
			isChar = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid letter: " << endl;
			continue;
		}

		//lowercase letters will be accepted
		if(ch >= 'a' && ch <= 'd'){
			ch -= 'a' - 'A';
		}

		isValid = ch >= lowerBound && ch <= upperBound;

		if((ch < lowerBound) || (ch > upperBound)){
			cout << "Please enter a valid letter: ";
		}
	} while(!isChar || !isValid);

	return ch;
}

// chooses a random num (for questions and 50/50)
int chooseRandom(int num){
	return rand() % num;
}


void printQuestion(Question question, int answerNotToBePrinted1Index, int answerNotToBePrinted2Index){
	char letter = 'A';
	cout << question.title << endl;

	if(answerNotToBePrinted1Index != 1 && answerNotToBePrinted2Index != 1){
		cout << letter++ << ") ";
		cout << question.answer1 << endl;
	}
	if(answerNotToBePrinted1Index != 2 && answerNotToBePrinted2Index != 2){
		cout << letter++ << ") ";
		cout << question.answer2 << endl;
	}
	if(answerNotToBePrinted1Index != 3 && answerNotToBePrinted2Index != 3){
		cout << letter++ << ") ";
		cout << question.answer3 << endl;
	}
	if(answerNotToBePrinted1Index != 4 && answerNotToBePrinted2Index != 4){
		cout << letter++ << ") ";
		cout << question.answer4 << endl;
	}
	cout << endl;
}


void chooseAnswer(int trueAnswerNumber, char lowerBound, char upperBound){
	//user enters the answers he/she thinks is right
	char userAnswer = parseChar(lowerBound, upperBound);
	cout << endl;

	if(userAnswer - 'A' + 1 == trueAnswerNumber){
		cout << "Congratulations! This is the right answer!" << endl;
		cout << endl;
	} else{
		cout << "Sorry, this is the wrong answer" << endl;
		cout << endl;
	}
}

void play(){
	char input[1000];

	do{
		int randomQustionIndex = chooseRandom(10);

		//get random question from database
		Question currentQuestion = questions[randomQustionIndex];
		printQuestion(currentQuestion, -1, -1);

		//50/50 if input is 'yes'
		cout << "Do you want to use 50/50? (yes/any key)" << endl;
		cin.getline(input, 1000);
		cout << endl;

		// there will be 50/50
		if(strcmp(input, "yes") == 0){
			int answer1Index = -1;
			int answer2Index = -1;

			//there have to be 2 different random answers, different from the right one
			do{
				answer1Index = chooseRandom(4) + 1;
				answer2Index = chooseRandom(4) + 1;
			} while(answer1Index == answer2Index || answer1Index == currentQuestion.trueAnswerNumber || answer2Index == currentQuestion.trueAnswerNumber);

			//print question without those two answers
			printQuestion(currentQuestion, answer1Index, answer2Index);

			//if the answers which were removed by 50/50 are 'before' the right one, the index of the right one will be lowered
			if(answer1Index < currentQuestion.trueAnswerNumber || answer2Index < currentQuestion.trueAnswerNumber){
				if(answer1Index < currentQuestion.trueAnswerNumber && answer2Index < currentQuestion.trueAnswerNumber){
					currentQuestion.trueAnswerNumber -= 2;
				} else{
					currentQuestion.trueAnswerNumber--;
				}
			}
			//user chooses answer
			chooseAnswer(currentQuestion.trueAnswerNumber, 'A', 'B');
			
		} else{
			//print question with all the answers
			printQuestion(currentQuestion, -1, -1);

			//user chooses answer
			chooseAnswer(currentQuestion.trueAnswerNumber, 'A', 'D');
		}

		//play again if input is 'yes'
		cout << "Do you want to play again? (yes/any key)" << endl;

		cin.ignore();
		cin.getline(input, 1000);
		cout << endl;
	} while(strcmp(input, "yes") == 0);
}

int main(){
	play();

	system("pause");

	return 1;
}