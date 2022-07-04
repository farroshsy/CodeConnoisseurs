#include <stdio.h>
#include <string.h>
typedef long long ll;
int r[2016][2016];
int l[2016][2016];

int main() {
    int Test, sum, ans, q, s[100];
    ll n, k;
    while(scanf("%d", &Test) != EOF) {
        ans = 0;
        while(Test--) {
            memset(s, 0, sizeof(s));
            scanf("%lld", &n);
            k = 0;
            while(n > 0) {
                s[k] = n % 2;
                n /= 2;
                k++;
            }
            for(int i = 0; i < k; i += 8) {
                q = 1;
                sum = 0;
                for(int j = i; j <= i + 7; j++) {
                    sum += q * s[j];
                    q *= 2;
                }
                if(sum == 97)
                    ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
