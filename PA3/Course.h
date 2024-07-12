#ifndef _COURSE_H
#define _COURSE_H

#include<iostream>
using namespace std;

#include "Student.h"

namespace PA3 {

class Course {
private:
    string courseName;
    string courseCode;
    Student** students;
    int studentCount;//Student number of class
    int capacity;

public:
    Course();
    Course(string courseName,string courseCode);
    ~Course();
    
    string getName() const;
    string getCode() const;
    void addStudent(Student* student);
    void removeStudent(Student* student);
    Student** getStudents() const;
    Student* getStudent(int index) const ;
    int getStudentCount() ;
};

} // namespace PA3
#endif