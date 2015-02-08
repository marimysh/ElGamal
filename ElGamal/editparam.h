#ifndef EDITPARAM_H
#define EDITPARAM_H

#include <QDialog>

namespace Ui {
class editparam;
}

class editparam : public QDialog
{
    Q_OBJECT
    
public:
    explicit editparam(QWidget *parent = 0);
    int gettoch();
    void gener(int toch);
    ~editparam();
    public slots:
        void blow(int value);
    
private:
    Ui::editparam *ui;
};

#endif // EDITPARAM_H
