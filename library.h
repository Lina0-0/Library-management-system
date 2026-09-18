#ifndef LIBRARY_H
#define LIBRARY_H

#include "Student.h"

#include <QWidget>
#include <QList>

QT_BEGIN_NAMESPACE
namespace Ui {
class Library;
}
QT_END_NAMESPACE

class Library : public QWidget
{
    Q_OBJECT

public:
    explicit Library(QWidget *parent = nullptr);
    ~Library() override;

private slots:
    void onBorrowClicked();
    void onReturnClicked();
    void onSearchClicked();

private:
    Ui::Library *ui;
    QList<Student> students ;

};
#endif // LIBRARY_H
