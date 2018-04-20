#include <iostream>
#include "Matrix.h"

Matrix::Matrix() {
	rows = 3;
	cols = 3;
	elemCount = rows*cols;
	for (int i = 0; i < rows; i++){
		std::vector<int> v{};
		for (int j = 0; j < cols; j++){
			v.push_back(0);
		}
		data.push_back(v); //add the row to the matrix
	}
}

void Matrix::printMatrix() {
	std::cout << "Printing Matrix:\n";
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			std::cout << data[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int** rot90(int** m, int rows, int cols){
	int** ret{};
	std::cout << "Hello, world!\n";

	return ret;
}