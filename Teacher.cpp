//
// Created by Lappy on 5/20/2024.
//

#include "Teacher.h"

Teacher::Teacher(std::string u, std::string p) : username(u), password(p) {}

void Teacher::addCourse(int courseId) {
    courseList.push(courseId);
}
std::string Teacher::getUsername() {
    return this->username;
}
std::string Teacher::getPassword(){
    return this->password;
}
std::priority_queue<int> Teacher::getCourseList() {
    return this->courseList;
}