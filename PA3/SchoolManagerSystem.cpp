#include "SchoolManagerSystem.h"

#include"Student.h"

#include"Course.h"

#include<iostream>
#include<stdlib.h>
#include <string>
using namespace std;

namespace PA3 {

  SchoolManagerSystem::SchoolManagerSystem(): courses(new Course * [10]), students(new Student * [10]), courseCount(0), studentCount(0) {}

  SchoolManagerSystem::~SchoolManagerSystem() {
    for (int i = 0; i < courseCount; i++) {
      delete courses[i];
    }
    for (int i = 0; i < studentCount; i++) {
      delete students[i];
    }
    delete[] courses;
    delete[] students;
  }

void SchoolManagerSystem::printMainMenu() {
    cout << "Main_menu\n" <<
      "0 exit\n" <<
      "1 student\n" <<
      "2 course\n" <<
      "3 list_all_students\n" <<
      "4 list_all_courses\n";
  }

void SchoolManagerSystem::printStudentMenu() {
    cout << "0 up\n" <<
      "1 add_student\n" <<
      "2 select_student\n";
  }
void SchoolManagerSystem::printStudentSubMenu() {
    cout << "0 up\n" <<
      "1 delete_student \n" <<
      "3 add_selected_student_to_a_course\n" <<
      "4 drop_selected_student_from_a_course\n";
  }

void SchoolManagerSystem::printCourseMenu() {
    cout << "0 up\n" <<
      "1 add_course\n" <<
      "2 select_course\n";
  }
void SchoolManagerSystem::printCourseSubMenu() {
    cout << "0 up\n" <<
      "1 delete_course \n" <<
      "2 list_students_registered_to_the_selected_course\n";
  }

void SchoolManagerSystem::run() {
    int mainChoice;
    int studentChoice;
    int courseChoice;

    while (true) {
      printMainMenu();
      cin >> mainChoice;
      switch (mainChoice) {
      case 0:
        return;
        break;
      /////1-Student
      case 1:
        printStudentMenu();
        cin >> studentChoice;
        switch (studentChoice) {
        case 0:
          //UP
          break;
        case 1:
        {
        //ADD STUDENT
         string name;
          int id;
          cin >> name >> id;   
          students[studentCount] = new Student(name, id);
          studentCount++;
          break;
        }
        //SELECT STUDENT
        case 2: {
          string name;
          int id, subchoice;
          cin >> name >> id;
          printStudentSubMenu();
          //student sub menu 
          for (int i = 0; i < studentCount; i++)
          {
            if (students[i] -> getName() == name && students[i] -> getID() == id)
            {
              cin >> subchoice;
              switch (subchoice) {
              case 0:
                break;
              case 1:
                // Delete student functionality
                delete students[i];
                for (int j = i; j < studentCount - 1; ++j) {
                  students[j] = students[j + 1];
                }
                studentCount--;
                break;
              case 3:
              //Add selected student to a course
              {
                for (int k = 0; k < courseCount; k++) {
                  if (students[i]->getCourse(k)==nullptr)
                  {
                    cout << k+1<<" "<<courses[k] -> getCode() << " " << courses[k] -> getName() << endl;
                  }
                }
                int addsort;
                cin>>addsort;                
                students[i] -> addCourse(courses[addsort-1]);
                courses[addsort-1]->addStudent(students[i]);//increase counter
              }
              break;
              case 4:{
                for (int k = 0; k <students[i]->getNumOfCourses(); k++) {
                  if (courses[k]!=NULL)
                  {
                    cout << k+1<<" "<<students[i]->getCourse(k)->getCode() << " " << students[i]->getCourse(k)-> getName() << endl;
                  }
                }
                  int deleteSort;
                  cin>>deleteSort; 
                  students[i]->removeCourse(courses[deleteSort-1]);
                }
                break;
              }
              break;
            }
          }
          break;
        }
        default:
          break;
        }
        break;
      ////
      ////2-Course
      ////
      case 2:
        printCourseMenu();
        cin >> courseChoice;
        switch (courseChoice) {
        case 0:
          //up
          break;
        case 1: {
          string code, name;
          cin >> code >> name;
          courses[courseCount++] = new Course(name, code);
          break;
        }
        case 2:
        {
          string code, name;
          cin >> code >> name;
          printCourseSubMenu();
          int select;
          // Select course functionality
          for (int i = 0; i < courseCount; i++)
          {
            if (courses[i] -> getCode() == code && courses[i] -> getName() == name) {
              cin >> select;
              switch (select) {
              case 0:
                break;
              case 1:
              {
                // Delete course functionality
                delete courses[i];
                for (int j = i; j < courseCount - 1; j++) {
                  courses[j] = courses[j + 1];
                }
                courseCount--;
                break;
              }
              case 2: 
              {
                //student number of selected course 
                int takenNum=courses[i]->getStudentCount();
                for (int j = 0; j < takenNum; j++) 
                {
                  if (students[j]->getCourse(i)->getCode()==courses[i] -> getCode())
                  {
                    cout <<  students[j]->getName()<< " " << students[j]-> getID() << endl;
                  }
                }
                break;
              } 
              default:
                break;
              }
            }
          }
          break;
        }
        default:
          break;
        }
        break;
      case 3:
        //List all students 
        for (int i = 0; i < studentCount; i++) 
        {
          cout << i+1 <<" "<<students[i] -> getName() << " " << students[i] -> getID() <<endl;
        }
        break;
      case 4:
        //List all courses 
        for (int i = 0; i < courseCount; i++) 
        {
          cout << i+1 <<" "<<courses[i] -> getCode() << " " << courses[i] -> getName() << endl;
        }
        break;
      default:
        break;
      }
    }
  }
}