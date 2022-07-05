#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>

using ll = long long;
using namespace std;

const int MAXN = 5*100000+1;
set<ll> arr[MAXN];
set<ll> s;

void func() {
    int N;
   // scanf("%d", &N);
    cin >> N;
    vector<ll> v(N);
    for(int i = 0; i < N; i++)
        cin >> v[i];
    //scanf("%lld", &v[i]);
    arr[N - 1].insert(v[N = 1]);
    s.insert(v[N - 1]);
    
    for(int i = N - 2; i >= 0; i--) {
        for(auto x:arr[i + 1]) {
            arr[i].insert(__gcd(x,v[i]));
        }
        arr[i].insert(v[i]);
        arr[i + 1].clear();
        for(auto x:arr[i])
            s.insert(x);
    }
    //printf("%lu\n", s.size());
    cout << s.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    func();
}
