#ifndef EDITKEY_H
#define EDITKEY_H

#include <QDialog>
#include "QString"

namespace Ui {
class editkey;
}

class editkey : public QDialog
{
    Q_OBJECT
    
public:
    explicit editkey(QWidget *parent = 0);
    bool eqpasswd();
    QString passwd();
    ~editkey();

private:
    Ui::editkey *ui;
};

#endif // EDITKEY_H
