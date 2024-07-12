#include "Student.h"

#include "Course.h"  //Include the Course header file

namespace PA3 {

Student::Student(const std::string& studentName, int studentID)
    : studentName(studentName), studentID(studentID), courses(new Course*[10]), numOfCourses(0), capacity(10) {}

Student::~Student() {
    delete[] courses;
}

std::string Student::getName() const {
    return studentName;
}

int Student::getID() const {
    return studentID;
}

void Student::addCourse(Course* course) {
    if (numOfCourses == capacity) {
        //Resize the array using 
        capacity *= 2;
        Course** newCourses = new Course*[capacity];
        for (int i = 0; i < numOfCourses; i++) {
            newCourses[i] = courses[i];
        }
        delete[] courses;
        courses = newCourses;
    }
    courses[numOfCourses++] = course;
}
void Student::removeCourse(Course* course) {
    for (int i = 0; i < numOfCourses; i++) {
        if (courses[i] == course) {
            for (int j = i; j < numOfCourses - 1; j++) {
                courses[j] = courses[j + 1];
                //shift array
            }
            numOfCourses--;
            break;
        }
    }
}

Course** Student::getCourses() const {
    return courses;
}
Course* Student::getCourse(int index) {
    return courses[index];
}
int Student::getNumOfCourses() const {
    return numOfCourses;
}

} 
