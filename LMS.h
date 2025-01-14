//
// Created by Lappy on 5/20/2024.
//

#ifndef STUDENTMANAGEMENTSYSTEM_LMS_H
#define STUDENTMANAGEMENTSYSTEM_LMS_H

#include <queue>
#include <string>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

using namespace std;
class LMS {
private:
    queue<Student> students;
    queue<Teacher> teachers;
    queue<Course> courses;
public:
    void addStudent(string username, string password, int id);
    void addTeacher(string username, string password, int id);
    void addCourse(int id, string name, string desc, string teacherUsername);
    void enrollStudentInCourse(string studentUsername, int courseID);
    void listStudents();
    void listTeachers();
    void listCourses();
    bool loginStudent(string username, string password, int id);
    bool loginTeacher(string username, string password, int id);
    void studentMenu(int id);
    void teacherMenu(int id);
    void adminMenu();
    void mainMenu();


};


#endif //STUDENTMANAGEMENTSYSTEM_LMS_H
