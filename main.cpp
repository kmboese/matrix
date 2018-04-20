#include <iostream>
#include <iomanip>
#include "Matrix.h"


using namespace std;

int main(int argc, char** argv){

	Matrix data{};
	data.printMatrix();

	cout << "Printing Rows:\n";
	data.printRow(3);
	cout << "Printing Columns:\n";
	data.printColumn(4);
	cout << endl;




	cout << "Generating dynamic 2D array:\n";
	char lBoundingChar = '[';
	char rBoundingChar = ']';
	int rows = 5;
	int cols = 5;
	int matSize = rows*cols;
	int *mat = (int *)malloc(sizeof(int) * matSize); //allocate space for 9 elements
	for (int i = 0; i < rows; i++) {
		cout << lBoundingChar;
		for (int j = 0; j < cols; j++) {
			*(mat + i*rows + j) = (j+1) + i*rows;
			cout << setw(4) << *(mat + i*cols + j) << " ";
		}//end column loop
		cout << rBoundingChar << endl;
	}//end row loop


	// initMatrix(matrix, rows, cols);
	// printMatrix(matrix, rows, cols);
	
	return 0;
}

