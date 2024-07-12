#ifndef _SCHOOLMANAGERSYSTEM_H
#define _SCHOOLMANAGERSYSTEM_H
#include "Student.h"
#include "Course.h"

namespace PA3 {

class SchoolManagerSystem {
private:
    Course** courses;
    Student** students;
    int courseCount;//All course count
    int studentCount;//All student count

    //Private member functions
    void printMainMenu();
    void printStudentMenu();
    void printStudentSubMenu();
    void printCourseMenu();
    void printCourseSubMenu();
public:
    SchoolManagerSystem();
    ~SchoolManagerSystem();
    void run();
};

} // namespace PA3
#endif