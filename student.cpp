//
// Created by Lappy on 5/20/2024.
//

#include "Student.h"
#include <string>



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

ofstream& operator<<(ofstream& ofs, const Student& student) {
    size_t usernameLength = student.username.size();
    size_t passwordLength = student.password.size();
    ofs.write(reinterpret_cast<const char*>(&usernameLength), sizeof(usernameLength));
    ofs.write(student.username.c_str(), usernameLength);
    ofs.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));
    ofs.write(student.password.c_str(), passwordLength);
    priority_queue<int> temp = student.courseList;
    while (!temp.empty()) {
        int courseID = temp.top();
        temp.pop();
        ofs.write(reinterpret_cast<const char*>(&courseID), sizeof(courseID));
    }
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Student& student) {
    size_t usernameLength;
    size_t passwordLength;
    ifs.read(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
    student.username.resize(usernameLength);
    ifs.read(&student.username[0], usernameLength);
    ifs.read(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));
    student.password.resize(passwordLength);
    ifs.read(&student.password[0], passwordLength);
    while (ifs.peek() != EOF) {
        int courseID;
        ifs.read(reinterpret_cast<char*>(&courseID), sizeof(courseID));
        student.courseList.push(courseID);
    }
    return ifs;
}
