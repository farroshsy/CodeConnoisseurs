#include <stdio.h>
#include <string.h>

bool p[20010];
int num[10010];
int ct;

int ans[20010];


int main() {
    int i, j;
    p[1] = 1;
    for(i = 2; i <= 150; i++) {
        if(!p[i]) {
            for(j = i; i * j <= 20000; j++)
                p[i * j] = 1;
        }
    }
    ct = 0;
    for(i = 2; i < 20000; i++) {
        if(p[i] == 0)
            num[ct++] = i;
    }
    memset(ans, 0, sizeof(ans));
    for(i = 0; i < ct; i++) {
        for(j = i + 1; j < ct; j++) {
            if(num[i] + num[j] <= 20000)
                ans[num[i] + num[j]]++;
        }
    }
    int n,m;
    while(scanf("%d", &n) != EOF) {
        if(n % 2 == 0)
            printf("%d\n", ans[n]);
        else {
            int ret = 0;
            for(i = 1; i < ct && num[i] < n; i++) {
                m = n - num[i];
                ret += ans[m];
                if(ans[m] > 0 && m > num[i] && !p[m - num[i]] && m != num[i] * 2)
                    ret--;
            }
            printf("%d\n", ret / 3);
        }
    }
    return 0;
}
