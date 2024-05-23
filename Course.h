//
// Created by Lappy on 5/20/2024.
//

#ifndef STUDENTMANAGEMENTSYSTEM_COURSE_H
#define STUDENTMANAGEMENTSYSTEM_COURSE_H


#include <string>
#include <queue>
#include <fstream>
#include <ostream>
#include "Teacher.h"
using namespace std;
class Teacher;

class Course {
private:
    int courseId;
    string courseName;
    string courseDescription;
    Teacher* teacher;
    priority_queue<string> studentList;

public:
    Course()=default;
    Course(int id, std::string name, std::string desc, Teacher* t);
    ~Course()=default;
    void addStudent(std::string username);
    int getCourseId();
    string getCourseName();
    string getCourseDesc();
    Teacher* getTeacher();
    priority_queue<string> getStudentNames();

    friend ofstream& operator<<(ofstream& ofs, const Course& course);
    friend ifstream& operator>>(ifstream& ifs, Course& course);
};

#endif //STUDENTMANAGEMENTSYSTEM_COURSE_H
