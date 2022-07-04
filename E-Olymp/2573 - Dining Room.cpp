#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
#define N ((int)5e3 + 5)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct ptt {
    int x,y;
};

vector < pair < ptt, int > > vec;
bool inn;
int dist;


int dis(ptt a, ptt b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

bool out(ptt p, ptt a, ptt b) {
    int tmp = min(dis(p, a), dis(p,b));
    if(tmp <= dist)
        return 0;
    if((p.x == a.x && a.x == b.x) || (p.y == a.y && b.y)) {
        if(p.x < a.x || p.x > b.x || p.y < a.y || p.y > b.y)
            return 1;
        return 0;
    }
    if((a.x != b.x || a.y != b.y) && ((p.x > a.x && p.x < b.x) || (p.y > a.y && p.y < b.y))) {
        if(a.x == b.x)
            tmp = abs(a.x - p.x);
        else
            tmp = abs(a.y - p.y);
        return tmp > dist;
    }
    else
        return 1;
}

bool vis[N][N];

ptt fun(int a, int b, int c, int d)
{
    if(a > c || b > d)
        return {
            -1, -1
        };
    bool flag = 1;
    for(auto p:vec) {
        ptt pnt = p.first;
        int tmp;
        
        if(inn) {
            tmp = max(dis(pnt, {a,b}), dis(pnt, {a,d}));
            tmp = max(tmp, max(dis(pnt, {c,d}), dis (pnt, {c,b})));
            if(tmp <= dist) {
                return {
                    -1, -1
                };
            }
        }
        else {
            if(out(pnt, {a,b}, {c,b}) && out(pnt, {a,b}, {a,d}) && out(pnt, {a,d}, {c,d}) && out(pnt, {c,b}, {c,d})) {
                if(pnt.x < a || pnt.x > c || pnt.y < b || pnt.y > d) {
                    return {
                            -1, -1
                        };
                    }
                }
            }
        }
        if(a == c && b == d) {
            if(vis[a][b])
                return {
                    -1, -1
                };
            return {
                a, b
            };
        }
        int midx = (a + c) >> 1, midy = (b + d) >> 1;
        ptt ans = fun(a, b, midx, midy);
        if(ans.x == a)
            return ans;
        ptt tmpp = fun(a, midy + 1, midx, d);
        if(ans.x != -1 && tmpp.x != -1) {
            if(ans.x <= tmpp.x)
                return ans;
            return tmpp;
        }
        else if(ans.x != -1)
            return ans;
        else if(tmpp.x != -1)
            return tmpp;
        ans = fun(midx + 1, midy + 1, c, d);
        if(ans.x == midx + 1)
            return ans;
        tmpp = fun(midx + 1, midy + 1, c, d);
        if(ans.x != -1 && tmpp.x != -1) {
            if(ans.x <= tmpp.x)
                return ans;
            return tmpp;
        }
        else if(ans.x != -1)
            return ans;
        else if(tmpp.x != -1)
            return tmpp;
        return {
            -1, -1
        };
    }

    
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= q; i++) {
        string str;
        cin >> str;
        if(str[0] == 'e'){
            inn = 0;
            int kiri = 1, kanan = (n + m) * (n + m);
            while(kiri < kanan) {
                int mid = (kiri + kanan) >> 1;
                dist = mid;
                if(fun(0, 0, n, m).x != -1)
                    kanan = mid;
                else
                    kiri = mid + 1;
            }
            dist = kiri;
            ptt ans = fun(0, 0, n, m);
            vec.push_back({ans, i});
            cout << ans.x << " " << ans.y << endl;
            vis[ans.x][ans.y] = 1;
        }
        else if(str[0] == 'i') {
            inn = 1;
            int kiri = 0, kanan = (n + m) * (n + m);
            while(kiri < kanan) {
                int mid = (kiri + kanan + 1) >> 1;
                dist = mid;
                if(fun(0, 0, n, m).x != -1)
                    kiri = mid;
                else
                    kanan = mid -1;
            }
            dist = kiri;
            ptt ans = fun(0, 0, n, m);
            vec.push_back({ans, i});
            cout << ans.x << " " << ans.y << endl;
            vis[ans.x][ans.y] = 1;
        }
        else {
            int num = 0;
            for(int j = 0; j < str.length(); j++)
                num = num * 10 + (str[j] - '0');
            bool flag = 0;
            for(int j = 0; j < vec.size(); j++) {
                if(vec[j].second == num) {
                    vis[vec[j].first.x][vec[j].first.y] = 0;
                    vec.erase(vec.begin() + j);
                    flag = 1;
                    break;
                }
            }
            assert(flag);
        }
    }
    return 0;
}
