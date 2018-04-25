#include <iostream>
#include <iomanip>
#include <assert.h>
#include <string>
#include "Matrix.h"


using namespace std;
const string divider = "______________________________________\n";

//Create a matrix with a default constructor and test that all methods work properly
void testDefaultMatrix();
void testCopyOperator();
void testOverloadedMatrix(int r, int c, vector<int> d);
void testAntiDiag();
void testDiag();

int main(int argc, char** argv){
	testDefaultMatrix();

	int rows = 2;
	int cols = 5;
	vector<int> d = {3, 7, 19, 12, 8, 13, 105};
	testOverloadedMatrix(rows, cols, d);
	testCopyOperator();
	testAntiDiag();
	testDiag();






	




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
	for (int i = 1; i <= data.getNumRows(); i++) {
		assert(data.printRow(i) == 0);
	}
	cout << "Testing row bounds:\n";
	assert(data.printRow(0) == -1);
	assert(data.printRow(data.getNumRows()+1) == -1);

	//test columns
	cout << "Printing all columns of default matrix:\n";
	for (int i = 1; i <= data.getNumColumns(); i++) {
		assert(data.printColumn(i) == 0);
		cout << "\n";
	}
	assert(data.printColumn(0) == -1);
	assert(data.printColumn(data.getNumColumns()+1) == -1);

	//test properties
	assert(data.isSquare());
	assert(data.getNumRows() == 3);
	assert(data.getNumColumns() == 3);
	assert(data.getElementCount() == 9);
}

void testOverloadedMatrix(int r, int c, vector<int> d) {
	cout << "\nTesting overloaded Matrix:\n" << divider;
	Matrix data{r, c, d};

	data.printMatrix();

	//test rows
	cout << "Printing all rows of default matrix:\n";
	for (int i = 1; i <= data.getNumRows(); i++) {
		assert(data.printRow(i) == 0);
	}
	cout << "Testing row bounds:\n";
	assert(data.printRow(0) == -1);
	assert(data.printRow(data.getNumRows()+1) == -1);

	//test columns
	cout << "Printing all columns of default matrix:\n";
	for (int i = 1; i <= data.getNumColumns(); i++) {
		assert(data.printColumn(i) == 0);
		cout << "\n";
	}
	assert(data.printColumn(0) == -1);
	assert(data.printColumn(data.getNumColumns()+1) == -1);

}

void testCopyOperator() {
	cout << "\nTesting Matrix copy operator:\n" << divider;

	//Create source Matrix
	vector<int> v {1,5,10,12,13, 7};
	Matrix src {2, 3, v};
	cout << "Printing original matrix:\n";
	src.printMatrix();

	//Copy Matrix and confirm they are the same
	Matrix dest{};
	assert (src != dest);
	cout << "\nPrinting a default matrix:\n";
	dest.printMatrix();
	dest = src;
	cout << "\nPrinting copied matrix:\n";
	dest.printMatrix();

	assert(src==dest);
}

void testAntiDiag() {
	cout << "\nTesting creating antidiagonal matrixes:\n" << divider;
	vector<int> v{};
	for (int i = 100; i > 0; i--)
		v.push_back(i);

	Matrix src{10, 10, v};
	Matrix ad = src;

	cout << "\nTesting diag():\n";
	src.printMatrix();
	cout << "\nPrinting Anti-Diagonal\n";
	ad = antidiag(src);

	//test properties
	assert(src.isSquare() == ad.isSquare());
	assert(src.getNumRows() == ad.getNumRows());
	assert(src.getNumColumns() == ad.getNumColumns());
	assert(src.getElementCount() == ad.getElementCount());

	ad.printMatrix();
}

