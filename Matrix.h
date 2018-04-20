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

private:
	std::vector<std::vector<int> > data;
	int rows;
	int cols;
	int elemCount;

};

//return a given matrix rotated 90 degrees
int** rot90(int** m, int rows, int cols);

#endif 