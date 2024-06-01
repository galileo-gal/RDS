#include "BST.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;

class LMS {
private:
    BST<Student> students;
    BST<Teacher> teachers;
    BST<Course> courses;

public:
    void printStudent(Student& student) {
        std::cout << "ID: " << student.getId() << ", Name: " << student.getName() << std::endl;
    }

    void addStudent(string username, string password, int id) {
        Student student(username, password, id);
        if (students.find(student)) {
            throw runtime_error("Student already exists");
        }
        students.insert(student);
    }

    void addTeacher(string username, string password, int id) {
        Teacher teacher(username, password, id);
        if (teachers.find(teacher)) {
            throw runtime_error("Teacher already exists");
        }
        teachers.insert(teacher);
    }

    void addCourse(int id, string name) {

        Course course(id, name);
        if (courses.find(course)) {
            throw runtime_error("Course already exists");
        }
        courses.insert(course);
    }

    void enrollStudentInCourse(int StudentID, int courseID) {
        if(students.find(StudentID)&&courses.find(courseID)){
            students.findNodeByID(StudentID)->data.enrollInCourse(courseID);
            courses.findNodeByID(courseID)->data.addStudent(StudentID);

        }else throw runtime_error("Student or Course not found");

    }

    void removeStudentFromCourse(int studentID, int courseID) {
        if(courses.findNodeByID(courseID)->data.hasStudent(studentID))
        courses.findNodeByID(courseID)->data.removeStudent(studentID);
        if(students.findNodeByID(studentID)->data.hasCourse((courseID))
            students.findNodeByID(studentID)->data.removeCourse(courseID);

    }

    void listStudents() const {
        students.inOrderTraversal([](Student& s) {
            cout << "ID: " << s.getId() << ", Username: " << s.getUsername() << endl;
        });
    }

    void listTeachers() const {
        teachers.inOrderTraversal([](Teacher& t) {
            cout << "ID: " << t.getId() << ", Username: " << t.getUsername() << endl;
        });
    }

    void listCourses() const {
        courses.inOrderTraversal([](Course& c) {
            cout << "ID: " << c.getCourseId() << ", Name: " << c.getCourseName() << endl;
        });
    }

    bool loginStudent(string username, string password, int id) {
        bool loggedIn = false;
        students.inOrderTraversal([&](Student& s) {
            if (s.getUsername() == username && s.getPassword() == password && s.getId() == id) {
                loggedIn = true;
            }
        });
        return loggedIn;
    }

    bool loginTeacher(string username, string password, int id) {
        bool loggedIn = false;
        teachers.inOrderTraversal([&](Teacher& t) {
            if (t.getUsername() == username && t.getPassword() == password && t.getId() == id) {
                loggedIn = true;
            }
        });
        return loggedIn;
    }

    Student findStudentById(int id) const {
        Student student("", "", 0);
        students.inOrderTraversal([&](Student& s) {
            if (s.getId() == id) {
                student = s;
            }
        });
        return student;
    }

    Teacher findTeacherById(int id) const {
        Teacher teacher("", "", 0);
        teachers.inOrderTraversal([&](Teacher& t) {
            if (t.getId() == id) {
                teacher = t;
            }
        });
        return teacher;
    }

    Course findCourseById(int id) const {
        Course course(0, "");
        courses.inOrderTraversal([&](Course& c) {
            if (c.getCourseId() == id) {
                course = c;
            }
        });
        return course;
    }

};

