    #include <stdio.h>
    int main() {
        long long n;
        scanf("%lld", &n);
        while(!(n & 1)) n >>= 1;
        long long ans = 2;
        for (long long i = 3; i * i <= n; i += 2) {
            int fact = 1;
            while (n % i == 0) n = n / i, fact++;
            ans = ans * fact;
        }
        if (n > 1) ans <<= 1;
        printf("%lld\n", ans);
        return 0;
    }
