// Pi calculation program using Monte Carlo algorithm

#include <iostream>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;

double unitSquarePoint()
{
    return (double)rand()/RAND_MAX;
}

int main()
{
    srand((unsigned)time(0));
    cout.precision(16);

    // Make 2 variables to keep track of how many points
    // we have choosen that are inside the circle
    // and how many that are outside the circle
    unsigned long long total = 0, inCircle = 0;
    while(total < ULLONG_MAX)
    {
        // Choose a random point on a square of 1 unit
        double x = unitSquarePoint(), y = unitSquarePoint();
        // Calculate it's distance from 0, 0
        double d = x*x + y*y;

        // We need to check if the distance is smaller or 
        // or equal to 1. Because sqrt(1) == 1 we don't need
        // to calculate the square root which you normally need
        // in order to use pythagoras theorem
        if(d <= 1.)
            inCircle++;
        total++;

        // Print once every 1 million iteration to get more speed
        if(total % 1000000 == 0)
            cout << 4. * ((double)inCircle/(double)total) << "\n";
    }
}