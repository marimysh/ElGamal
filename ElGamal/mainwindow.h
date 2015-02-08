#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "editkey.h"
#include <QtGui>
#include "elgamal2.h"
#include "QString"
#include "QVariant"
#include "editparam.h"
#include "enterkey.h"
#include "funcpasswd.h"
#include "vigenere.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    ElGamal* elgam = new ElGamal();
    
private slots:
    void on_actionExit_triggered();

    void on_actionEdit_params_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionEncrypt_triggered();

    void on_actionDecrypt_triggered();

//    void on_actionOpen_for_decrupt_triggered();

    void on_actionOpen_for_decrypt_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
