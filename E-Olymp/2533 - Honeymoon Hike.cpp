#include <stdio.h>
#include <cstring>
const int MAXN = 10005;

int a[MAXN][MAXN], vis[MAXN][MAXN], n;
int dirx[] = {
    0, 0, 1, -1
};
int diry[] = {
    1, -1, 0, 0
};

bool dfs(int x, int y, int low, int high){
    vis[x][y] = 1;
    if(a[x][y] > high || a[x][y] < low)
        return false;
    if(x == n && y == n)
        return true;
    for(int i = 0; i < 4; i++) {
        int dx = x + dirx[i], dy = y + diry[i];
        if(dx >= 1 && dx <= n && dy >= 1 && dy <= n && !vis[dx][dy]) {
            if(dfs(dx, dy, low, high))
                return true;
        }
    }
    return false;
}

bool check(int x) {
    for(int i = 0; i + x <= 200; i++){
        memset(vis, 0, sizeof(vis));
        if(dfs(1, 1, i, i + x))
            return true;
    }
    return false;
}

int main() {
    int test;
    scanf("%d", &test);
    int c = 0;
    while(test--) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int l = 0, r = 200, ans = 0;
        while(r - l >= 0) {
            int mid = (l + r) >> 1;
            if(check(mid)) {
                r = mid - 1;
                ans = mid;
            }
            else {
                l = mid + 1;
            }
        }
        printf("Scenario #%d:\n%d\n\n", ++c, ans);
    }
    return 0;
}
