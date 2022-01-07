// Pi with the formula developed by Gottfried Leibniz. For more information:
// https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80

#include <iostream>
#include <climits>
using namespace std;

int main() {
    cout.precision(20);
    // The denominator of the recursive division each iteration
    unsigned long long d=3;
    double p=1.;
    // Only run while the denominator variable has not exceeded the maximum number of it's type
    while(d < ULLONG_MAX) {
        // Calculate the number of iteration by the fact that the denominator started at 3 and grows by 2 each loop
        unsigned long long c = d/2-1;

        // If the iteration counter is even subtract the division from pi
        if(c % 2 == 0)
            p -= 1./d;
        // Else add the division to pi
        else
            p += 1./d;

        // Printing is slow therefore only do it every 1 million iterations
        if(c%1000000==0) {
            // Leibniz's formula get pi/4 hence the pi variable needs to be multiplied by 4 first
            cout << p*4. << "\n";
        }
        d += 2;
    }
}