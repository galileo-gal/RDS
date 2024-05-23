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


ofstream& operator<<(ofstream& ofs, const Teacher& teacher) {
    size_t usernameLength = teacher.username.size();
    size_t passwordLength = teacher.password.size();
    ofs.write(reinterpret_cast<const char*>(&usernameLength), sizeof(usernameLength));
    ofs.write(teacher.username.c_str(), usernameLength);
    ofs.write(reinterpret_cast<const char*>(&passwordLength), sizeof(passwordLength));
    ofs.write(teacher.password.c_str(), passwordLength);

    // Serialize the priority_queue size and elements
    size_t courseListSize = teacher.courseList.size();
    ofs.write(reinterpret_cast<const char*>(&courseListSize), sizeof(courseListSize));
    priority_queue<int> temp = teacher.courseList;
    while (!temp.empty()) {
        int courseID = temp.top();
        temp.pop();
        ofs.write(reinterpret_cast<const char*>(&courseID), sizeof(courseID));
    }
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Teacher& teacher) {
    size_t usernameLength;
    size_t passwordLength;
    ifs.read(reinterpret_cast<char*>(&usernameLength), sizeof(usernameLength));
    teacher.username.resize(usernameLength);
    ifs.read(&teacher.username[0], usernameLength);
    ifs.read(reinterpret_cast<char*>(&passwordLength), sizeof(passwordLength));
    teacher.password.resize(passwordLength);
    ifs.read(&teacher.password[0], passwordLength);

    // Deserialize the priority_queue size and elements
    size_t courseListSize;
    ifs.read(reinterpret_cast<char*>(&courseListSize), sizeof(courseListSize));
    for (size_t i = 0; i < courseListSize; ++i) {
        int courseID;
        ifs.read(reinterpret_cast<char*>(&courseID), sizeof(courseID));
        teacher.courseList.push(courseID);
    }
    return ifs;
}