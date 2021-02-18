#pragma once

int parseDifficulty(int, int);
int parseRowColumn(int, int);
int parseNumber(int, int);
bool isValidMove(int[9][9], int, int);
bool sudokuIsFilled(int[9][9]);
bool validateRow(int[9][9], int, int);
bool validateColumn(int[9][9], int, int);
bool validateSquare(int[9][9], int, int, int);
void printSudoku(int[9][9]);

