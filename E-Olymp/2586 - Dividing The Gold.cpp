#include <iostream>
using namespace std;
typedef long long ll;
const ll mod = 1e6;
ll n, sum, a[300], f[500005], dp[500005];
int main() {
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i], sum += a[i];
    for(ll i = 1; i <= n; i++) {
        for(ll j = sum/2; j >= a[i]; j--)
            f[j] = max(f[j], f[j - a[i]] + a[i]);
    }
    printf("%lld\n", sum - 2 * f[sum/2]);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = sum; j >= a[i]; j--)
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    }
    printf("%lld\n", dp[f[sum/2]]);
    return 0;
}
