#include <iostream>
#include <vector>
#define MAXN 1000000000ll
typedef long long ll;
using namespace std;

bool solve(ll max, vector<ll>& s, vector<ll>& f, vector<ll>& a, vector<ll>& b) {
    ll n = s.size();
    ll RLS = 0;
    for (int i = 0; i < n; ++i){
        ll limit = min(max, f[i]);
        if (limit < s[i])
            continue;
        RLS += (limit - s[i]) / (a[i] + b[i]) * a[i];
        ll r = (limit - s[i]) % (a[i] + b[i]);
        if (r >= a[i])
            RLS += a[i];
        else
            RLS += r + 1;
        
    }
    if (RLS % 2 == 1)
        return 1;
    else
        return 0;
}

void count() {
    ll n;
    cin >> n;
    vector<ll> s(n), f(n), a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i] >> f[i] >> a[i] >> b[i];
    
    ll l = 0, rs = MAXN;
    while (l <= rs){
        ll mid = (l + rs) / 2;
        if (solve(mid, s, f, a, b))
            rs = mid - 1;
    }
    if (l > MAXN)
        l = 0;
    cout << l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test = 1;
    while(test--){
        count();
    return 0;
    }
}
