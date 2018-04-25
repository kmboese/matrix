#ifndef MATRIX
#define MATRIX

#include <vector>

class Matrix{
public:
	/* Default constructor: 
	 * rows: 3
	 * cols: 3
	 * values: all elements initialized to ints 1-9
	*/
	Matrix();
	/* Overloaded constructor:
	 * r: number of rows
	 * c: number of columns
	 * All elements initalized to zero.
	 */
	Matrix(int r, int c);
	/* Overloaded constructor: 
	 * r: number of rows
	 * c: number of columns
	 * d: vector of ints for matrix to hold. If the number of elements in d is less than the number of elements in the matrix, fill the rest of the matrix values with zero.
	 */
	Matrix(int r, int c, std::vector<int> &d);

	/* Returns: a vector containg the given row, 1-indexed */
	std::vector<int> getRow(int r) const;
	/* Returns: a vector containing the given column, 1-indexed */
	std::vector<int> getColumn(int c) const;
	/* Returns: an int containing the number of rows of a matrix */
	int getNumRows() const;
	/* Returns: an int containing the number of columns of a matrix*/
	int getNumColumns() const;
	/* Returns: an int containing the number of elements in the matrix*/
	int getElementCount() const;
	/* Inserts an integer in the given row and column position */
	void insert(int r, int c, int n);
	/* Returns: true if matrix is square, false otherwise */
	bool isSquare() const;
	/* Prints an entire matrix object, surrounded by brackets, 
	 * with one row per line
	 */
	void printMatrix();
	/* Prints a given row of a matrix, 1-indexed 
	 * Returns: 0 if given row is valid, -1 otherwise.*/
	int printRow(int r);
	/* Prints a given column of a matrix, 1-indexed 
	 * Returns: 0 if given column is valid, -1 otherwise.
	 */
	int printColumn(int c);

	/* Overloaded Operators */
	void operator= (const Matrix &rhs);
	bool operator== (const Matrix &rhs);
	bool operator!= (const Matrix &rhs);
	Matrix operator+ (const Matrix &rhs);

	/* Friend Methods */
	friend Matrix diag(Matrix &m);
	friend Matrix antidiag(Matrix &m);

private:
	std::vector<std::vector<int> > data;
	int rows;
	int cols;
	int elemCount;
	bool square;

};

/* Returns: a matrix consisting of the main diagonal (top-left to
 * bottom-right) of the matrix, with the rest of the elements as zero.
 */
Matrix diag(Matrix &m);
/* Returns: a matrix consisting of the anti-diagonal (bottom-left to 
 * top-right) of the matrix, with the rest of the elements as zero.
 */
Matrix antidiag(Matrix &m);

//return a given matrix rotated 90 degrees
int** rot90(int** m, int rows, int cols);

#endif 