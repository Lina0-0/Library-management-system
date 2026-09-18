#ifndef BOOK_H
#define BOOK_H

#include <QString>

class Book{
private:
    int id;
    int borrowedBy;
    QString authorName;
    QString title;
    QString type;
    bool status;

public:

    Book(int id, const QString& authorName, const QString& title, const QString& type);

    int getId() const;
    QString getTitle() const;
    QString getType() const;
    bool getStatus() const;

    void setBorrowed() ;
    void setAvailable() ;
    void setBorrowedBy(int studentId);
};

#endif // BOOK_H
