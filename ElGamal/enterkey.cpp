#include "enterkey.h"
#include "ui_enterkey.h"

enterkey::enterkey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enterkey)
{
    ui->setupUi(this);
}

enterkey::~enterkey()
{
    delete ui;
}

QString enterkey::getpasswd()
{
    return ui->lineEdit->text();
}
