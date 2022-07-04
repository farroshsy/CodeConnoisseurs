#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

string to_string(vector <bool> v) {
    bool first = true;
    string res = "[";
    for(int i = 0; i < static_cast <int> (v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "]";
    return res;
}
template <typename A>
string ts(A v) {
    bool first = true;
    string res = "[";
    for(const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "]";
    return res;
}

ll dp[255];
void solve() {
    ll n, m;
    cin >> n >> m;
    vector <ll> v(m +1);
    for(int i = 1; i <= m; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    dp[0] = 1;
    for(int j = 1; j <= m; j++) {
        for(int i = v[j]; i <= n; i++) {
            dp[i] += dp[i - v[j]];
        }
    }
    cout << dp[n] << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long t = 1;
    for(int i = 1; i <= t; i++)
        solve();
}
