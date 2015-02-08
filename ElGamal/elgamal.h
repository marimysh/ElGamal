#ifndef ELGAMAL_H
#define ELGAMAL_H

#include "QString"
#include "gmp.h"
#include "bignum.h"

#define ECCRYPT_BIGNUM_DIGITS BIGNUM_MAX_DIGITS

class elgamal
{
private:
    bignum_digit_t x[ECCRYPT_BIGNUM_DIGITS], k[ECCRYPT_BIGNUM_DIGITS];
public:
    bignum_digit_t p[ECCRYPT_BIGNUM_DIGITS], g[ECCRYPT_BIGNUM_DIGITS], a[ECCRYPT_BIGNUM_DIGITS], b[ECCRYPT_BIGNUM_DIGITS];
    bignum_digit_t y[ECCRYPT_BIGNUM_DIGITS];
    bignum_digit_t M[ECCRYPT_BIGNUM_DIGITS];
    elgamal(char inp[]);
    void cryptel(char res[]);
};

#endif // ELGAMAL_H
