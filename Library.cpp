#include "Library.h"
#include "ui_Library.h"
#include "Dialog.h"

#include <QMessageBox>
#include <QTableWidget>
#include <QDialog>
#include <QDebug>

Library::Library(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Library)
{
    ui->setupUi(this);

    ui->books->setRowCount(20);
    ui->books->setColumnCount(5);
    ui->books->setHorizontalHeaderLabels({"ID", "Title", "Author", "type", "status"});
    ui->books->verticalHeader()->setVisible(false);
    ui->books->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->books->setColumnWidth(1, 150);
    ui->books->setColumnWidth(2, 150);

    auto setCell = [&](int row, int col, const QString& text) {
        ui->books->setItem(row, col, new QTableWidgetItem(text));
    };

    setCell(0, 0, "1");
    setCell(0, 1, "The Hobbit");
    setCell(0, 2, "J.R.R. Tolkien");
    setCell(0, 3, "Fantasy");
    setCell(0, 4, "Available");
    setCell(1, 0, "2");
    setCell(1, 1, "1984");
    setCell(1, 2, "George Orwell");
    setCell(1, 3, "Dystopian");
    setCell(1, 4, "Available");
    setCell(2, 0, "3");
    setCell(2, 1, "To Kill a Mockingbird ");
    setCell(2, 2, "Harper Lee");
    setCell(2, 3, "Fiction");
    setCell(2, 4, "Available");
    setCell(3, 0, "4");
    setCell(3, 1, "Pride and Prejudice ");
    setCell(3, 2, "Jane Austen");
    setCell(3, 3, "Romance");
    setCell(3, 4, "Available");
    setCell(4, 0, "5");
    setCell(4, 1, "The Great Gatsby");
    setCell(4, 2, "F. Scott Fitzgerald");
    setCell(4, 3, "Fiction");
    setCell(4, 4, "Available");
    setCell(5, 0, "6");
    setCell(5, 1, "Moby Dick");
    setCell(5, 2, "Herman Melville");
    setCell(5, 3, "Adventure");
    setCell(5, 4, "Available");
    setCell(6, 0, "7");
    setCell(6, 1, "War and Peace");
    setCell(6, 2, "Leo Tolstoy");
    setCell(6, 3, "Historical");
    setCell(6, 4, "Available");
    setCell(7, 0, "8");
    setCell(7, 1, "Crime and Punishment");
    setCell(7, 2, "Fyodor Dostoevsky");
    setCell(7, 3, "Psychological");
    setCell(7, 4, "Available");
    setCell(8, 0, "9");
    setCell(8, 1, "The Catcher in the Rye");
    setCell(8, 2, "J.D. Salinger");
    setCell(8, 3, "Fiction");
    setCell(8, 4, "Available");
    setCell(9, 0, "10");
    setCell(9, 1, "Brave New World");
    setCell(9, 2, "Aldous Huxley");
    setCell(9, 3, "Dystopian");
    setCell(9, 4, "Available");
    setCell(10, 0, "11");
    setCell(10, 1, "The Lord of the Rings");
    setCell(10, 2, "J.R.R. Tolkien");
    setCell(10, 3, "Fantasy");
    setCell(10, 4, "Available");
    setCell(11, 0, "12");
    setCell(11, 1, "Fahrenheit 451");
    setCell(11, 2, "Ray Bradbury");
    setCell(11, 3, "Dystopian");
    setCell(11, 4, "Available");
    setCell(12, 0, "13");
    setCell(12, 1, "Jane Eyre");
    setCell(12, 2, "Charlotte Brontë");
    setCell(12, 3, "Romance");
    setCell(12, 4, "Available");
    setCell(13, 0, "14");
    setCell(13, 1, "Wuthering Heights");
    setCell(13, 2, "Emily Brontë");
    setCell(13, 3, "Romance");
    setCell(13, 4, "Available");
    setCell(14, 0, "15");
    setCell(14, 1, "The Odyssey");
    setCell(14, 2, "Homer");
    setCell(14, 3, "Epic");
    setCell(14, 4, "Available");
    setCell(15, 0, "16");
    setCell(15, 1, "Don Quixote");
    setCell(15, 2, "Miguel de Cervantes");
    setCell(15, 3, "Adventure");
    setCell(15, 4, "Available");
    setCell(16, 0, "17");
    setCell(16, 1, "The Brothers Karamazov");
    setCell(16, 2, "Fyodor Dostoevsky");
    setCell(16, 3, "Philosophical");
    setCell(16, 4, "Available");
    setCell(17, 0, "18");
    setCell(17, 1, "Great Expectations");
    setCell(17, 2, "Charles Dickens");
    setCell(17, 3, "Fiction");
    setCell(17, 4, "Available");
    setCell(18, 0, "19");
    setCell(18, 1, "The Picture of Dorian Gray");
    setCell(18, 2, "Oscar Wilde");
    setCell(18, 3, "Gothic");
    setCell(18, 4, "Available");
    setCell(19, 0, "20");
    setCell(19, 1, "Frankenstein");
    setCell(19, 2, "Mary Shelley");
    setCell(19, 3, "Gothic");
    setCell(19, 4, "Available");

    connect(ui->borrow, &QPushButton::clicked, this, &Library::onBorrowClicked);
    connect(ui->search, &QPushButton::clicked, this, &Library::onSearchClicked);
    connect(ui->return_2, &QPushButton::clicked, this, &Library::onReturnClicked);

}

