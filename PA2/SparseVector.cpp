#include <iostream>
#include <vector>
#include <fstream>
#include "SparseVector.h"

using namespace std;

//Default Constructor.
SparseVector::SparseVector(){}

//Constructor takes string and fills the vector.
SparseVector::SparseVector(string filename)
{
	ifstream cinfile;
	cinfile.open(filename);
    
    if (!cinfile.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

	int a;   //index
	char b;  //:
	double c;//data
	//While loop takes data from file until end of the file.
    while(cinfile >> a >> b >> c){
        datatype temp;
        temp.index = a;
        temp.data = c;
        alldata.push_back(temp);

	}
	cinfile.close();
}

const SparseVector SparseVector::operator+(const SparseVector& sparse_vec) const {
    SparseVector sum; //Sparse vector to hold the sum

    size_t i = 0;
    size_t j = 0; 

    //Continue while there are elements in both vectors
    while (i < alldata.size() && j < sparse_vec.alldata.size()) {
        if (alldata[i].index == sparse_vec.alldata[j].index) {
            //If both vectors have elements at the same index add them up and push to the sum vector
            sum.alldata.push_back({alldata[i].index, alldata[i].data + sparse_vec.alldata[j].data});
            i++; 
            j++; 
        }
        else if (alldata[i].index < sparse_vec.alldata[j].index)
        {
            //If the first vector is smaller than the second vector push the element from the first vector to the sum
            sum.alldata.push_back(alldata[i]);
            i++;
        }
        else 
        {
            //If the first vector is greater than the  second vector push the element from the second vector to the sum
            sum.alldata.push_back(sparse_vec.alldata[j]);
            j++;
        }
    }
    //Add remaining elements from the first vector
    for (; i < alldata.size(); i++) {
        sum.alldata.push_back(alldata[i]);
    }

    //Add remaining elements from the second vector
    for (; j < sparse_vec.alldata.size(); j++) {
        sum.alldata.push_back(sparse_vec.alldata[j]);
    }
    return sum; 
}


const SparseVector SparseVector::operator-(const SparseVector& sparse_vec) const {
    SparseVector diff; 

    size_t i = 0; 
    size_t j = 0; 

    //Iterate through both vectors while there are elements in both
    while (i < alldata.size() && j < sparse_vec.alldata.size()) {
        if (alldata[i].index == sparse_vec.alldata[j].index) {
            //If both vectors have elements at the same index, subtract the corresponding values and push to the difference vector
            diff.alldata.push_back({alldata[i].index, alldata[i].data - sparse_vec.alldata[j].data});
            i++;
            j++;
        } else if (alldata[i].index < sparse_vec.alldata[j].index) {
            //If the index in the first vector is smaller than the one in the second vector,push the element from the first vector to the difference
            diff.alldata.push_back(alldata[i]);
            i++; 
        } else {
            //If the index in the first vector is greater than the one in the second vector,push the negated element from the second vector to the difference
            diff.alldata.push_back({sparse_vec.alldata[j].index, -sparse_vec.alldata[j].data});
            j++;  
        }
    }

    //copy remaining elements from the first vector
    for (; i < alldata.size(); i++) {
        diff.alldata.push_back(alldata[i]);
    }
    //copy remaining elements from the second vector,negating each value
    for (; j < sparse_vec.alldata.size(); j++) {
        diff.alldata.push_back({sparse_vec.alldata[j].index, -sparse_vec.alldata[j].data});
    }

    return diff;  
}


const SparseVector SparseVector::operator-() const {
    SparseVector negative; 
    //iterate through each element in the original vector
    for (const auto& elem : alldata) {
        //negate the data of each element and push it to the negative vector
        negative.alldata.push_back({elem.index, -elem.data});
    }
    return negative; 
}



const SparseVector& SparseVector::operator=(const SparseVector& sparse_vec) {
    // Copy the data from the provided SparseVector into the current SparseVector
    alldata = sparse_vec.alldata;
    // Return a reference to the current SparseVector object
    return *this;
}


//Sends contents of a SparseVector to a std::ostream object.
ostream& operator<<(ostream& outs, const SparseVector& sparse_vec) {
    //Iterate through each element in the SparseVector
    for (const auto& element : sparse_vec.alldata) 
    {
        //Print only if data of the element is not zero
        if (element.data != 0) 
        {
            //Output index and data of the element
            outs << element.index << ":" << element.data << " ";
        }
    }
    outs << endl;
    
    return outs;
}



double dot(const SparseVector &sparse_vec1, const SparseVector &sparse_vec2) {
    double result = 0.0;
    
    //iterate through both vectors simultaneously
    size_t i = 0, j = 0;
    while (i < sparse_vec1.alldata.size() && j < sparse_vec2.alldata.size()) {
        //if indices match multiply corresponding data and accumulate
        if (sparse_vec1.alldata[i].index == sparse_vec2.alldata[j].index)
        {
            result += sparse_vec1.alldata[i].data * sparse_vec2.alldata[j].data;
            i++;
            j++;
        }
        //if indices don't match move to the next index in the vector with smaller index
        else if (sparse_vec1.alldata[i].index < sparse_vec2.alldata[j].index) 
        {
            i++;
        } 
        else 
        {
            j++;
        }
    }
    return result;
}