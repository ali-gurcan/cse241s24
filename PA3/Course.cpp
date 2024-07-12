#include "Course.h"

namespace PA3 {

Course::Course() : courseName(""), courseCode(""), students(nullptr), studentCount(0) {}

Course::Course(std::string courseName, std::string courseCode) : courseName(courseName), courseCode(courseCode), students(new Student*[10]), studentCount(0), capacity(10) {}

Course::~Course() {
    delete[] students;
}

std::string Course::getName() const {
    return courseName;
}

std::string Course::getCode() const {
    return courseCode;
}


void Course::addStudent(Student* student) {
    if (studentCount == capacity) {
        //Resize the array 
        capacity *= 2;
        Student** newStudents = new Student*[capacity];
        for (int i = 0; i < studentCount; i++) {
            newStudents[i] = students[i];
        }
        delete[] students;
        students = newStudents;
    }
    students[studentCount++] = student;
}

void Course::removeStudent(Student* student) {
    //shift array according to new version
    for (int i = 0; i < studentCount; i++) {
        if (students[i] == student) {
            for (int j = i; j < studentCount - 1;j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            break;
        }
    }
}

Student** Course::getStudents() const {
    return students;
}
Student* Course::getStudent(int index)const{
    return students[index];
 }
int Course::getStudentCount()  {
    return studentCount;
}

} // namespace PA3
