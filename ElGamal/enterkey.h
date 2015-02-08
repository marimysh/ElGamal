#ifndef ENTERKEY_H
#define ENTERKEY_H

#include <QDialog>
#include "QString"

namespace Ui {
class enterkey;
}

class enterkey : public QDialog
{
    Q_OBJECT
    
public:
    explicit enterkey(QWidget *parent = 0);
    QString getpasswd();
    ~enterkey();
    
private:
    Ui::enterkey *ui;
};

#endif // ENTERKEY_H
