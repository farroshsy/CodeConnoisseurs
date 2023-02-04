#include <stdio.h>
#include <algorithm>
using namespace std;
const int MOD = 5000011, MAXN = 100001;
int dp[MAXN][2];

int main() {
    int T, n, k;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &n, &k);
        dp[1][0] = dp[1][1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
            if(i - k - 1 > 0)
                dp[i][1] = (dp[i - k - 1][0] + dp[i - k - 1][1]) % MOD;
            else dp[i][1] = 1;
        }
        printf("%d\n", (dp[n][0] + dp[n][1]) % MOD);
    }
    return 0;
}
