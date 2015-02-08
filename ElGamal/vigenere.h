#ifndef VIGENERE_H
#define VIGENERE_H

#include "QByteArray"

class Vigenere
{
public:
    Vigenere();
    static QByteArray Encrypt(QByteArray inmess, QByteArray passwd);
    static QByteArray Decrypt(QByteArray inmess, QByteArray passwd);
};

#endif // VIGENERE_H
