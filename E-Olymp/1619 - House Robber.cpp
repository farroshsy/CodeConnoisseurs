#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1000005;

int main() {
    ll n, a[MAXN], dp[MAXN];
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[1]);
    }
    dp[1] = a[1];
    dp[2] = max(a[1], a[2]);
    for(int i = 3; i <= n; i++) {
        dp[i] = max(a[i] + dp[i - 2], dp[i - 1]);
    }
    printf("%lld\n", dp[n]);
}
