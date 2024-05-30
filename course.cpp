#include "Course.h"
#include "LMS.cpp"

Course::Course(int id, std::string name, std::string desc, Teacher* t)
    : courseId(id), courseName(name), courseDescription(desc), teacher(t) {}

void Course::addStudent(std::string username) {
    studentList.push(username);
}

std::string Course::getCourseName() const {
    return this->courseName;
}

int Course::getCourseId() const {
    return this->courseId;
}

string Course::getCourseDesc() const {
    return this->courseDescription;
}

Teacher* Course::getTeacher() const {
    return this->teacher;
}

priority_queue<string> Course::getStudentNames() const {
    return this->studentList;
}

ofstream& operator<<(ofstream& ofs, const Course& course) {
    ofs.write(reinterpret_cast<const char*>(&course.courseId), sizeof(course.courseId));
    size_t nameLength = course.courseName.size();
    size_t descLength = course.courseDescription.size();
    ofs.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    ofs.write(course.courseName.c_str(), nameLength);
    ofs.write(reinterpret_cast<const char*>(&descLength), sizeof(descLength));
    ofs.write(course.courseDescription.c_str(), descLength);

    // Serialize teacher pointer as an integer (teacher ID)
    int teacherId = (course.teacher != nullptr) ? course.teacher->getId() : -1;
    ofs.write(reinterpret_cast<const char*>(&teacherId), sizeof(teacherId));

    size_t studentCount = course.studentList.size();
    ofs.write(reinterpret_cast<const char*>(&studentCount), sizeof(studentCount));
    priority_queue<string> temp = course.studentList;
    while (!temp.empty()) {
        string studentUsername = temp.top();
        temp.pop();
        size_t studentLength = studentUsername.size();
        ofs.write(reinterpret_cast<const char*>(&studentLength), sizeof(studentLength));
        ofs.write(studentUsername.c_str(), studentLength);
    }
    return ofs;
}

ifstream& operator>>(ifstream& ifs, Course& course) {
    ifs.read(reinterpret_cast<char*>(&course.courseId), sizeof(course.courseId));
    size_t nameLength;
    size_t descLength;
    ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    course.courseName.resize(nameLength);
    ifs.read(&course.courseName[0], nameLength);
    ifs.read(reinterpret_cast<char*>(&descLength), sizeof(descLength));
    course.courseDescription.resize(descLength);
    ifs.read(&course.courseDescription[0], descLength);

    // Deserialize teacher pointer as an integer (teacher ID)
    int teacherId;
    ifs.read(reinterpret_cast<char*>(&teacherId), sizeof(teacherId));
    course.teacher = (teacherId != -1) ? getTeacherById(teacherId) : nullptr;

    size_t studentCount;
    ifs.read(reinterpret_cast<char*>(&studentCount), sizeof(studentCount));
    for (size_t i = 0; i < studentCount; ++i) {
        size_t studentLength;
        ifs.read(reinterpret_cast<char*>(&studentLength), sizeof(studentLength));
        string studentUsername(studentLength, ' ');
        ifs.read(&studentUsername[0], studentLength);
        course.studentList.push(studentUsername);
    }
    return ifs;
}
