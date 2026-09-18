#include "Student.h"

Student::Student(int studentId, const QString& name, int bookId):
    studentId(studentId), name(name), bookId(bookId){}

int Student::getStudentId() const{
    return studentId;
}

QString Student::getName() const{
    return name;
}

int Student::getBookId() const{
    return bookId;
}