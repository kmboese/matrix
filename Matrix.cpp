#include <iostream>
#include <iomanip>
#include "Matrix.h"

const char lBoundingChar = '[';
const char rBoundingChar = ']';

Matrix::Matrix() {
	rows = 3;
	cols = 3;
	elemCount = rows*cols;
	for (int i = 0; i < rows; i++){
		std::vector<int> v{};
		for (int j = 0; j < cols; j++){
			v.push_back((j+1) + (i*rows));
		}
		data.push_back(v); //add the row to the matrix
	}
}

void Matrix::printMatrix() {
	int formatWidth = 4;

	std::cout << "Printing Matrix:\n";
	for (int i = 0; i < rows; i++){
		std::cout << lBoundingChar;
		for (int j = 0; j < cols; j++){
			std::cout << std::setw(formatWidth) << data[i][j];
		}
		std::cout << std::setw(formatWidth) << rBoundingChar << std::endl;
	}
}

void Matrix::printRow(int r) {
	//Check for valid row bounds
	if ( r > rows || r < 1) {
		std::cerr << "Error: invalid row number given\n";
		return;
	}

	std::vector<int> row = data[r-1];
	std::cout << lBoundingChar;
	for (int i = 0; i < cols; i++) {
		if (i != 0)
			std::cout << " ";
		std::cout << row[i];
	}
	std::cout << rBoundingChar << std::endl;
}

void Matrix::printColumn(int c) {
	//check for valid column bounds
	if (c > cols || c < 1) {
		std::cerr << "Error: invalid column number given\n";
		return;
	}
	for (int i = 0; i < rows; i++) {
		std::cout << lBoundingChar;
		std::cout << data[i][c-1];
		std::cout << rBoundingChar << std::endl;

	}

}

int** rot90(int** m, int rows, int cols){
	int** ret{};
	std::cout << "Hello, world!\n";

	return ret;
}