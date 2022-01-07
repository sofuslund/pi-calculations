// Pi with the formula developed by Srinivasa Ramanujan
// For more information see .\formula.png and https://en.wikipedia.org/wiki/Approximations_of_%CF%80#20th_and_21st_centuries

// Current digits record of program: 30

#include <iostream>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/math/special_functions/factorials.hpp>
#include <boost/math/constants/constants.hpp>
using namespace std;
using namespace boost::multiprecision;
using namespace boost::math;

typedef cpp_bin_float_100 BF;

inline BF powr(BF a, BF b)
{
    return BF(pow(static_cast<long double>(a), static_cast<long double>(b)));
}

inline BF fact(BF a)
{
    return factorial<BF>(static_cast<unsigned>(a));
}

int main() {
    cout.precision(numeric_limits<BF>::digits10);
    // Calculate the number that should be multiplied with the final sigma expression
    BF m(constants::root_two<BF>());
    m *= 2;
    m /= 9801;
    cout << "M = " << m << endl;

    // Calculate the sigma function
    BF sum(0);
    for(BF n(0); n < 10000; n++) {
        // Calculate the numerator
        // (4k)!(1103+26390k)
        BF num(fact(4*n));
        BF tmp(1103);
        tmp += BF(26390) * n;
        num *= tmp;

        // Calculate the denominator
        BF den(powr(fact(n), BF(4)));
        den *= powr(BF(396), 4*n);

        if(num != 0 && den != 0)
            sum += num/den;
        
        BF pi(1);
        pi /= m * sum;
        cout << "pi = " << pi << endl;
    }
    cin.get();
}