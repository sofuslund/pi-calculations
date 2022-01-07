#pragma once
#include <iostream>
#include <iomanip>
#include <mpirxx.h>
#include "math.h"

using namespace std;

mpf_class ramanujan(int prec, unsigned long long cycles, bool show_output=true)
{
    // Get the length of the number of cycles when converted to a string
    const int CYCLES_PRINT_LENGTH = to_string(cycles).length();

    // Make a variable to contain the final value of pi
    mpf_class pi(0, prec);

    // Calculate the number that should be multiplied with the final sigma expression
    mpf_class m(sqrt(mpf_class(8, prec)), prec);
    m /= 9801;

    // Set the print precision
    cout.precision(prec);
    // Show the precision bits if that is specified
    if(show_output)
        cout << "precision = " << prec << endl;

    // Calculate the sigma function
    mpf_class sum(0, prec);
    unsigned long long iteration = 0;
    for(iteration = 0; iteration < cycles; iteration++) {
        // Calculate the numerator
        // (4k)!(1103+26390k)
        mpf_class num(fact(4*iteration, prec), prec);
        mpf_class tmp(1103, prec);
        tmp += mpf_class(26390, prec)*iteration;
        num *= tmp;

        // Calculate the denominator
        // (k!)^4 * 396^4k
        mpf_class f(fact(iteration, prec), prec);
        mpf_class den(f * f * f * f, prec);
        den *= pow(mpf_class(396, prec), 4*iteration, prec);

        if(num != 0 && den != 0)
            sum += num/den;
        
        // Print output if that is specified to be done
        if(show_output)
        {
            // Calculate pi
            pi = 1 / (m * sum);
            // Print the number of iterations followed by what pi is estimated to be
            // The number of iterations is padded with spaces to right so it always is the same print width
            cout << left << setw(CYCLES_PRINT_LENGTH) << iteration+1 << "|" << pi << endl;
        }
    }
    cout << "Iteration EQUALS:: == :: " << iteration << "!!!!!!!!!!! ? what SERIOUSLY. Are. You. Kidding. Me... YOU LITTLE SHIT" << endl;
    // Calculate pi and return it
    pi = 1 / (m * sum);
    return pi;
}