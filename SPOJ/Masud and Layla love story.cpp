#include <iostream>
#include <numeric>
#define ull unsigned long long

using namespace std;

ull solve(ull n, ull k) {
    ull gcd = __gcd(n,k);
    ull cnt = n / gcd;
    ull u1 = ((n - 1) % gcd) ? 1 : 0;
    ull sum = cnt * (2 * u1 + (cnt - 1) * gcd) / 2;
    return sum;
}

int main() {
    ull n,k;
    cin >> n >> k;
    cout << solve(n,k) << endl;
    return 0;
}

