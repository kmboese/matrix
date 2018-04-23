#include <iostream>
#include <iomanip>
#include <assert.h>
#include <string>
#include "Matrix.h"


using namespace std;
const string divider = "______________________________________\n";

//Create a matrix with a default constructor and test that all methods work properly
void testDefaultMatrix();
void testOverloadedMatrix(int r, int c, vector<int> d);

int main(int argc, char** argv){
	testDefaultMatrix();

	int rows = 2;
	int cols = 5;
	vector<int> d = {3, 7, 19, 12, 8, 13, 105};
	testOverloadedMatrix(rows, cols, d);

	vector<int> v{};
	for (int i = 100; i > 0; i--)
		v.push_back(i);
	Matrix defaultMatrix{10, 11, v};
	cout << "\nTesting diag():\n";
	defaultMatrix.printMatrix();
	cout << "\nPrinting Anti-Diagonal\n";
	// defaultMatrix.antidiag();

	




	/* 
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
	*/
	
	return 0;
}

void testDefaultMatrix() {
	cout << "Testing default matrix:\n" << divider;
	Matrix data{};
	data.printMatrix();

	//test rows
	cout << "Printing all rows of default matrix:\n";
	for (int i = 1; i <= data.getRows(); i++) {
		assert(data.printRow(i) == 0);
	}
	cout << "Testing row bounds:\n";
	assert(data.printRow(0) == -1);
	assert(data.printRow(data.getRows()+1) == -1);

	//test columns
	cout << "Printing all columns of default matrix:\n";
	for (int i = 1; i <= data.getColumns(); i++) {
		assert(data.printColumn(i) == 0);
		cout << "\n";
	}
	assert(data.printColumn(0) == -1);
	assert(data.printColumn(data.getColumns()+1) == -1);
}

void testOverloadedMatrix(int r, int c, vector<int> d) {
	cout << "\nTesting overloaded Matrix:\n" << divider;
	Matrix data{r, c, d};

	data.printMatrix();

	//test rows
	cout << "Printing all rows of default matrix:\n";
	for (int i = 1; i <= data.getRows(); i++) {
		assert(data.printRow(i) == 0);
	}
	cout << "Testing row bounds:\n";
	assert(data.printRow(0) == -1);
	assert(data.printRow(data.getRows()+1) == -1);

	//test columns
	cout << "Printing all columns of default matrix:\n";
	for (int i = 1; i <= data.getColumns(); i++) {
		assert(data.printColumn(i) == 0);
		cout << "\n";
	}
	assert(data.printColumn(0) == -1);
	assert(data.printColumn(data.getColumns()+1) == -1);

}

