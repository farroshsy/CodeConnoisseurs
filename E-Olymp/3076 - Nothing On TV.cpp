#include <iostream>
#include <cstdio>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

const int N = 101111;

struct Point {
    int x, y;
    int index;
    Point() { }
    Point(int x, int y) : x(x), y(y) { }
    Point operator -(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    bool operator <(const Point &p) const {
        return length2() < p.length2();
    }
    long long length2() const {
        long long xx = (long long)x * x;
        long long yy = (long long)y * y;
        return xx + yy;
    }
    long long dot(const Point &p) const {
        return x * p.x + y * p.y;
    }
} p[N];

struct Cmp_by_arg {
    bool operator() ( const Point &p, const Point &q) const {
        double arg1 = atan2(p.y, p.x);
        double arg2 = atan2(q.y, q.x);
        return arg1 < arg2;
    }
};

bool check_legal(const Point &p, const Point &q) {
    return q.dot(p - q) < 0;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        p[i].index = i + 1;
    }
    sort(p, p + n);
    
    set <Point, Cmp_by_arg> st;
    vector <int> ans;
    for (int i = 0; i < n; i++)
        if(st.size() == 0) {
            st.insert(p[i]);
            ans.push_back(p[i].index);
        }
        else {
            set <Point, Cmp_by_arg> :: iterator c = st.lower_bound(p[i]);
            if(c == st.end())
                c = st.begin();
            
            bool flag = true;
            set <Point, Cmp_by_arg> :: iterator it = c;
            for(int t = 0; t < 3; t++) {
                if(!check_legal(p[i], *it))
                    flag = false;
                it++;
                if(it == st.end())
                    it = st.begin();
            }
            it = c;
            for(int t = 0; t < 3; t++) {
                if(!check_legal(p[i], *it))
                    flag = false;
                if(it == st.begin())
                    it = st.end();
                it--;
            }
            if(flag) {
                st.insert(p[i]);
                ans.push_back(p[i].index);
            }
        }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
    
    return 0;
}
