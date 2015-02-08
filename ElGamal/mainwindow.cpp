#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //elgam->gen("123qwerty");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionEdit_params_triggered()
{
    editparam formOption;
    formOption.setModal(true);
    formOption.gener(elgam->toch);
    if (QDialog::Accepted == formOption.exec())
    {
        elgam->toch = formOption.gettoch();
        unsigned long long resultp = elgam->genaratep();
        //params p - primary key
        QString fileNamep = QFileDialog::getSaveFileName(this, tr("Save File"), "",
            tr("Text Files (*.txt)"));

        if (fileNamep != "") {
            QFile filep(fileNamep);
            if (!filep.open(QIODevice::WriteOnly)) {
                QMessageBox::critical(this, tr("Error"), tr("Could not create file"));
                return;
            } else {
                QTextStream streamp(&filep);
                streamp << QString::number(resultp);
                streamp.flush();

        editkey formpass;
        while (true)
        if (formpass.exec() == QDialog::Accepted)
        {
            if (formpass.eqpasswd())
                if (FuncPasswd::TruePasswd(formpass.passwd().toAscii()))
                {
                    elgam->genaratex(resultp);
                    QString resultstr = QString::fromAscii(
                                Vigenere::Encrypt(QString::number(elgam->getcloseparam()).toAscii(),
                                                  formpass.passwd().toAscii()));
                    //params x - close key
                    QString fileNamex = QFileDialog::getSaveFileName(this, tr("Save File"), "",
                        tr("Text Files (*.txt)"));

                    if (fileNamex != "") {
                        QFile filex(fileNamex);
                        if (!filex.open(QIODevice::WriteOnly)) {
                            QMessageBox::critical(this, tr("Error"), tr("Could not create file"));
                            return;
                        } else {
                            QTextStream streamx(&filex);
                            streamx << resultstr;
                            streamx.flush();
                            filex.close();
                        }
                        streamp << " " << elgam->g << " " << elgam->y;
                        streamp.flush();
                        filep.close();
                        return;
                    }
                }
        }

    }
}

    }
}


//Encrypt
void MainWindow::on_actionOpen_triggered()
{
    //params of messege encrypt
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
            tr("Text Files (*.txt)"));
    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
           QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
           return;
        }
        QTextStream in(&file);

        //params - primary key
        QString fileNameparamp = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                tr("Text Files (*.txt)"));
        if (fileNameparamp != "") {
            QFile fileparamp(fileNameparamp);
            if (!fileparamp.open(QIODevice::ReadOnly)) {
               QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
               return;
            }
            QTextStream inparamp(&fileparamp);

                    QString strparamp = inparamp.readAll();
                    QStringList strparlist = strparamp.split(" ");
                    elgam->setKey(strparlist);
                    elgam->gen(in.readAll());
                    elgam->Encrypt();
                    ui->textOriginal->setText("");
                    for (int i = 0; i < elgam->getLength(); ++i)
                    {
                        QString astring = "a = " + QString::number(elgam->a[i]);
                        QString bstring = "b = " + QString::number(elgam->b[i]);
                        ui->textOriginal->append(astring);
                        ui->textOriginal->append(bstring);
                    }
            fileparamp.close();
        }
        file.close();
    }
    return;
}

//Save encrypt
void MainWindow::on_actionSave_triggered()
{
    //params encrypt
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("Text Files (*.txt)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Could not create file"));
            return;
    } else {
        QTextStream stream(&file);
        for (int i = 0; i < elgam->getLength(); ++i)
        {
            stream << QString::number(elgam->a[i]);
            stream << " ";
            stream << QString::number(elgam->b[i]);
            stream << " ";
        }
        stream.flush();
        file.close();
        }
    }
}

void MainWindow::on_actionEncrypt_triggered()
{
    //params of messege encrypt
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
            tr("Text Files (*.txt)"));
    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
           QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
           return;
        }
        QTextStream in(&file);

        //params - primary key
        QString fileNameparamp = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                tr("Text Files (*.txt)"));
        if (fileNameparamp != "") {
            QFile fileparamp(fileNameparamp);
            if (!fileparamp.open(QIODevice::ReadOnly)) {
               QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
               return;
            }
            QTextStream inparamp(&fileparamp);

            //params - close key
            QString fileNameparamx = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                    tr("Text Files (*.txt)"));
            if (fileNameparamx != "") {
                QFile fileparamx(fileNameparamx);
                if (!fileparamx.open(QIODevice::ReadOnly)) {
                   QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                   return;
                }
                QTextStream inparamx(&fileparamx);

                //enter password for close key
                enterkey formkey;
                if (QDialog::Accepted == formkey.exec())
                {
                    QString strparamp = inparamp.readAll();
                    QString strparamx = inparamx.readAll();
                    QByteArray paramx = strparamx.toAscii();
                    //elgam->setKey(strparamp.toAscii(), Vigenere::Decrypt(paramx, formkey.getpasswd().toAscii()));
                    elgam->gen(in.readAll());
                    elgam->Encrypt();
                    ui->textOriginal->setText("");
                    for (int i = 0; i < elgam->getLength(); ++i)
                    {
                        QString astring = "a = " + QString::number(elgam->a[i]);
                        QString bstring = "b = " + QString::number(elgam->b[i]);
                        ui->textOriginal->append(astring);
                        ui->textOriginal->append(bstring);
                    }
                }
                fileparamx.close();
            }
            fileparamp.close();
        }
        file.close();
    }

}

void MainWindow::on_actionDecrypt_triggered()
{
    elgam->Decrypt();
    QString answer = QString::fromAscii(elgam->barr);
    ui->textOriginal->setText(answer);
}

void MainWindow::on_actionOpen_for_decrypt_triggered()
{
    //params of messege encrypt
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
            tr("Text Files (*.txt)"));
    if (fileName != "") {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
           QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
           return;
        }
        QTextStream in(&file);

        //params - primary key
        QString fileNameparamp = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                tr("Text Files (*.txt)"));
        if (fileNameparamp != "") {
            QFile fileparamp(fileNameparamp);
            if (!fileparamp.open(QIODevice::ReadOnly)) {
               QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
               return;
            }
            QTextStream inparamp(&fileparamp);

            //params - close key
            QString fileNameparamx = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                    tr("Text Files (*.txt)"));
            if (fileNameparamx != "") {
                QFile fileparamx(fileNameparamx);
                if (!fileparamx.open(QIODevice::ReadOnly)) {
                   QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
                   return;
                }
                QTextStream inparamx(&fileparamx);

                //enter password for close key
                enterkey formkey;
                if (QDialog::Accepted == formkey.exec())
                {
                    QString strparamp = inparamp.readAll();
                    QStringList listparam = strparamp.split(" ");
                    QString strparamx = inparamx.readAll();
                    QByteArray paramx = strparamx.toAscii();
                    elgam->setKey(listparam);
                    elgam->setcloseparam(elgam->QStringtoull(
                                             Vigenere::Decrypt(paramx, formkey.getpasswd().toAscii())));
                    elgam->genDecrypt(in.readAll());
                    elgam->Decrypt();
                    QString answer = QString::fromAscii(elgam->barr);
                    ui->textOriginal->setText(answer);
                }
                fileparamx.close();
            }
            fileparamp.close();
        }
        file.close();
    }
}
