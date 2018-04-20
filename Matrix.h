#ifndef MATRIX
#define MATRIX

#include <vector>

class Matrix{
public:
	/* Default constructor: 
	 * rows: 3
	 * cols: 3
	 * values: all elements initialized to 0
	*/
	Matrix();
	void printMatrix();
	/* Prints a given row of a matrix, 1-indexed */
	void printRow(int r);
	/* Prints a given column of a matrix, 1-indexed */
	void printColumn(int c);

private:
	std::vector<std::vector<int> > data;
	int rows;
	int cols;
	int elemCount;

};

//return a given matrix rotated 90 degrees
int** rot90(int** m, int rows, int cols);

#endif 