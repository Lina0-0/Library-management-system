#include "Dialog.h"
#include "ui_Dialog.h"

#include <QString>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->operation, &QDialogButtonBox::accepted, this, &Dialog::accept);
    connect(ui->operation, &QDialogButtonBox::rejected, this, &Dialog::reject);
}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getFullName() const{
    return ui->fullName->text();
}

QString Dialog::getId() const{
    return ui->StudentId->text();
}