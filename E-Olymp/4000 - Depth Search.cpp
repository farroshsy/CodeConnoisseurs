#include <stdio.h>
int n, m;
int A[101][101], color[101];

void DFS(int node) {
    color[node] = 1;
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0 && A[node][i] == 1)
            DFS(i);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    DFS(m);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(color[i] == 1) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
