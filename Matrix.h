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
	/* Overloaded constructor: 
	 * r: number of rows
	 * c: number of columns
	 * d: vector of ints for matrix to hold. If the number of elements in d is less than the number of elements in the matrix, fill the rest of the matrix values with zero.
	 */
	Matrix(int r, int c, std::vector<int> &d);
	/* Prints a matrix consisting of the main diagonal (top-left to bottom-right) of the matrix, with the rest of the elements as zero.
	 * Returns: 0 if the matrix is square, -1 otherwise
	 */
	int diag();

	/* Prints a matrix consisting of the anti-diagonal (bottom-left to 
	 * top-right) of the matrix, with the rest of the elements as zero.
	 * Returns: 0 if the matrix is square, -1 otherwise (fails to print diagonal)
	 */
	Matrix antidiag(Matrix &m);
	/* Returns: an int containing the number of rows of a matrix */
	int getRows() const;
	/* Returns: an int containing the number of columns of a matrix*/
	int getColumns();
	/* Returns: true if matrix is square, false otherwise */
	bool isSquare();
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

private:
	std::vector<std::vector<int> > data;
	int rows;
	int cols;
	int elemCount;
	bool square;

};

//return a given matrix rotated 90 degrees
int** rot90(int** m, int rows, int cols);

#endif 