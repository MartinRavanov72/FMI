#include <iomanip> 
#include <iostream>
#include <string>
#include "Solver.h"

using namespace std;

void solveSudoku(int sudoku[9][9]){
	cout << "Here's your sudoku." << endl;
	bool isFilled = sudokuIsFilled(sudoku);
	do{
		printSudoku(sudoku);

		//read number and position
		cout << "Enter row (0-8):";
		int row = parseRowColumn(0, 8);

		cout << "Enter column (0-8):";
		int column = parseRowColumn(0, 8);

		//could be 0, because we can erase numbers on the current position
		cout << "Enter number (0-9):";
		int number = parseNumber(0, 9);

		if(number == 0){ //erase the number on the current position
			if(sudoku[row][column] > 10){ //it's a number the user has entered, since the numbers, entered by the user, are kept in the sudoku as it's value + 10
				sudoku[row][column] = number;

				cout << "You cleared the number on position " << row << " " << column << "." << endl;
				continue;
			} else if(sudoku[row][column] == 0){ //it's empty space
				cout << "You can't put 0 in the free spaces. Try again:" << endl;
				continue;
			} else{ //number is one of the already given ones
				cout << "You can't clear the numbers that were already given. Try again:" << endl;
				continue;
			}
		} else{
			//validate the input
			bool isValidInput = isValidMove(sudoku, row, column);
			
			if(!isValidInput){
				cout << "Invalid move. " << number << " cannot be written on position " << row << " " << column << ". There's already a number there. Try again:" << endl;
				continue;
			}
			
			//validate the move
			bool validRow = validateRow(sudoku, row, number);
			bool validColumn = validateColumn(sudoku, column, number);
			bool validSquare = validateSquare(sudoku, row, column, number);

			if(!validColumn || !validRow || !validSquare){
				cout << "Invalid move. " << number << " cannot be written on position " << row << " " << column << ". Try again:" << endl;
				continue;
			}

			//place the number in the matrix as it's value + 10, so we can distinguish them from the already given ones
			sudoku[row][column] = number + 10;
			cout << "You placed " << number << " on position " << row << " " << column << "." << endl;
		}

		isFilled = sudokuIsFilled(sudoku); //check if the sudoku is filled
	} while(!isFilled);
}