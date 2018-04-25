#include <iostream>
#include <iomanip>
#include "Matrix.h"

const char lBoundingChar = '[';
const char rBoundingChar = ']';
const int formatWidth = 1; //text width for stdout formatting

template <class T>
Matrix<T>::Matrix() {
	rows = 3;
	cols = 3;
	elemCount = rows*cols;
	square = true;
	for (int i = 0; i < rows; i++){
		std::vector<T> v{};
		for (int j = 0; j < cols; j++){
			v.push_back((j+1) + (i*rows));
		}
		data.push_back(v); //add the row to the matrix
	}
}

template <class T>
Matrix<T>::Matrix(int r, int c, std::vector<T> &d)
	: rows{r}, cols{c}, square{r==c} {

		std::vector<T> tmp{};
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

template <class T>
Matrix<T>::Matrix(int r, int c) 
	: rows{r}, cols{c}, elemCount{r*c}, square{r==c} {
		for (int i = 0; i < rows; i++) {
			std::vector<T> v{};
			for (int j = 0; j < cols; j++) {
				v.push_back(0);
			}
			data.push_back(v);
		}
}

template <class T>
std::vector<T> Matrix<T>::getRow(int r) const {
	if (r < 1 || r > rows) {
		perror("Error: row access out of bounds!\n");
		exit(1);
	}
	return (data[r-1]);
}

template <class T>
std::vector<T> Matrix<T>::getColumn(int c) const {
	if (c < 1 || c > cols) {
		perror("Error: column access out of bounds!\n");
		exit(1);
	}
	std::vector<T> ret{};
	for (int i = 0; i < rows; i++) {
		ret.push_back(data[i][c-1]); //access the column elements, row by row
	}
	return ret;
}

template <class T>
int Matrix<T>::getNumRows() const {
	return rows;
}

template <class T>
int Matrix<T>::getNumColumns() const {
	return cols;
}

template <class T>
int Matrix<T>::getElementCount() const{
	return elemCount;
}

template <class T>
void Matrix<T>::insert(int r, int c, T n) {
	if ( (r < 1 || r > rows) || (c < 1 || c > cols) ) {
		perror("Error: invalid row or column given!\n");
		exit(1);
	}
	data[r-1][c-1] = n;
}

template <class T>
bool Matrix<T>::isSquare() const {
	return square;
}

template <class T>
void Matrix<T>::print() {
	for (int i = 0; i < rows; i++){
		std::cout << lBoundingChar;
		for (int j = 0; j < cols; j++){
			std::cout << std::setw(formatWidth) << data[i][j] << " ";
		}
		std::cout << std::setw(formatWidth) << rBoundingChar << std::endl;
	}
}

template <class T>
int Matrix<T>::printRow(int r) {
	//Check for valid row bounds
	if ( r > rows || r < 1) {
		std::cerr << "Error: invalid row number given!\n";
		return -1;
	}

	std::vector<T> row = data[r-1];
	std::cout << lBoundingChar;
	for (int i = 0; i < cols; i++) {
		std::cout << std::setw(formatWidth) << row[i];
	}
	std::cout << std::setw(formatWidth) << rBoundingChar << std::endl;
	return 0;
}

template <class T>
int Matrix<T>::printColumn(int c) {
	//check for valid column bounds
	if (c > cols || c < 1) {
		std::cerr << "Error: invalid column number given!\n";
		return -1;
	}
	for (int i = 0; i < rows; i++) {
		std::cout << lBoundingChar;
		std::cout << std::setw(formatWidth) << data[i][c-1];
		std::cout << std::setw(formatWidth) << rBoundingChar << std::endl;
	}
	return 0;
}

template <class T>
void Matrix<T>::operator= (const Matrix<T> &rhs) {
	data = rhs.data;
	rows = rhs.rows;
	cols = rhs.cols;
	elemCount = rhs.elemCount;
	square = rhs.square;
}

template <class T>
bool Matrix<T>::operator== (const Matrix<T> &rhs) {
	return (data == rhs.data &&
			rows == rhs.rows &&
			cols == rhs.cols &&
			elemCount == rhs.elemCount &&
			square == rhs.square);
}

template <class T>
bool Matrix<T>::operator!= (const Matrix<T> &rhs) {
	return (!(*this == rhs));
}

template <class T>
Matrix<T> Matrix<T>::operator+ (const Matrix<T> &rhs) {
	if (! (rows == rhs.rows) && (cols == rhs.cols) ) {
		perror("Error: Matrix dimensions must be identical to perform addition!\n");
		exit(1);
	}
	//add all elements and return result
	Matrix<T> m{rhs.rows, rhs.cols}; //the return matrix will have the same dimensions
	for (int i = 1; i <= rhs.rows; i++) {
		std::vector<T> r1 = this->getRow(i);
		std::vector<T> r2 = rhs.getRow(i);
		//sum the rows together
		for (unsigned int j = 0; j < r1.size(); j++) {
			r1[j] += r2[j];
		}
		m.data[i-1] = r1;
	}
	return m;
}

/*static functions */

template <class T>
static Matrix<T> diag(Matrix<T> &m) {
	if (!(m.isSquare())){
		perror("Error: cannot print diagonal of non-square matrix!\n");
		return m;
	}

	Matrix<T> diag = m;

	for (int i = 0; i < diag.rows; i++) {
		for (int j = 0; j < diag.cols; j++) {
			if (j == i) {
				diag.data[i][j] = m.data[i][j];
			}
			else {
				diag.data[i][j] = 0;
			}
		}
	}
	return diag;
}

template <class T>
static Matrix<T> antidiag(Matrix<T> &m) {
	//Matrix must be square to print a diagonal
	if (!(m.isSquare() )) {
		perror("Error: cannot print anti-diagonal of non-square matrix!\n");
		return m;
	}

	Matrix<T> antidiag = m; //size the antidiag matrix to the size of the original
	int count = antidiag.cols - 1; //keeps track of anti-diagonal values

	for (int i = 0; i < antidiag.rows; i++) {
		for (int j = 0; j < antidiag.cols; j++) {
			//only assign antidiagonal values
			if (j == count) {
				antidiag.data[i][j] = m.data[i][j];
				count--;
			}
			else {
				antidiag.data[i][j] = 0;
			}

		}
	}
	return antidiag;
}