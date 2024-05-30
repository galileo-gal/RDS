//
// Created by Lappy on 5/20/2024.
//

#include "Teacher.h"

Teacher::Teacher(std::string u, std::string p, std:: int id) : username(u), password(p), id(id) {}

void Teacher::addCourse(int courseId) {
    courseList.push(courseId);
}
std::string Teacher::getUsername() {
    return this->username;
}
std::string Teacher::getPassword(){
    return this->password;
}
std::int Teacher::getId(){
    return this->id;
}
std::priority_queue<int> Teacher::getCourseList() {
    return this->courseList;
}
