//
// Created by Lappy on 5/20/2024.
//

#ifndef STUDENTMANAGEMENTSYSTEM_STUDENT_H
#define STUDENTMANAGEMENTSYSTEM_STUDENT_H

#include <string>
#include <queue>

class Student {
public:
    std::string username;
    std::string password;
    std:: int id;
    std::priority_queue<int> courseList;
    std::string getUsername();

    Student(std::string u, std::string p, std::int id);

    void enrollInCourse(int courseId);

    std::string getPassword();
    std::int getId();
    std::priority_queue<int> getCourseList();

};


#endif //STUDENTMANAGEMENTSYSTEM_STUDENT_H
