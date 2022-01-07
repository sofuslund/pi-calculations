// Pi with the formula developed by Srinivasa Ramanujan
// For more information see .\formula.png and https://en.wikipedia.org/wiki/Approximations_of_%CF%80#20th_and_21st_centuries

#include <iostream>
#include <math.h>
using namespace std;

long long fact(long long a)
{
    return (a==0) ? 1 : a * fact(a-1);
}

int main() {
    cout.precision(20);
    // Calculate the number that should be multiplied with the final sigma expression
    long double m = sqrt(2.L) * 2.L;
    m /= 9801;

    // Calculate the sigma function
    long double sum = 0;
    for(long double n = 0; n < 1000; n++) {
        // Calculate the numerator
        // (4k)!(1103+26390k)
        long double num = (long double)fact(long(4.L*n));
        num *= 1103.L + 26390.L*n;

        // Calculate the denominator
        long double den = pow((long double)fact(long(n)), 4.L);
        den *= pow(396.L, 4.L*n);

        if(num != 0 && den != 0)
            sum += num/den;
        long double pi = 1.L / (m * sum);
        cout << "pi = " << pi << endl;
    }
    cin.get();
}