#include "Book.h"

Book::Book (int id, const QString& authorName, const QString& title, const QString &type)
    : id(id), authorName(authorName), title(title), type(type){
    status = true;
    borrowedBy = 0;
}

int Book::getId() const{
    return id;
}

QString Book::getTitle() const{
    return title;
}

QString Book::getType() const{
    return type;
}

bool Book::getStatus() const{
    return status;
}

void Book::setBorrowed(){
    status = false;
}

void Book::setAvailable(){
    status = true;
}

void Book::setBorrowedBy(int StudentId){
    borrowedBy = studentId;
}