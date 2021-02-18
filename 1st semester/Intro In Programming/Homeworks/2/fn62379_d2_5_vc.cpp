/**
*
* Solution to homework assignment 2
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

#include <iostream>

using namespace std;


bool matrixIsFound = false;

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


int parseInt(){ // fixed version of the one in the slides
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
	} while(!isInt);

	return intNumber;
}


bool isSorted(int** matrix, int size){
	for(int j = 0; j < size - 1; j++){
		//check if the current element is bigger than the next one on the diagonal
		if(matrix[j][j] - '0' > matrix[j + 1][j + 1] - '0'){
			return false;
		}
	}
	return true;
}


void swapTwoRows(int **row1, int **row2){
	//swap the two rows in the matrix
	int *temp = *row1;
	*row1 = *row2;
	*row2 = temp;
}


void printÌatrix(int** matrix, int size){
	//print the matrix
	for(int i = 0; i < size; i++){
		cout << "[";
		for(int j = 0; j < size; j++){
			cout << matrix[i][j];
			if(j != size - 1){
				cout << " ";
			}
		}
		cout << "]";
		cout << endl;
	}
	cout << endl;
}


void printValidPermutationsOfMatrixRows(int** matrix, int start, int end){
	//ground state
	if(start == end){
		if(isSorted(matrix, end + 1) && !matrixIsFound){
			//so we will print only the first found valid matrix
			matrixIsFound = true;
			printÌatrix(matrix, end + 1);
		}
		return;
	}
	for(int i = start; i <= end; i++){
		//swapping rows
		swapTwoRows((matrix + i), (matrix + start));

		//fixing one first row and calling this function on the rest of the rows
		printValidPermutationsOfMatrixRows(matrix, start + 1, end);
		swapTwoRows((matrix + i), (matrix + start));
	}
}


int main(){
	cout << "Enter the number of rows and columns of the matrix (between 1 and 10): ";

	//read the number of rows and columns of the matrix
	int size = parseInt(1, 10);

	//initialize matrix
	int** matrix = new int*[size];
	for(int i = 0; i < size; i++){
		matrix[i] = new int[size];
	}

	cout << "Enter matrix: " << endl;

	//fill the matrix
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){
			matrix[i][j] = parseInt();
		}
	}
	cout << endl; 
		
	printValidPermutationsOfMatrixRows(matrix, 0, size - 1);

	if(!matrixIsFound){
		cout << "The rows of the matrix cannot be rearranged so that the matrix is valid." << endl;
	}

	//delete elements from memory
	for(int i = 0; i < size; i++){
		delete[] matrix[i];
	}

	delete[] matrix;

	return 1;
}