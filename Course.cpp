//
// Created by Lappy on 5/20/2024.
//

#include "Course.h"

Course::Course(int id, std::string name, std::string desc, Teacher* t)
        : courseId(id), courseName(name), courseDescription(desc), teacher(t) {}

void Course::addStudent(std::string username) {
    studentList.push(username);
}
std::string Course::getCourseName(){
    return this->courseName;
}
int Course::getCourseId() {
    return this->courseId;
}

