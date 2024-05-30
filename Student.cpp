//
// Created by Lappy on 5/20/2024.
//

#include "Student.h"


Student::Student(std::string u, std::string p, std::int id) : username(u), password(p), id(id) {}

void Student::enrollInCourse(int courseId) {
    courseList.push(courseId);
}
std::string Student::getUsername() {
    return this->username;
}
std::string Student::getPassword(){
    return this->password;
}
std:: int Student::getId(){
    return this->id;
}
std::priority_queue<int> Student::getCourseList() {
    return this->courseList;
}
