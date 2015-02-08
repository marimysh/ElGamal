#ifndef ELGAMAL_H
#define ELGAMAL_H
#include "gmp.h"
#include <QString>

class ElGamal
{
private:
    unsigned long long x, k;        //закрытый ключ и сеансовый
    int lengthmess;
    int shift;
public:
    unsigned long long a[50], b[50];        //открытые ключи
    unsigned long long y, p, g;     //параметр шифрования
    unsigned long long M[50];           //шифруемый текст
    int toch;
    QByteArray barr;                //исходный или расшифрованный текст
    void Encrypt();
    void Decrypt();
    ElGamal();
    void gen(QString inp);
    void genDecrypt(QString inp);
    void setKey(QStringList numberp);
    bool ferma(long long x);
    unsigned long long gcd(unsigned long long a, unsigned long long b);
    unsigned long long mul(unsigned long long a, unsigned long long b, unsigned long long m);
    unsigned long long pows(unsigned long long a, unsigned long long b, unsigned long long m);
    unsigned long long qe2(unsigned long x, unsigned long y, unsigned long long n, unsigned long long z);
    unsigned long long SafeAdd(unsigned long long x, unsigned long long y, unsigned long long n);
    unsigned long long MulPeasant(unsigned long long a, unsigned long long b, unsigned long long n);
    unsigned long long genaratep();     //generate new prime number
    void genaratex(unsigned long long p);
    void setp (unsigned long long newp);    //set new prime number
    int getLength();    //current length message
    unsigned long long QStringtoull(QByteArray number);
    unsigned long long getcloseparam();
    void setcloseparam(unsigned long long newx);
};

#endif // ELGAMAL_H
