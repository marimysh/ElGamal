#include "funcpasswd.h"

FuncPasswd::FuncPasswd()
{
}

bool FuncPasswd::TruePasswd(QByteArray passwd)
{
    if (passwd.length() < 8)
        return false;
    bool flLow = false, flUp = false, flNumb = false;
    for (int i = 0; i < passwd.length(); ++i)
    {
        if (passwd[i] >= 48 && passwd[i] <= 57)
            flNumb = true;
        else if (passwd[i] >= 65 && passwd[i] <= 90)
            flUp = true;
        else if (passwd[i] >= 97 && passwd[i] <= 122)
            flLow = true;
    }
    return (flNumb && flUp && flLow);
}