void Library::onSearchClicked(){

    int type = ui->type->currentIndex();
    QString info = ui->searchLabel->text().toLower().simplified();

    if(type == -1){
        QMessageBox::warning(this, "Warning", "Please select the type of search");
    }
    else{
        if(info.isEmpty()){
            QMessageBox::warning(this, "Error", "Enter a valid information");
        }
        else{
            if(type==0){
                for (int i = 0 ; i<ui->books->rowCount(); i++){
                    if(ui->books->item(i, 1)->text().toLower() == info){
                        QString id = ui->books->item(i, 0)->text();
                        QString status = ui->books->item(i, 4)->text();
                        if(status =="Available"){
                            QMessageBox::information(this, "Book exists", "Its ID:"+id);
                            return;
                        }
                        else{
                            QMessageBox::information(this, "Book Exists", "But it is currently borrowed");
                            return;
                        }
                    }
                }
                QMessageBox::information(this, "Book does not exist", "Try another name or ID");
            }
            if(type==1){
                for (int i = 0 ; i<ui->books->rowCount(); i++){
                   if(ui->books->item(i, 0)->text() ==  info){
                       QString id = ui->books->item(i, 1)->text();
                       QString status = ui->books->item(i, 4)->text();
                       if(status == "Available"){
                            QMessageBox::information(this, "Book exists", "Its title:"+id);
                           return;
                       }
                       else{
                           QMessageBox::information(this, "Book Exists", "But it is currently borrowed");
                           return;
                       }
                   }
                }
                QMessageBox::information(this, "Book does not exist", "Try another name or ID");
            }

        }
    }
}

void Library::onBorrowClicked(){
    Dialog dialog(this);

    if(dialog.exec() == QDialog::Accepted){
        int bookId = ui->books->currentRow() + 1;
        if (bookId == 0){
            QMessageBox::warning(this, "Warning" , "Please select the book you desire to borrow");
            return;
        }
        else{
            QString studentId = dialog.getId();
            QString fullName = dialog.getFullName();

            if(studentId.isEmpty() || fullName.isEmpty()){
                QMessageBox::warning(this, "Warning" , "Please enter valid information");
                return;
            }

            bool ok;
            int id = studentId.toInt(&ok);
            if(!ok){
                QMessageBox::warning(this, "Warning" , "Please enter a valid ID");
                return;
            }
            else{
                if(ui->books->item(bookId-1, 4)->text() == "Not Available"){
                    for (int i=0 ; i<students.length(); i++){
                        if(students[i].getBookId() == bookId){
                            int x = students[i].getStudentId();
                            QString y = QString::number(x);
                            QMessageBox::information(this, "Book exists", "But it is currently borrowed by " +students[i].getName()+ "\nHis/her ID is " +y);
                            return;
                        }
                    }
                }
                else{
                    students.append({id, fullName, bookId});
                    ui->books->item(bookId-1, 4)->setText("Not Available");
                }
            }
        }
    }
    else{
        return;
    }
}

void Library::onReturnClicked(){
    int bookId = ui->books->currentRow() + 1;
    if (bookId == 0){
        QMessageBox::warning(this, "Warning" , "Please select the book you desire to return");
        return;
    }
    if(ui->books->item(bookId-1, 4)->text() == "Available"){
        QMessageBox::warning(this, "Warning" , "Please select the right book you desire to return");
        return;
    }
    else{
       Dialog dialog(this);
        if(dialog.exec() == QDialog::Accepted){
           QString fullName = dialog.getFullName().toLower().simplified();
            QString studentId = dialog.getId();
           if(fullName.isEmpty()||studentId.isEmpty()){
                QMessageBox::warning(this, "Warning" , "Please enter valid information");
                return;
            }

            bool ok;
            int id = studentId.toInt(&ok);
            if(!ok){
                QMessageBox::warning(this, "Warning" , "Please enter a valid ID");
                return;
            }

            for(int i=0; i<students.length(); i++){
                if(bookId == students[i].getBookId()){
                    if(fullName==students[i].getName().toLower().simplified() && id == students[i].getStudentId()){
                        ui->books->item(bookId-1, 4)->setText("Available");
                        QMessageBox::information(this, "Book returned successfully" , "Thank you for your corporation");
                        students.removeAt(i);
                        return;
                    }
                    else{
                        QMessageBox::warning(this, "Warning" , "Invalid information\nTry another name or ID");
                        return;
                    }
                }
                else{
                    QMessageBox::warning(this, "Warning" , "Wrong book\nMake sure of the book you are trying to return");
                    return;
                }
            }
        }
        else{
            return;
        }
    }
}

Library::~Library()
{
    delete ui;
}
