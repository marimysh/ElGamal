#include <math.h>
#include "elgamal2.h"

#include "iostream"
#include "limits"
#include "QStringList"

unsigned long long MAXINT = std::numeric_limits<unsigned long long int>::max();

ElGamal::ElGamal()
{
    toch = 3;
    shift = 7;
    lengthmess = 0;
}

void ElGamal::gen(QString inp)
{
    if (inp.size() == 0)
    {
        M[0] = -1;
        return;
    }
    QByteArray barr = inp.toAscii();
    //M[0] = (int)barr[0] - 32;          //32 - номер первого печатного символа

    int iterM = 0;
    for (int i = 0; i < barr.size(); i++)
    {
        M[iterM] = 0;
        for (int j = 1; j <= toch; ++j, ++i)
        {
            M[iterM] = M[iterM] << shift;
            if (barr[i] != 10 && barr.size() > i)
                M[iterM] = M[iterM] + (int)barr[i] - 31;  //if M == 0 - end of line
            barr[i] = 0;
        }
        --i;
        if (M[iterM] != 0)
            ++iterM;
    }
    M[iterM] = -1;
    return;
}

void ElGamal::genDecrypt(QString inp)
{
    lengthmess = 0;
    QStringList numberkey = inp.split(" ");
    int i = 0;
    while (numberkey.length()-1 > i)
    {
        this->a[lengthmess] = this->QStringtoull(numberkey.at(i++).toAscii());
        this->b[lengthmess++] = this->QStringtoull(numberkey.at(i++).toAscii());
    }
    return;
}

void ElGamal::Encrypt()
{
    //unsigned long long int temp_simple;
    srand(time(NULL));                      //reload random every start programm
    //temp_simple = 8434963;                  //test simple number
    //std::cout << temp_simple << std::endl;
    //p = temp_simple;
    //x = rand() % p;
    //g = rand() % (p-1);

    int lengthMess = -1;
    int iterM = 0;
    while (lengthMess == -1)
    {
        if (M[iterM] == -1)
            lengthMess = iterM;
        else
            iterM++;
    }
    this->lengthmess = lengthMess;
    iterM = 0;
    for (int i = 0; i < lengthMess; ++i)
    {
        srand(time(NULL));
        bool fl_simple_kp = true;           //for original general
        while (fl_simple_kp)
        {
            k = rand() % p;
            if (gcd(k, p) == 1)
                fl_simple_kp = false;
        }
        /*x = 8;            //test
        p = 11;
        g = 2;
        k = 9;
        */
        //y = qe2(g, x, p, 1);
        a[i] = qe2(g, k, p, 1);
        b[i] = qe2(y, k, p, M[i]);

        std::cout << "p = " << p << std::endl;
        std::cout << "k = " << k << std::endl;
        std::cout << "x = " << x << std::endl;
        std::cout << "g = " << g << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "a = " << a[i] << std::endl;
        std::cout << "b = " << b[i] << std::endl;
        std::cout << "M = " << M[i] << std::endl << std::endl;
    }
    return;
}

void ElGamal::Decrypt()
{
    unsigned long long mess;
    /*
    int lengthMess = -1;
    int iterM = 0;
    while (lengthMess == -1)
    {
        if (M[iterM] == -1)
            lengthMess = iterM;
        else
            iterM++;
    }
    */
    int itermess = 0;
    for (int i = 0; i < this->lengthmess; ++i)
    {
        mess = qe2(a[i], p-x-1, p, b[i]);
        std::cout << "mess = " << mess << std::endl;
        for (int i = 0; i < this->toch; ++i)
        {
            barr[itermess + toch - 1 - i] = mess & 127;           //маска 1111111
            if (barr[itermess + toch - 1 - i] == 0)               //если конец строки
                barr[itermess + toch - 1 - i] = 10;
            else
                barr[itermess + toch - 1 - i] = barr[itermess + toch - 1 - i] + 31;
            mess = mess >> shift;
        }
        itermess += toch;
    }

    for (int i = 0; i < itermess; ++i)
    {
        std::cout << barr[i];
    }
    std::cout << std::endl;
    return;
}

