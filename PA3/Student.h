#ifndef _STUDENT_H
#define _STUDENT_H
#include <string>

namespace PA3 {

class Course;  // Forward declaration of Course class

class Student {
private:
    std::string studentName;
    int studentID;
    Course** courses;
    int numOfCourses;//Taken course number
    int capacity;


public:
    Student(const std::string& studentName, int studentID);
    ~Student();

    std::string getName() const;
    int getID() const;
    void addCourse(Course* course);
    void removeCourse(Course* course);
    Course** getCourses() const;
    Course* getCourse(int index);
    int getNumOfCourses() const;
};

} // namespace PA3
#endif