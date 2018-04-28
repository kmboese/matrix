# Matrix
A matrix class in C++.

# Functions:
* Constructors:
	* Default Constructor: creates a 3x3 matrix with elements 1-9
	* Overloaded Constructor 1: creates a matrix of given rows and columns with 
	all elements as zeroes.
	* Overloaded Constructor 2: creates a matrix of given rows and columns, using 
	a vector of elements as the data.
* Accessors:
	* getRow()
	* getColumn()
	* getNumRows()
	* getNumColumns()
	* getElementCount()
* Mutators:	
	* insert(): insert an element into a given row and columns
* Identity Functions:
	* isSquare()
* toString methods:
	* print(): Prints a matrix using bracketed formatting
	* printRow()
	* printColumn()

* Overloaded Operators:
	* =
	* == 	: checks element equality
	* != 	: checks element inequality
	* \+ 	: matrix addition
	* \-	: matrix subtraction
	* *	: matrix multiplication
