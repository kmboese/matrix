#include <iostream>
#include <iomanip>
#include "Matrix.h"

const char lBoundingChar = '[';
const char rBoundingChar = ']';
const int formatWidth = 4; //text width for stdout formatting

Matrix::Matrix() {
	rows = 3;
	cols = 3;
	elemCount = rows*cols;
	square = true;
	for (int i = 0; i < rows; i++){
		std::vector<int> v{};
		for (int j = 0; j < cols; j++){
			v.push_back((j+1) + (i*rows));
		}
		data.push_back(v); //add the row to the matrix
	}
}

Matrix::Matrix(int r, int c, std::vector<int> &d)
	: rows{r}, cols{c}, square{rows==cols} {

		std::vector<int> tmp{};
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				//check that d is still valid
				//if (count > 0) {
				if (!d.empty()) {
					tmp.push_back(d.back());
					d.pop_back();
				}
				//if d is not valid, simply insert a zero
				else {
					tmp.push_back(0);
				}
			}
			data.push_back(tmp);
			tmp.clear();
		}
 }

int Matrix::diag() {
	if (!square){
		perror("Error: cannot print diagonal of non-square matrix\n");
		return -1;
	}
	return 0;
}

int Matrix::getNumRows() const {
	return rows;
}

int Matrix::getNumColumns() {
	return cols;
}

int Matrix::getElementCount() {
	return elemCount;
}

bool Matrix::isSquare() {
	return square;
}

void Matrix::printMatrix() {
	for (int i = 0; i < rows; i++){
		std::cout << lBoundingChar;
		for (int j = 0; j < cols; j++){
			std::cout << std::setw(formatWidth) << data[i][j];
		}
		std::cout << std::setw(formatWidth) << rBoundingChar << std::endl;
	}
}

int Matrix::printRow(int r) {
	//Check for valid row bounds
	if ( r > rows || r < 1) {
		std::cerr << "Error: invalid row number given\n";
		return -1;
	}

	std::vector<int> row = data[r-1];
	std::cout << lBoundingChar;
	for (int i = 0; i < cols; i++) {
		std::cout << std::setw(formatWidth) << row[i];
	}
	std::cout << std::setw(formatWidth) << rBoundingChar << std::endl;
	return 0;
}

int Matrix::printColumn(int c) {
	//check for valid column bounds
	if (c > cols || c < 1) {
		std::cerr << "Error: invalid column number given\n";
		return -1;
	}
	for (int i = 0; i < rows; i++) {
		std::cout << lBoundingChar;
		std::cout << std::setw(formatWidth) << data[i][c-1];
		std::cout << std::setw(formatWidth) << rBoundingChar << std::endl;
	}
	return 0;

}

void Matrix::operator= (const Matrix &rhs) {
	data = rhs.data;
	rows = rhs.rows;
	cols = rhs.cols;
	elemCount = rhs.elemCount;
	square = rhs.square;
}

bool Matrix::operator== (const Matrix &rhs) {
	return (data == rhs.data &&
			rows == rhs.rows &&
			cols == rhs.cols &&
			elemCount == rhs.elemCount &&
			square == rhs.square);
}

bool Matrix::operator!= (const Matrix &rhs) {
	return (!(*this == rhs));
}

/*Non-member functions */

Matrix antidiag(Matrix &m) {
	//Matrix must be square to print a diagonal
	if (!(m.isSquare() )) {
		perror("Error: cannot print anti-diagonal of non-square matrix\n");
		return m;
	}

	std::vector<int> tmp {};
	Matrix antidiag = m;
	

	int count = antidiag.cols; //keeps track of anti-diagonal values
	for (int i = 1; i <= antidiag.rows; i++) {
		for (int j = 1; j <= antidiag.cols; j++) {
			//only assign antidiagonal values
			if (j == count) {
				antidiag.data[i-1][j-1] = m.data[i-1][j-1];
				count--;
			}
			else {
				antidiag.data[i-1][j-1] = 0;
			}

		}
	}
	return antidiag;
}

int** rot90(int** m, int rows, int cols){
	int** ret{};
	std::cout << "Hello, world!\n";

	return ret;
}