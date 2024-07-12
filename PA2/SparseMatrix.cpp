#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "SparseMatrix.h"

using namespace std;

//Default Constructor
SparseMatrix::SparseMatrix(){}

SparseMatrix::SparseMatrix(string filename)
{
    ifstream cinfile(filename); // Open file directly with constructor

    if (!cinfile.is_open()){
        cerr << "Error opening file " << filename << endl;
        return;
    }

    int row;
    char colon; // ':' character
    int index;
    double data;

    string line; // variable to store each line from the file

    //reading data from file line by line
    while (getline(cinfile, line)) 
    {
        istringstream lineStream(line); // create a stringstream from the line

        lineStream >> row; // Read the row index

        // Read (index:data) until the end of the line
        while (lineStream >> index >> colon >> data) {
            matrixdatatype temp;
            temp.row_index = row;
            temp.index = index;
            temp.data = data;
            storage_matrix.push_back(temp);
            // Check for end of line
            if (lineStream.peek() == '\n' || lineStream.peek() == EOF)
                break;  // Exit loop if end of line or end of file
        }
    }

    cinfile.close();
}


const SparseMatrix SparseMatrix::operator+(const SparseMatrix &sparse_matrix) const {
    SparseMatrix result; // Resultant SparseMatrix to hold the sum

    size_t i = 0, j = 0; // Index variables for iterating through storage_matrix and sparse_matrix

    //iterate through both storage matrices until one of them is fully traversed
    while (i < storage_matrix.size() && j < sparse_matrix.storage_matrix.size()) {
        //compare row indexes and indices to determine the order of elements
        if (storage_matrix[i].row_index < sparse_matrix.storage_matrix[j].row_index || 
            (storage_matrix[i].row_index == sparse_matrix.storage_matrix[j].row_index && storage_matrix[i].index < sparse_matrix.storage_matrix[j].index))
        {
            //if the element in the current SparseMatrix is before the one in sparse_matrix, add it to the result
            result.storage_matrix.push_back(storage_matrix[i]);
            i++;
        } 
        else if (storage_matrix[i].row_index > sparse_matrix.storage_matrix[j].row_index || 
                   (storage_matrix[i].row_index == sparse_matrix.storage_matrix[j].row_index && storage_matrix[i].index > sparse_matrix.storage_matrix[j].index))
        {
            // if the element in the current SparseMatrix is after the one in sparse_matrix add it to the result
            result.storage_matrix.push_back(sparse_matrix.storage_matrix[j]);
            j++;
        }
        else 
        {
            //if  elements are at the same position adds their values and push to the result
            result.storage_matrix.push_back({storage_matrix[i].row_index, storage_matrix[i].index, 
                                            storage_matrix[i].data + sparse_matrix.storage_matrix[j].data});
            i++;
            j++;
        }
    }

    //Add remaining elements from either matrix
    while (i < storage_matrix.size()) {
        result.storage_matrix.push_back(storage_matrix[i]);
        i++;
    }

    while (j < sparse_matrix.storage_matrix.size()) {
        result.storage_matrix.push_back(sparse_matrix.storage_matrix[j]);
        j++;
    }

    return result; 
}


const SparseMatrix SparseMatrix::operator-(const SparseMatrix &sparse_matrix) const {
    SparseMatrix result;  

    size_t i = 0, j = 0; //Index variables for iterating through storage_matrix and sparse_matrix

    //iterate through both storage matrices until one of them is fully traversed
    while (i < storage_matrix.size() && j < sparse_matrix.storage_matrix.size()) {
        //compare row indexes and indices to determine the order of elements
        if (storage_matrix[i].row_index < sparse_matrix.storage_matrix[j].row_index ||
            (storage_matrix[i].row_index == sparse_matrix.storage_matrix[j].row_index && storage_matrix[i].index < sparse_matrix.storage_matrix[j].index))
        {
            //if the element in the current SparseMatrix is before the one in sparse_matrix, add it to the result
            result.storage_matrix.push_back(storage_matrix[i]);
            i++;
        } 
        else if (storage_matrix[i].row_index > sparse_matrix.storage_matrix[j].row_index ||
                   (storage_matrix[i].row_index == sparse_matrix.storage_matrix[j].row_index && storage_matrix[i].index > sparse_matrix.storage_matrix[j].index)) 
        {
            //if the element in the current SparseMatrix is after the one in sparse_matrix, add the negated value to the result
            result.storage_matrix.push_back({sparse_matrix.storage_matrix[j].row_index, sparse_matrix.storage_matrix[j].index, -sparse_matrix.storage_matrix[j].data});
            j++;
        } 
        else 
        {
            //if the elements are at the same position, subtract their values and push to the result if non-zero
            double subtracted_value = storage_matrix[i].data - sparse_matrix.storage_matrix[j].data;
            if (subtracted_value != 0) {
                result.storage_matrix.push_back({storage_matrix[i].row_index, storage_matrix[i].index, subtracted_value});
            }
            i++;
            j++;
        }
    }

    //add remaining elements from the first matrix
    while (i < storage_matrix.size()) 
    {
        result.storage_matrix.push_back(storage_matrix[i]);
        i++;
    }

    //add remaining elements from the second matrix (negated)
    while (j < sparse_matrix.storage_matrix.size()) 
    {
        result.storage_matrix.push_back({sparse_matrix.storage_matrix[j].row_index, sparse_matrix.storage_matrix[j].index, -sparse_matrix.storage_matrix[j].data});
        j++;
    }

    return result;  
}


