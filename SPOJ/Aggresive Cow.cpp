#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

bool solve(ll k, vector<ll> &a, int cow) {
    ll lcow = a[1];
        --cow;
    for(int i = 2; i < (int)a.size(); ++i) {
        if(a[i] - lcow >= k) {
            lcow = a[i];
            --cow;
        }
    }
    return cow <= 0;
}

void check() {
    int n, c;
    cin >> n >> c;
    vector<ll> a(n + 1);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    ll l = 0, r = 1e15, res = 0;
    while(l <= r) {
        ll mid = l + (r - 1) / 2;
        if(solve(mid, a, c)) {
            res = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << res << '\n';
}

int main() {
    int test;
    cin >> test;
    while(test--)
        check();
    return 0;
}
