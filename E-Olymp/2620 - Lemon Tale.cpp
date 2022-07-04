#include <stdio.h>
typedef long long ll;

ll dp[10005][200], mx = 1e17;
void add(ll i) {
    ll j = 0;
    while(dp[i][j] > 0) {
        dp[i + 1][j] += dp[i][j] + dp[i][j];
        if(dp[i + 1][j] >= mx) {
            dp[i + 1][j + 1];
            dp[i + 1][j] -= mx;
        }
        j++;
    }
}

void sub(ll i, ll j) {
    ll k = 0, tot, carry = 0;
    while(dp[j][k] + carry > 0) {
        tot = dp[i][k] - dp[j][k] - carry;
        if(tot < 0){
            dp[i][k] = mx + tot;
            carry = 1;
        }
        else {
            dp[i][k] = tot;
            carry = 0;
        }
        k++;
    }
}

int main() {
    ll i, j, n, k;
    scanf("%lld %lld", &n, &k);
    for(i = dp[0][0] = 1; i <= k; i++) {
        add(i - 1);
    }
    if(k < n) {
        add(k);
        sub(k + 1, 0);
    }
    for(i = j = k; i <= n; i++) {
        add(i - 1);
        sub(i, i - j);
    }
    i = 190;
    while(i >= 0 && dp[n][i] == 0)
        i--;
    if(i >= 0)
        printf("%lld", dp[n][i--]);
    while(i >= 0) {
        printf("%017lld", dp[n][i--]);
    }
}
