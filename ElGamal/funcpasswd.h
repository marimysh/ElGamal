#ifndef FUNCPASSWD_H
#define FUNCPASSWD_H

#include "QByteArray"

class FuncPasswd
{
public:
    FuncPasswd();
    static bool TruePasswd(QByteArray passwd);
};

#endif // FUNCPASSWD_H
