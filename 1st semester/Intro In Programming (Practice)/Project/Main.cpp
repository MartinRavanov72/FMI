#include <iomanip> 
#include <iostream>
#include <string>
#include "Main.h"

using namespace std;

int main(){
	bool doesPlayAgain;

	do{
		//if you play more than once, you'll no longer see the previous games (so the console window won't become too long to scroll)
		system("cls");
		int difficulty = readDifficulty();
		if(difficulty == 1){
			//jump to the main solver function
			solveSudoku(EASY_SUDOKU);
			cout << "You completed level 1! Veeery weeeell!" << endl;
		} else if(difficulty == 2){
			//main solver function
			solveSudoku(MEDIUM_SUDOKU);
			cout << "You completed level 2! Daaaamn, gooooood joooob!" << endl;
		} else{
			//main solver function
			solveSudoku(HARD_SUDOKU);
			cout << "You completed level 3! You crazy..." << endl;
		}
		//after each game you can decide whether to play again or not
		doesPlayAgain = playsAgain();

	} while(doesPlayAgain);

	cout << "End of game. You did really great!" << endl;
	return 1;
}