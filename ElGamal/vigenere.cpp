#include "vigenere.h"

Vigenere::Vigenere()
{
}

QByteArray Vigenere::Encrypt(QByteArray inmess, QByteArray passwd)
{
    QByteArray outmess;
    int iterpass = 0;
    for (int i = 0; i < inmess.length(); ++i)
    {
        outmess[i] = inmess[i] + passwd[iterpass];
        if (iterpass == (passwd.length() - 1))
            iterpass = 0;
        else
            ++iterpass;
    }
    return outmess;
}

QByteArray Vigenere::Decrypt(QByteArray inmess, QByteArray passwd)
{
    QByteArray outmess;
    int iterpass = 0;
    for (int i = 0; i < inmess.length(); ++i)
    {
        outmess[i] = inmess[i] - passwd[iterpass];
        if (iterpass == (passwd.length() - 1))
            iterpass = 0;
        else
            ++iterpass;
    }
    return outmess;
}