const SparseMatrix SparseMatrix::operator-() const {
    SparseMatrix negatedMatrix;

    //negating elements
    for (size_t i = 0; i < storage_matrix.size(); i++) {
        negatedMatrix.storage_matrix.push_back({storage_matrix[i].row_index, storage_matrix[i].index, -storage_matrix[i].data});
    }

    return negatedMatrix;
}

const SparseMatrix& SparseMatrix::operator=(const SparseMatrix& sparse_matrix) {
    //check for self-assignment
    if (this != &sparse_matrix) {
        //copy the data from sparse_matrix to this object
        storage_matrix = sparse_matrix.storage_matrix;
    }
    return *this;
}

const SparseMatrix SparseMatrix::operator*(const SparseMatrix &sparse_matrix) const {
    //check if multiplication is possible
    if (storage_matrix.empty() || sparse_matrix.storage_matrix.empty()) {
        //return an empty matrix
        return SparseMatrix();
    }

    //define a vector to store the result
    vector<matrixdatatype> result;

    //iterate through each row of the first matrix
    for (const auto &elem1 : storage_matrix) {
        //iterate through each column of the second matrix
        for (const auto &elem2 : sparse_matrix.storage_matrix) {
            //check if multiplication is possible
            if (elem1.index == elem2.row_index){
                //compute the resulting element
                double value = elem1.data * elem2.data;
                //add the resulting element to the result vector
                result.push_back({elem1.row_index, elem2.index, value});
            }
        }
    }

    //create a new SparseMatrix object to store the result
    SparseMatrix resultMatrix;

    //assign the result vector to the resultMatrix storage_matrix
    resultMatrix.storage_matrix = result;

    return resultMatrix;
}
 
ostream& operator<<(ostream &out, const SparseMatrix &sparse_matrix) {
    //variable to keep track of the current row being printed
    int current_row = -1;

    //loop through the storage_matrix
    for (const auto& data : sparse_matrix.storage_matrix) {
        //if starting a new row, print the row index
        if (data.row_index != current_row) {
            //if this is not the first row, add a newline
            if (current_row != -1)
                out << endl;
            out << data.row_index << " ";
            current_row = data.row_index;
        }
        //Print the index:data pair
        out << data.index << ":" << data.data << " ";
    }
    out << endl; 
    return out;
}


const SparseMatrix SparseMatrix::transpose() {
    SparseMatrix result;

    //iterate over the elements of the original matrix
    for (const auto &element : storage_matrix) {
        //swap row_index and index to transpose the element
        result.storage_matrix.push_back({element.index, element.row_index, element.data});
    }

    //sort the transposed matrix in ascending order based on row_index and index
    for (size_t i = 0; i < result.storage_matrix.size(); i++) {
        for (size_t j = i + 1; j < result.storage_matrix.size(); j++) {
            //check if the current element should be swapped with the next element
            if (result.storage_matrix[i].row_index > result.storage_matrix[j].row_index ||
                (result.storage_matrix[i].row_index == result.storage_matrix[j].row_index &&
                 result.storage_matrix[i].index > result.storage_matrix[j].index)) 
            {
                //swap the elements
                swap(result.storage_matrix[i], result.storage_matrix[j]);
            }
        }
    }

    return result;
}
