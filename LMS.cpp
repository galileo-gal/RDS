#include "LMS.h"
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

void LMS::addStudent(string username, string password) {
    queue<Student> proxy;
    while (!students.empty()) {
        if (students.front().getUsername() == username) {
            throw runtime_error("Student already exists");
        }
        proxy.push(students.front());
        students.pop();
    }
    proxy.push(Student(username, password));
    students = proxy;
}

void LMS::addTeacher(string username, string password) {
    queue<Teacher> proxy;
    while (!teachers.empty()) {
        if (teachers.front().getUsername() == username) {
            throw runtime_error("Teacher already exists");
        }
        proxy.push(teachers.front());
        teachers.pop();
    }
    proxy.push(Teacher(username, password));
    teachers = proxy;
}

void LMS::addCourse(int id, string name, string desc, string teacherUsername) {
    queue<Teacher> proxyTeacher;
    Teacher* teacher = nullptr;

    while (!teachers.empty()) {
        if (teachers.front().getUsername() == teacherUsername) {
            teacher = new Teacher(teachers.front());
        }
        proxyTeacher.push(teachers.front());
        teachers.pop();
    }

    if (teacher == nullptr) {
        throw runtime_error("Teacher not found");
    }

    teachers = proxyTeacher;

    queue<Course> proxyCourse;
    while (!courses.empty()) {
        if (courses.front().getCourseId() == id) {
            throw runtime_error("Course already exists");
        }
        proxyCourse.push(courses.front());
        courses.pop();
    }
    proxyCourse.push(Course(id, name, desc, teacher));
    courses = proxyCourse;
}

void LMS::enrollStudentInCourse(string studentUsername, int courseID) {
    queue<Student> proxyStudent;
    queue<Course> proxyCourse;
    Student* student = nullptr;
    Course* course = nullptr;

    while (!students.empty()) {
        if (students.front().getUsername() == studentUsername) {
            student = new Student(students.front());
        }
        proxyStudent.push(students.front());
        students.pop();
    }

    while (!courses.empty()) {
        if (courses.front().getCourseId() == courseID) {
            course = new Course(courses.front());
        }
        proxyCourse.push(courses.front());
        courses.pop();
    }

    if (student == nullptr) {
        throw runtime_error("Student not found");
    }

    if (course == nullptr) {
        throw runtime_error("Course not found");
    }

    student->enrollInCourse(courseID);
    course->addStudent(studentUsername);

    students = proxyStudent;
    courses = proxyCourse;
}

void LMS::listStudents() {
    queue<Student> proxy = students;
    cout << "Students in the institute:" << endl;
    while (!proxy.empty()) {
        cout << proxy.front().getUsername() << endl;
        proxy.pop();
    }
}

void LMS::listTeachers() {
    queue<Teacher> proxy = teachers;
    cout << "Teachers in the institute:" << endl;
    while (!proxy.empty()) {
        cout << proxy.front().getUsername() << endl;
        proxy.pop();
    }
}

void LMS::listCourses() {
    queue<Course> proxy = courses;
    cout << "Courses offered by the institute:" << endl;
    while (!proxy.empty()) {
        cout << "Course ID: " << proxy.front().getCourseId() << ", Name: " << proxy.front().getCourseName() << endl;
        proxy.pop();
    }
}

bool LMS::loginStudent(string username, string password) {
    queue<Student> proxy = students;
    while (!proxy.empty()) {
        if (proxy.front().getUsername() == username && proxy.front().getPassword() == password) {
            return true;
        }
        proxy.pop();
    }
    return false;
}

bool LMS::loginTeacher(string username, string password) {
    queue<Teacher> proxy = teachers;
    while (!proxy.empty()) {
        if (proxy.front().getUsername() == username && proxy.front().getPassword() == password) {
            return true;
        }
        proxy.pop();
    }
    return false;
}

void LMS::studentMenu(string username) {
    int choice;
    do {
        cout << "\nStudent Menu\n";
        cout << "1. View Enrolled Courses\n";
        cout << "2. Enroll in a Course\n";
        cout << "3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                queue<Student> proxy = students;
                while (!proxy.empty()) {
                    if (proxy.front().getUsername() == username) {
                        priority_queue<int> courseList = proxy.front().getCourseList();
                        cout << "Enrolled Courses:\n";
                        while (!courseList.empty()) {
                            int courseId = courseList.top();
                            courseList.pop();
                            cout << "Course ID: " << courseId << ", Name: " << courses.front().getCourseName() << "\n";
                        }
                        break;
                    }
                    proxy.pop();
                }
                break;
            }
            case 2: {
                int courseId;
                cout << "Enter Course ID to enroll: ";
                cin >> courseId;
                enrollStudentInCourse(username, courseId);
                break;
            }
            case 3:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);
}

void LMS::teacherMenu(string username) {
    int choice;
    do {
        cout << "\nTeacher Menu\n";
        cout << "1. View Courses\n";
        cout << "2. Add Course\n";
        cout << "3. Remove Course\n";
        cout << "4. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                queue<Teacher> proxy = teachers;
                while (!proxy.empty()) {
                    if (proxy.front().getUsername() == username) {
                        priority_queue<int> courseList = proxy.front().getCourseList();
                        cout << "Courses:\n";
                        while (!courseList.empty()) {
                            int courseId = courseList.top();
                            courseList.pop();
                            cout << "Course ID: " << courseId << ", Name: " << courses.front().getCourseName() << "\n";
                        }
                        break;
                    }
                    proxy.pop();
                }
                break;
            }
            case 2: {
                int courseId;
                string name, desc;
                cout << "Enter Course ID: ";
                cin >> courseId;
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Course Description: ";
                getline(cin, desc);
                addCourse(courseId, name, desc, username);
                break;
            }
            case 3:
                // Implementation for removing a course
                cout << "Feature not implemented yet.\n";
                break;
            case 4:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}

void LMS::adminMenu() {
    int choice;
    do {
        cout << "\nAdmin Menu\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Add Course\n";
        cout << "4. List Students\n";
        cout << "5. List Teachers\n";
        cout << "6. List Courses\n";
        cout << "7. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string username, password;
                cout << "Enter Student Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;
                addStudent(username, password);
                break;
            }
            case 2: {
                string username, password;
                cout << "Enter Teacher Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;
                addTeacher(username, password);
                break;
            }
            case 3: {
                int courseId;
                string name, desc, teacherUsername;
                cout << "Enter Course ID: ";
                cin >> courseId;
                cout << "Enter Course Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Course Description: ";
                getline(cin, desc);
                cout << "Enter Teacher Username: ";
                cin >> teacherUsername;
                addCourse(courseId, name, desc, teacherUsername);
                break;
            }
            case 4:
                listStudents();
                break;
            case 5:
                listTeachers();
                break;
            case 6:
                listCourses();
                break;
            case 7:
                cout << "Logging out...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
}

void LMS::mainMenu() {
    int choice;
    do {
        cout << "\nMain Menu\n";
        cout << "1. Student Login\n";
        cout << "2. Teacher Login\n";
        cout << "3. Admin Login\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        string username, password;
        switch (choice) {
            case 1:
                cout << "Enter Student Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;
                if (loginStudent(username, password)) {
                    studentMenu(username);
                } else {
                    cout << "Invalid credentials. Try again.\n";
                }
                break;
            case 2:
                cout << "Enter Teacher Username: ";
                cin >> username;
                cout << "Enter Password: ";
                cin >> password;
                if (loginTeacher(username, password)) {
                    teacherMenu(username);
                } else {
                    cout << "Invalid credentials. Try again.\n";
                }
                break;
            case 3:
                adminMenu();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
}
