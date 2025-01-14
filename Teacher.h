//
// Created by Lappy on 5/20/2024.
//

#ifndef STUDENTMANAGEMENTSYSTEM_TEACHER_H
#define STUDENTMANAGEMENTSYSTEM_TEACHER_H

#include <string>
#include <queue>

class Teacher {
public:
    std::string username;
    std::string password;
    std::int id;
    std::priority_queue<int> courseList;


    Teacher(std::string u, std::string p, std::id);

    std::string getUsername();
    void addCourse(int courseId);

    std::string getPassword(); 
    std::int getId();

    std::priority_queue<int> getCourseList();
};


#endif //STUDENTMANAGEMENTSYSTEM_TEACHER_H
