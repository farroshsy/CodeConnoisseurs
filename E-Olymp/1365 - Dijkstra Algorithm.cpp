#include <iostream>
const int MAXN = 1e9;
int RLS[101];
int a[101][101];
int d[101];
bool False = 0;
bool True = 1;
using namespace std;
int main() {	
    int r = 0, n, s, t, tn, u;
    //scanf("%d %d %d", &n, &s, &t);
    cin >> n;
    cin >> s >> t;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            if(a[i][j] == -1)
                a[i][j] = MAXN;
        }
    }
    for(int v = 1; v <= n; v++) {
        d[v] = a[s][v];
        RLS[v] = False;
    }
    d[s] = 0;
    RLS[s] = True;
    while(!RLS[t]) {
        tn = MAXN;
        r++;
        for(int v = 1; v<= n; v++) {
            if((!RLS[v]) && (tn > d[v])) {
                u = v;
                tn = d[v];
            }
        }
        RLS[s] = True;
        if(!RLS[t]) {
            for(int v = 1; v <= n; v++) {
                if((!RLS[v]) && (d[u] + a[u][v] < d[v])) {
                    d[v] = d[u] + a[u][v];
                }
            }
        }
        if(r > 101) {
            printf("-1");
            return 0;
        }
    }
    printf("%d", d[t]);
}
