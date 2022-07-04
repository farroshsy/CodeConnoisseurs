#include <stdio.h>
#include <string.h>
#include <math.h>
typedef long long ll;
const int N = 2;
const int p = 10000;

struct Matrix {
    ll m[N][N];
    Matrix() {
        memset(m, 0, sizeof(m));
    }
    Matrix operator*(Matrix &a) {
        Matrix ans;
        memset(ans.m, 0, sizeof(ans.m));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                for(int k = 0; k < N; k++) {
                    ans.m[i][j] += (m[i][k] * a.m[k][j]) % p;
                }
            }
        }
        return ans;
    }
};

Matrix RLS(Matrix a, ll n) {
    Matrix res;
    for(int i = 0; i < N; i++) {
        res.m[i][i] = 1;
    }
    while(n) {
        if(n & 1)
            res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

ll u[50];
void temp() {
    u[0] = 0;
    u[1] = u[2] = 1;
    for(int i = 3; i < 40; i++) {
        u[i] = u[i - 1] + u[i - 2];
    }
    return;
}
int top(ll n) {
    double t = -0.5 * log10(5.0) + (double)n * log10((1 + pow(5.0, 0.5)) / 2);
    t = t - floor(t);
    double x = pow(10, t + 3);
    return (ll) floor(x);
}
void solve() {
    temp();
    ll n;
    Matrix base;
    base.m[0][0] = base.m[0][1] = 1;
    Matrix k;
    k.m[0][0] = k.m[0][1] = k.m[1][0] = 1;
    while(scanf("%lld", &n)) {
        if(n < 40) {
            printf("%lld\n", u[n]);
        }
        else {
            printf("%d...", top(n));
            Matrix ans = RLS(k, n - 1);
            ans = ans * base;
            printf("%04d\n", ans.m[0][0] % p);
        }
    }
}
int main() {
    solve();
    return 0;
}
