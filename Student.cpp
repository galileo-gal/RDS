//
// Created by Lappy on 5/20/2024.
//

#include "Student.h"


Student::Student(std::string u, std::string p) : username(u), password(p) {}

void Student::enrollInCourse(int courseId) {
    courseList.push(courseId);
}
std::string Student::getUsername() {
    return this->username;
}
std::string Student::getPassword(){
    return this->password;
}
std::priority_queue<int> Student::getCourseList() {
    return this->courseList;
}