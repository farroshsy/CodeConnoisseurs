//masi salah
#include <stdio.h>
const int M = 1e5 + 7;

int t;
int n, m;
int a[M], du[M];
int ans = 0;

struct edge {
    int t, n;
}e[M * 2];

int head[M], cnt;

void add(int u, int v) {
    e[cnt].t = v;
    e[cnt].n = head[u];
    head[u] = cnt++;
}

void dfs(int u, int f, int sum) {
    if(a[u])
        sum++;
    else
        sum = 0;
    if(sum > m)
        return;
    if(du[u] == 1 && sum <= m)
        ans++;
    for(int i = head[u]; ~i; i = e[i].n) {
        int v = e[i].t;
        if(v!=f)
            dfs(v, u, sum);
    }
}

void solve(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]), head[i] = -1;
    for(int i = 1; i < n; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
        du[u]++;
        du[v]++;
    }
    dfs(1, 0, 0);
    printf("%d", ans);
}

int main() {
    solve();
    return 0;
}
