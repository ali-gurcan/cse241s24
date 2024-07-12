#ifndef _SPARSE_VECTOR_H
#define _SPARSE_VECTOR_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent non-zero elements in the sparse vector
struct datatype {
    int index;      // Index of the element
    double data;    // Value of the element
};

class SparseVector {
public:
    // Constructors
    SparseVector();                     // Default constructor
    SparseVector(string filename);     // Constructor to load vector from file

    // Overloaded operators
    const SparseVector operator+(const SparseVector& sparse_vec) const;   // Addition
    const SparseVector operator-(const SparseVector &sparse_vec) const;   // Subtraction
    const SparseVector operator-() const;                                 // Unary negation
    const SparseVector &operator=(const SparseVector &sparse_vec);        // Assignment
    friend ostream &operator<<(ostream &out, const SparseVector &sparse_vec); // Output
    friend double dot(const SparseVector &sparse_vec1, const SparseVector &sparse_vec2); // Dot product

private:
    vector<datatype> alldata;    // Vector to store non-zero elements
};

#endif
