#include <stdio.h>
#include <algorithm>
using namespace std;
int n, c;
long long dp[1005][1005][2][2];
int main() {
    dp[0][1][1][1] = 1;
    while(scanf("%d", &n) && n) {
        c++;
        int R = (n + 4) >> 1, L = (n - 4) >> 1;
        for(int i = 1; i <= R; i++) {
            dp[i][0][0][0] = 1;
            for(int j = max(1,i - 5); j <= min(L, i + 1); j++) {
                dp[i][j][0][0] = dp[i - 1][j][0][0] + dp[i - 1][j][1][0];
                dp[i][j][0][1] = dp[i - 1][j][0][1] + dp[i - 1][j][1][1];
                dp[i][j][1][0] = dp[i][j - 1][0][0];
                dp[i][j][1][1] = dp[i][j - 1][0][1];
            }
        }
        printf("Case %d: %lld\n", c, n % 2 || n < 4 ? 0 : dp[R][L][0][0] + dp[R][0][1][0] + dp[R][0][1][0]);
    }
    return 0;
}
