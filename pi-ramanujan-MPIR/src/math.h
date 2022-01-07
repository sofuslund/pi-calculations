#pragma once
#include <mpirxx.h>

mpf_class fact(mpf_class a, int PREC)
{
    // If the number is negative turn it positive and then floor the number
    mpf_class b(floor(abs(a)), PREC);
    return (b==0) ? mpf_class(1, PREC) : b * fact(b-1, PREC);
}

mpf_class pow(mpf_class n, mpf_class e, int PREC)
{
    // Initialize --------------------- |
    mpf_t res;
    mpf_init2(res, PREC);
    // Calculate ---------------------- |
    mpf_pow_ui(res, n.get_mpf_t(), e.get_ui());
    // Clean -------------------------- |
    mpf_class res_class(res, PREC);
    mpf_clear(res);
    // Return ------------------------- |
    return res_class;
}