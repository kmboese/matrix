#include <iostream>
#include <iomanip>
#include <assert.h>
#include <string>
#include "Matrix.h"
#include "Matrix.cpp" //necessary for the source to have the template implementation


using namespace std;
const string divider = "______________________________________\n";

//Create a matrix with a default constructor and test that all methods work properly
void testDefaultMatrix();
void testCopyOperator();
template <class T>
void testOverloadedMatrix(int r, int c, vector<T> d);
void testDiag();
void testAntiDiag();
void testAddition();
void testInsert();

int main(int argc, char** argv){
	Matrix<int> m{};
	m.print();
	testDefaultMatrix();

	int rows = 2;
	int cols = 5;
	vector<float> d = {3.3, 7.1, 19.2, 12.3, 8.4, 13.5, 105.9};
	testOverloadedMatrix(rows, cols, d);
	testCopyOperator();

	//Test string matrix
	vector<string> text = {"Hello", "there", "ladies", "and", 
							"gentlemen", "."};
	Matrix<string> stringy{2, 3, text};
	cout << "\nPrinting string matrix: \n";
	stringy.print();
	testDiag();
	testAntiDiag();
	testAddition();
	testInsert();

	return 0;
}


void testDefaultMatrix() {
	cout << "Testing default matrix:\n" << divider;
	Matrix<int> data{};
	data.print();

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
	cout << "Testing column bounds:\n";
	assert(data.printColumn(0) == -1);
	assert(data.printColumn(data.getNumColumns()+1) == -1);

	//test properties
	assert(data.isSquare());
	assert(data.getNumRows() == 3);
	assert(data.getNumColumns() == 3);
	assert(data.getElementCount() == 9);
}

template <class T>
void testOverloadedMatrix(int r, int c, vector<T> d) {
	cout << "\nTesting overloaded Matrix:\n" << divider;
	Matrix<T> data{r, c, d};

	data.print();

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
	cout << "Testing column bounds:\n";
	assert(data.printColumn(0) == -1);
	assert(data.printColumn(data.getNumColumns()+1) == -1);

}
void testCopyOperator() {
	cout << "\nTesting Matrix copy operator:\n" << divider;

	//Create source Matrix
	vector<double> v {1.1,5.7,10.1234,12.56,13.13, 7.9684};
	Matrix<double> src {2, 3, v};
	cout << "Printing original matrix:\n";
	src.print();

	//Copy Matrix and confirm they are the same
	Matrix<double> dest{};
	assert (src != dest);
	cout << "\nPrinting a default matrix:\n";
	dest.print();
	dest = src;
	cout << "\nPrinting copied matrix:\n";
	dest.print();

	assert(src==dest);
}


void testDiag() {
	cout << "\nTesting creating diagonal matrixes:\n" << divider;
	vector<int> v{1,5,10,15,20,25,30,35,40,45};

	Matrix<int> src{3,3,v};
	Matrix<int> d = src;
	cout << "\nOriginal Matrix:\n";
	src.print();

	//Assign the diagonal
	d = diag(src);

	//test properties
	assert(src.isSquare() == d.isSquare());
	assert(src.getNumRows() == d.getNumRows());
	assert(src.getNumColumns() == d.getNumColumns());
	assert(src.getElementCount() == d.getElementCount());

	cout << "\nDiagonal Matrix:\n";
	d.print();
}

void testAntiDiag() {
	cout << "\nTesting creating antidiagonal matrixes:\n" << divider;
	vector<int> v{};
	for (int i = 1; i <= 100; i++)
		v.push_back(i);

	Matrix<int> src{10, 10, v};
	Matrix<int> ad = src;

	cout << "\nTesting antidiag():\n";
	src.print();
	cout << "\nPrinting Anti-Diagonal\n";
	ad = antidiag(src);

	//test properties
	assert(src.isSquare() == ad.isSquare());
	assert(src.getNumRows() == ad.getNumRows());
	assert(src.getNumColumns() == ad.getNumColumns());
	assert(src.getElementCount() == ad.getElementCount());

	ad.print();
}

void testAddition() {
	cout << "\nTesting matrix addition:\n" << divider;
	vector<int> tmp {2,3,5,7,9,11,13,17,19};
	Matrix<int> a{};
	Matrix<int> b{3, 3, tmp};
	Matrix<int> c = a + b;

	cout << "Matrix A:\n";
	a.print();
	cout << "Matrix B:\n";
	b.print();
	cout << "Matrix C (A+B):\n";
	c.print();

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
	Matrix<int> m{10,10};
	cout << "Original Matrix:\n";
	m.print();

	for (int i = 1; i <= m.getNumRows(); i++) {
		for (int j = 1; j <= m.getNumColumns(); j++) {
			m.insert(i,j,13);
		}
	}
	cout << "New Matrix\n";
	m.print();
}
