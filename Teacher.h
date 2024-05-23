//
// Created by Lappy on 5/20/2024.
//

#ifndef STUDENTMANAGEMENTSYSTEM_TEACHER_H
#define STUDENTMANAGEMENTSYSTEM_TEACHER_H

#include <string>
#include <queue>
#include <fstream>
#include <ostream>

using namespace std;

class Teacher {

private:
    string username;
    string password;
    priority_queue<int> courseList;

public:
    Teacher()=default;
    Teacher(std::string u, std::string p);
    ~Teacher()=default;

    std::string getUsername();
    void addCourse(int courseId);
    std::string getPassword();
    std::priority_queue<int> getCourseList();

    friend ofstream& operator<<(ofstream& ofs, const Teacher& teacher);
    friend ifstream& operator>>(ifstream& ifs, Teacher& teacher);
};


#endif //STUDENTMANAGEMENTSYSTEM_TEACHER_H
