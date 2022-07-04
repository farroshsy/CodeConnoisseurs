#include <stdio.h>
#include <cmath>
int main() {
    int n, i, fib[40], a[15010];
    const double x = log10(1.0 / sqrt(5.0));
    const double y = log10(1.0 + sqrt(5.0)) / 2.0;
    fib[0] = 0, fib[1] = 1, a[0] = 0, a[1] = 1;
    for(i = 2; i < 40; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    for(i = 2; i <15000; i++) {
        a[i] = a[i - 1] + a[i - 2];
        if(a[i] >= 10000)
            a[i] %= 10000;
    }
    while(scanf("%d", &n) != EOF) {
        if(n < 40) {
            printf("%d\n", fib[n]);
            continue;
        }
        
        double res;
        res = x + n * y;
        res -= (int)res;
        res = pow(10, res) * 1000;
        printf("%d...%0.4d\n", (int)res, a[n % 15000]);
    }
    return 0;
}
