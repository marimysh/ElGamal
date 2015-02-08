#include "editparam.h"
#include "ui_editparam.h"

void editparam::blow(int value)
{
    ui->label_toch->setText(QString::number(value));
}

editparam::editparam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editparam)
{
    ui->setupUi(this);
    connect(ui->tochSlider, SIGNAL(valueChanged(int)), this, SLOT(blow(int)));
}

editparam::~editparam()
{
    delete ui;
}

void editparam::gener(int toch)
{
    ui->tochSlider->setValue(toch);
    ui->label_toch->setText(QString::number(toch));
    return;
}

int editparam::gettoch()
{
    return ui->tochSlider->value();
}
