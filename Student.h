#ifndef STUDENT_H
#define STUDENT_H

#include <QString>

class Student{
private:
    int studentId;
    QString name;
    int bookId;

public:
    Student(int id, const QString& name, int bookId);

    int getStudentId() const;
    QString getName() const;
    int getBookId() const;
};

#endif // STUDENT_H
