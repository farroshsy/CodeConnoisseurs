#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int MAXN = 5010;
int RC[MAXN];
bool vis[15];
vector<int> g[MAXN];
queue<int> q;

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    for(int i = 1; i <= m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; ++i)
        RC[i] = -1;
    for(int i = 1; i <= k; ++i)
        RC[i] = i - 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < g[u].size(); ++i) {
            int v = g[u][i];
            if(RC[v] != -1)
                continue;
            RC[v] = (RC[u] + 1) % k;
            for(int j = 0; j < k; ++ j)
                vis[j] = false;
            for(int j = 0; j < g[v].size(); ++j) {
                int t = g[v][j];
                if(RC[t] == -1)
                    continue;
                vis[RC[t]] = true;
            }
            while(vis[RC[v]]) RC[v] = (RC[v] + 1) % k;
            q.push(v);
        }
    }
    for(int i = 1; i <= n; ++i)
        printf("%d", RC[i] + 1);
    return 0;
}
