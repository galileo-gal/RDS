#ifndef STUDENTMANAGEMENTSYSTEM_TEACHER_H
#define STUDENTMANAGEMENTSYSTEM_TEACHER_H

#include <string>
#include <queue>
#include <fstream>
#include <ostream>

using namespace std;

class Teacher {

private:
    int id; // Assuming each teacher has a unique ID
    string username;
    string password;
    priority_queue<int> courseList;

public:
    Teacher()=default;
    Teacher(int id, std::string u, std::string p);
    ~Teacher()=default;

    int getId() const; // Add this method to get the teacher ID
    std::string getUsername() const;
    std::string getPassword() const;
    std::priority_queue<int> getCourseList() const;

    void addCourse(int courseId);

    friend ofstream& operator<<(ofstream& ofs, const Teacher& teacher);
    friend ifstream& operator>>(ifstream& ifs, Teacher& teacher);
};

#endif //STUDENTMANAGEMENTSYSTEM_TEACHER_H
