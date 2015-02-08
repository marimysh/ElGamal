#include "editkey.h"
#include "ui_editkey.h"

editkey::editkey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editkey)
{
    ui->setupUi(this);
}

editkey::~editkey()
{
    delete ui;
}

bool editkey::eqpasswd()
{
    if (ui->linekey->text() == ui->lineKey2->text())
        return true;
    else
        return false;
}

QString editkey::passwd()
{
    return ui->linekey->text();
}
