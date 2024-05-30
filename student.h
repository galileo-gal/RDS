//
// Created by Lappy on 5/20/2024.
//

#ifndef STUDENTMANAGEMENTSYSTEM_STUDENT_H
#define STUDENTMANAGEMENTSYSTEM_STUDENT_H

#include <string>
#include <queue>
#include <fstream>
#include <ostream>
using namespace std;

class Student {
private:
    string username;
    string password;
    priority_queue<int> courseList;

public:
    Student() = default;
    Student(string username, string password);
    string getUsername();
    string getPassword();
    priority_queue<int> getCourseList();
    void enrollInCourse(int courseID);

    friend ofstream& operator<<(ofstream& ofs, const Student& student);
    friend ifstream& operator>>(ifstream& ifs, Student& student);

};


#endif //STUDENTMANAGEMENTSYSTEM_STUDENT_H