//Проверка числа на простоту
bool ElGamal::ferma(long long x){
    if(x == 2)
        return true;
    srand(time(NULL));
    for(int i = 0; i < 25; i++){
        long long a = (rand() % (x - 2)) + 2;
        if (gcd(a, x) != 1)
            return false;
        if( qe2(a, x-1, x, 1) != 1)
            return false;
    }
    return true;
}

//НОД двух чисел. Алгоритм Евклида
unsigned long long ElGamal::gcd(unsigned long long a, unsigned long long b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

// x^y mod N
unsigned long long ElGamal::qe2(unsigned long x, unsigned long y, unsigned long long n, unsigned long long z) {
   unsigned long long s, u;
   s = z;
   u = y;
   while (u > 0)
   {
       s = MulPeasant(x, s, n);
       --u;
   }
   return s;
}

unsigned long long ElGamal::MulPeasant(unsigned long long a, unsigned long long b, unsigned long long n)
{
    a = a % n; // не нужно, если гарантированно a < n
    b = b % n; // не нужно, если гарантированно b < n
    int acc = 0;
    while (b > 0)
    {
        if ((b & 1) != 0)
            acc = SafeAdd(acc, a, n);
        a = SafeAdd(a, a, n);
        b >>= 1;
    }
    return acc;
}

unsigned long long ElGamal::SafeAdd(unsigned long long x, unsigned long long y, unsigned long long n)
{
    if (x <= MAXINT - y) // проверка на переполнение сложения
    {
        int result = x + y; // x, y < n, x + y < 2n. (x + y) mod n равно или x + y,
        return (result >= n) ? (result - n) : result;  // или x + y - n
    }
    else // в этом случае x + y > MAXINT >= n, но x + y < n + n = 2n
    {    // значит (x + y) mod n = x + y - n
        return x - (n - y); // n - y > 0, вычитаем два положительных числа меньших n
    }
}

void ElGamal::setp(unsigned long long newp)
{
    this->p = newp;
    return;
}

unsigned long long ElGamal::genaratep()
{
    bool fl_empty = true;
    unsigned long long int temp_simple;
    srand(time(NULL));                    //reload random every start programm
    while (fl_empty)
    {
        temp_simple = 0;
        if (this->toch * 2 + 1 <= 10)           //toch <= 4
        {
            int range = pow(10, this->toch * 2 + 1);
            temp_simple += rand() % range;
        }
        else
        {
            bool fl_enouth = false;
            unsigned long long range = pow(10, this->toch * 2 + 1);
            while (!fl_enouth)
            {
                temp_simple += rand();
                if (temp_simple >= range)
                    fl_enouth = true;
            }
            int random = rand() % 10;
            for (int i = 0; i < random; ++i)
                temp_simple += rand();
        }
        //temp_simple = 7;                              //test
        std::cout << "no " << temp_simple << std::endl; //test
        //for screenings bologo number of cases
        if (temp_simple % 2 != 0 && temp_simple % 5 != 0 && temp_simple % 3 != 0 && temp_simple % 7 != 0 && temp_simple % 11 != 0)
            fl_empty = !ferma(temp_simple);
    }
    return temp_simple;
}

void ElGamal::genaratex(unsigned long long p)
{
    if (this->toch * 2 + 1 <= 10)
    {
        unsigned long long range = pow(10, this->toch * 2);
        this->x = p - rand() % range;     //x
        this->g = p - rand() % range;
        this->y = qe2(this->g, this->x, p, 1);  //y
        return;
    }
    else
    {
        this->x = p - rand();             //x
        this->g = p - rand();
        this->y = qe2(this->g, this->x, p, 1);
        return;
    }
}

int ElGamal::getLength()
{
    return this->lengthmess;
}

unsigned long long ElGamal::QStringtoull(QByteArray number)
{
    unsigned long long result = 0;
    for (int i = 0; i < number.length(); ++i)
        if (number[i] >= 48 && number[i] <= 57)
            result = result*10 + number[i] - 48;
    return result;
}

void ElGamal::setKey(QStringList numberp)
{
    this->p = this->QStringtoull(numberp.at(0).toAscii());
    this->g = this->QStringtoull(numberp.at(1).toAscii());
    this->y = this->QStringtoull(numberp.at(2).toAscii());
    return;
}

unsigned long long ElGamal::getcloseparam()
{
    return this->x;
}

void ElGamal::setcloseparam(unsigned long long newx)
{
    this->x = newx;
    return;
}
