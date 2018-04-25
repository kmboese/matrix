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
void testDiag();
void testAntiDiag();
void testAddition();
void testInsert();

int main(int argc, char** argv){
	testDefaultMatrix();

	int rows = 2;
	int cols = 5;
	vector<int> d = {3, 7, 19, 12, 8, 13, 105};
	testOverloadedMatrix(rows, cols, d);
	testCopyOperator();
	testDiag();
	testAntiDiag();
	testAddition();
	testInsert();

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

void testDiag() {
	cout << "\nTesting creating diagonal matrixes:\n" << divider;
	vector<int> v{1,5,10,15,20,25,30,35,40,45};

	Matrix src{3,3,v};
	Matrix d = src;
	cout << "\nOriginal Matrix:\n";
	src.printMatrix();

	//Assign the diagonal
	d = diag(src);

	//test properties
	assert(src.isSquare() == d.isSquare());
	assert(src.getNumRows() == d.getNumRows());
	assert(src.getNumColumns() == d.getNumColumns());
	assert(src.getElementCount() == d.getElementCount());

	cout << "\nDiagonal Matrix:\n";
	d.printMatrix();
}

void testAntiDiag() {
	cout << "\nTesting creating antidiagonal matrixes:\n" << divider;
	vector<int> v{};
	for (int i = 100; i > 0; i--)
		v.push_back(i);

	Matrix src{10, 10, v};
	Matrix ad = src;

	cout << "\nTesting antidiag():\n";
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

void testAddition() {
	cout << "\nTesting matrix addition:\n" << divider;
	vector<int> tmp {2,3,5,7,9,11,13,17,19};
	Matrix a{};
	Matrix b{3, 3, tmp};
	Matrix c = a + b;

	cout << "Matrix A:\n";
	a.printMatrix();
	cout << "Matrix B:\n";
	b.printMatrix();
	cout << "Matrix C (A+B):\n";
	c.printMatrix();

	//Check element-by-element sums
	for (int i = 1; i <= c.getNumRows(); i++) {
		vector<int> aRow = a.getRow(i);
		vector<int> bRow = b.getRow(i);
		vector<int> cRow = c.getRow(i);
		for (int j = 0; j < c.getNumColumns(); j++) {
			assert(cRow[j] == (aRow[j] + bRow[j]));
		}
	}
}

void testInsert() {
	cout << "\nTesting matrix insertion:\n" << divider;
	Matrix m{};
	cout << "Original Matrix:\n";
	m.printMatrix();

	for (int i = 1; i <= m.getNumRows(); i++) {
		for (int j = 1; j <= m.getNumColumns(); j++) {
			m.insert(i,j,13);
		}
	}
	cout << "New Matrix\n";
	m.printMatrix();
}



