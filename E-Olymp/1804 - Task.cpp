#include <iostream>
#include <vector>
#include <climits>
typedef long long ll;
const int N = 1e9;
using namespace std;

struct edge {
    int from, to, cost;
};

int n, m;
string s;

bool BellFord(int src, vector<edge>& edges, vector<int>& d, int nodes) {
    d.assign(nodes, N);
    d[src] = 0;
    for(int i = 1; i <= nodes; ++i) {
        bool r = false;
        for(auto & e : edges) {
            if(d[e.from] < N) {
                if(d[e.to] > d[e.from] + e.cost) {
                    d[e.to] = max(-N, d[e.from] + e.cost);
                    r = true;
                }
            }
        }
        if(!r)
            return true;
        if(i == nodes)
            return false;
    }
    return 0;
}
    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(cin >> n >> m) {
        vector<edge> g;
        while(m--) {
            int i, j, t;
            bool c = true;
            cin >> s >> i >> s >> s;
            if(s == "at") {
                c = false;
                cin >> s >> t;
            }
            else {
                cin >> t >> s >> s >> s;
            }
            cin >> s >> s >> s >> s >> j;
            
            if(c) {
                g.push_back({i, j, 0});
                g.push_back({j, i, t});
            }
            else {
                g.push_back({i, j, -t});
            }
        }
        for(int i = 1; i <= n; ++i) {
            g.push_back({0, i, 0});
        }
        vector<int> d;
        if(BellFord(0, g, d, n + 1)) {
            int minVal = INT_MAX;
            for(int i = 1; i <= n; ++i) {
                minVal = min(minVal, d[i]);
            }
            for(int i = 1; i <= n; ++i) {
                cout << d[i] + (1 - minVal) << " \n"[i == n];
            }
        }
        else
            cout << "Impossible.\n";
    }
    return 0;
}
