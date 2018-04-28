#ifndef MATRIX
#define MATRIX

#include <vector>

template <class T>
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
	Matrix(int r, int c, std::vector<T> &d);

	/* Returns: the element at the given row and column */
	T getElement(int r, int c) const;
	/* Returns: a vector containg the given row, 1-indexed */
	std::vector<T> getRow(int r) const;
	/* Returns: a vector containing the given column, 1-indexed */
	std::vector<T> getColumn(int c) const;
	/* Returns: an int containing the number of rows of a matrix */
	int getNumRows() const;
	/* Returns: an int containing the number of columns of a matrix*/
	int getNumColumns() const;
	/* Returns: an int containing the number of elements in the matrix*/
	int getElementCount() const;
	/* Inserts an integer in the given row and column position */
	void insert(int r, int c, T n);
	/* Returns: true if matrix is square, false otherwise */
	bool isSquare() const;
	/* Prints an entire matrix object, surrounded by brackets, 
	 * with one row per line
	 */
	void print();
	/* Prints a given row of a matrix, 1-indexed 
	 * Returns: 0 if given row is valid, -1 otherwise.*/
	int printRow(int r);
	/* Prints a given column of a matrix, 1-indexed 
	 * Returns: 0 if given column is valid, -1 otherwise.
	 */
	int printColumn(int c);

	/* Overloaded Operators */
	void operator= (const Matrix<T> &rhs);
	bool operator== (const Matrix<T> &rhs);
	bool operator!= (const Matrix<T> &rhs);
	Matrix<T> operator+ (const Matrix<T> &rhs);
	Matrix<T> operator- (const Matrix<T> &rhs);

	/* Static Methods */
	static Matrix<T> diag(Matrix<T> &m);
	static Matrix<T> antidiag(Matrix<T> &m);

private:
	// std::vector<std::vector<int> > data;
	std::vector<std::vector<T> > data;

	int rows;
	int cols;
	int elemCount;
	bool square;

};

/* Returns: a matrix consisting of the main diagonal (top-left to
 * bottom-right) of the matrix, with the rest of the elements as zero.
 */
// template <class T>
// Matrix<T> diag(Matrix<T> &m);
/* Returns: a matrix consisting of the anti-diagonal (bottom-left to 
 * top-right) of the matrix, with the rest of the elements as zero.
 */
// template <class T>
// Matrix<T> antidiag(Matrix<T> &m);

#endif 