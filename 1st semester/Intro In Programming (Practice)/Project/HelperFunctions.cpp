#include <iomanip> 
#include <iostream>
#include <string>

using namespace std;

int parseDifficulty(int lowerBound, int upperBound){  // fixed version of the parser function in the slides, lower- and upperBound added
	int intNumber;
	bool isInt = true;

	do{
		isInt = true;
		cin >> intNumber;
		//should be an integer
		if(cin.fail()){
			isInt = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid integer (" << lowerBound << "-" << upperBound << ")." << endl;
			continue;
		}

		//should be within the constraints
		if((intNumber < lowerBound) || (intNumber > upperBound)){
			
			cout << "Invalid difficulty. Difficulty should be between " << lowerBound << " and " << upperBound << ". Try again:" << endl;
		}
	} while(!isInt || (intNumber < lowerBound) || (intNumber > upperBound));

	return intNumber;
}

int parseRowColumn(int lowerBound, int upperBound){  // fixed version of the parser function in the slides, lower- and upperBound added
	int intNumber;
	bool isInt = true;

	do{
		isInt = true;
		cin >> intNumber;
		//should be an integer 
		if(cin.fail()){
			isInt = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid integer (" << lowerBound << "-" << upperBound << ")." << endl;
			continue;
		}

		//should be within the constraints
		if((intNumber < lowerBound) || (intNumber > upperBound)){
			cout << "Invalid move. Position should be between " << lowerBound << " and " << upperBound << ". Try again:" << endl;
		}
	} while(!isInt || (intNumber < lowerBound) || (intNumber > upperBound));

	return intNumber;
}

int parseNumber(int lowerBound, int upperBound){  // fixed version of the parser function in the slides, lower- and upperBound added
	int intNumber;
	bool isInt = true;

	do{
		isInt = true;
		cin >> intNumber;
		//should be an integer 
		if(cin.fail()){
			isInt = false;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter a valid integer (" << lowerBound << "-" << upperBound << ")." << endl;
			continue;
		}

		//should be within the constraints
		if((intNumber < lowerBound) || (intNumber > upperBound)){
			cout << "Invalid move. Number should be between " << lowerBound << " and " << upperBound << ". Try again:" << endl;
		}
	} while(!isInt || (intNumber < lowerBound) || (intNumber > upperBound));

	return intNumber;
}

int readDifficulty(){
	cout << "Choose difficulty to play : 1 = easy, 2 = medium, 3 = hard." << endl;
	return parseDifficulty(1, 3);
}

bool playsAgain(){
	string str;

	//plays again if user enters "yes"
	cout << "Do you wanna play again? (yes/no): ";
	cin >> str;
	if(str == "yes"){
		return true;
	}
	return false;
}

bool isValidMove(int sudoku[9][9], int row, int column){
	//the element on the selected row and column
	if(sudoku[row][column] == 0){
		return true;
	}
	return false;
}

bool sudokuIsFilled(int sudoku[9][9]){
	//there is no empty slot(isn't == 0)
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 9; j++){
			if(sudoku[i][j] == 0){
				return false;
			}
		}
	}
	return true;
}

bool validateRow(int sudoku[9][9], int row, int number){
	for(int i = 0; i < 9; i++){
		//since the numbers, entered by the user, are kept in the sudoku as it's value + 10, we should subtract 10 from these numbers
		if(sudoku[row][i] > 10){
			sudoku[row][i] -= 10;
		}
		//there should be no equal element on this row 
		if(sudoku[row][i] == number){
			return false;
		}
	}
	return true;
}

bool validateColumn(int sudoku[9][9], int column, int number){
	for(int i = 0; i < 9; i++){
		//since the numbers, entered by the user, are kept in the sudoku as it's value + 10, we should subtract 10 from these numbers
		if(sudoku[i][column] > 10){
			sudoku[i][column] -= 10;
		}
		//there should be no equal element on this column 
		if(sudoku[i][column] == number){
			return false;
		}
	}
	return true;
}

bool validateSquare(int sudoku[9][9], int row, int column, int number){ 
	//determines which one of the 9 big squares we're gonna start from

	//first, the row
	//for 0, 1, 2 we get the 0th square
	int startX = row / 3;
	//for 3, 4, 5 we get the 1st square
	startX = startX == 1 ? startX += 2 : startX;
	//for 6, 7, 8 we get the 1st square
	startX = startX == 2 ? startX += 4 : startX;

	//then, the column
	int startY = column / 3;
	startY = startY == 1 ? startY += 2 : startY;
	startY = startY == 2 ? startY += 4 : startY;

	for(int k = startX; k < startX + 3; k++){
		for(int l = startY; l < startY + 3; l++){
			//since the numbers, entered by the user, are kept in the sudoku as it's value + 10, we should subtract 10 from these numbers
			if(sudoku[k][l] > 10){
				sudoku[k][l] -= 10;
			}
			//there should be no equal element in this square
			if(sudoku[k][l] == number){
				return false;
			}
		}
	}
	return true;
}

void printSudoku(int sudoku[9][9]){
	cout << endl;
	cout << "     ";
	//print the rows' numbers
	for(int i = 0; i < 9; i++){
		cout << i << ")";
	}

	cout << endl;
	cout << endl;

	for(int i = 0; i < 9; i++){
		//print the columns' numbers
		cout << i << ")   ";

		for(int j = 0; j < 9; j++){
			//zeros should be represented as a black space, aka _
			if(sudoku[i][j] == 0){
				cout << "_" << " ";
			} else if(sudoku[i][j] > 10){ //since the numbers, entered by the user, are kept in the sudoku as it's value + 10, we should subtract 10 from these numbers
				cout << sudoku[i][j] - 10 << " ";
			} else{
				cout << sudoku[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}