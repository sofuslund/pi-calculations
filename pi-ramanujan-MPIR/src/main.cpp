// Pi with the formula developed by Srinivasa Ramanujan
// For more information see .\formula.png and https://en.wikipedia.org/wiki/Approximations_of_%CF%80#20th_and_21st_centuries

#include <iostream>
#include "pi.h"

using namespace std;

int main()
{
    // The bits of precision of all mpf_class variables
    //const unsigned long long PREC = 32768;
    const unsigned long long PREC = 64;
    ramanujan(PREC, 10000, true);
    cin.get();
}
