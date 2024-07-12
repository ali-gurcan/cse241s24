#ifndef _SPARSE_MATRIX_H
#define _SPARSE_MATRIX_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Structure to represent non-zero elements in the sparse matrix
struct matrixdatatype {
    int row_index;  // Row index of the element
    int index;      // Column index of the element
    double data;    // Value of the element
};

class SparseMatrix {
public:
    // Constructors
    SparseMatrix();             // Default constructor
    SparseMatrix(string filename);  // Constructor to load matrix from file

    // Overloaded operators
    const SparseMatrix operator+(const SparseMatrix &sparse_matrix) const;   // Addition
    const SparseMatrix operator-(const SparseMatrix &sparse_matrix) const;   // Subtraction
    const SparseMatrix operator-() const;                                     // Unary negation
    const SparseMatrix &operator=(const SparseMatrix &sparse_matrix);          // Assignment
    const SparseMatrix operator*(const SparseMatrix &sparse_matrix) const;     // Multiplication
    friend ostream& operator<<(ostream &out, const SparseMatrix &sparse_matrix);   // Output
    const SparseMatrix transpose();    // Transpose

private:
    vector<matrixdatatype> storage_matrix;    // Vector to store non-zero elements
};

#endif
