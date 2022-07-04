// C++ program to represent a given
// number as sum of minimum possible
// psuedobinary numbers
#include<iostream>
using namespace std;


void psuedoBinary(int n)
{
    // Repeat below steps until n > 0
    while (n > 0)
    {
        // calculate m (A number that has same
        // number of digits as n, but has 1 in
        // place of non-zero digits 0 in place
        // of 0 digits)
        int temp = n, m = 0, p = 1;
        while (temp)
        {
            int rem = temp % 10;
            temp = temp / 10;

            if (rem != 0)
                m += p;
            
            p *= 10;
        }
        
        cout << m << " ";

        // subtract m from n
        n = n - m;
    }
}

// Driver code
int main()
{
    int n = 2;

    psuedoBinary(n);

    return 0;
}
