//
// Created by Lappy on 5/20/2024.
//

#ifndef STUDENTMANAGEMENTSYSTEM_COURSE_H
#define STUDENTMANAGEMENTSYSTEM_COURSE_H


#include <string>
#include <queue>
#include "Teacher.h"

class Course {
public:
    int courseId;
    std::string courseName;
    std::string courseDescription;
    Teacher* teacher;
    std::priority_queue<std::string> studentList;

    Course(int id, std::string name, std::string desc, Teacher* t);

    void addStudent(std::string username);
    int getCourseId();
    std::string getCourseName();
};

#endif //STUDENTMANAGEMENTSYSTEM_COURSE_H
