#include <iostream>
#include <vector>
using namespace std;
int n, m, i, x, y, bal, ans[1000001];

struct det {
    int pos, type, id;
};

bool solve(det &a, det &b) {
    if(a.pos < b.pos)
        return 1;
    if(a.pos > b.pos)
        return 0;
    return (a.type < b.type);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    vector <det> h;
    cin >> n >> m;
    while(n--) {
        cin >> x >> y;
        h.push_back( {
            min(x, y), 0, 0
        });
        h.push_back( {
            max(x, y), 2, 0
        });
    }
    for(i = 1; i <= m; i++) {
        cin >> x;
        h.push_back({
            x, 1, i
        });
    }
    sort(h.begin(), h.end(), solve);
    for(auto e : h) {
        if(e.type == 0)
            bal++;
        else if(e.type == 1)
            ans[e.id] = bal;
        else
            bal--;
    }
    for (i = 1; i <= m; i++)
        cout << ans[i] << " ";
}
