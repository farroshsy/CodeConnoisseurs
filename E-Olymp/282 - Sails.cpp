#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    bool count(int x) {
        int u = x % mod;
        for(int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 1e5 + 5;

struct ele {
    int h, gs;
    bool operator < (const ele A) const { return h < A.h; }
} a[N];

int ch[N][2], val[N], tag[N], siz[N], n, root;

inline void update(int u) { siz[u] = siz[ch[u][0]] + siz[ch[u][1]] + 1; }

inline void add_tag(int u, int x) { if(u <= 100000) val[u] += x; tag[u] += x; }

inline void pushdown(int u) {
    if(tag[u]) {
        if(ch[u][0]) add_tag(ch[u][0], tag[u]);
        if(ch[u][1]) add_tag(ch[u][1], tag[u]);
        tag[u] = 0;
    }
}

inline void rotate(int &u, int d) {
    int tmp = ch[u][d];
    ch[u][d] = ch[tmp][d ^ 1];
    ch[tmp][d ^ 1] = u;
    update(u); update(tmp);
    u = tmp;
}

void splay(int &u, int k) {
    pushdown(u);
    int ltree = siz[ch[u][0]];
    if(ltree + 1 == k) return;
    int d = k > ltree;
    pushdown(ch[u][d]);
    int k2 = d ? k - ltree - 1 : k;
    int ltree2 = siz[ch[ch[u][d]][0]];
    if(ltree2 + 1 != k2) {
        int d2 = k2 > ltree2;
        splay(ch[ch[u][d]][d2], d2 ? k2 - ltree2 - 1 : k2);
        if(d == d2) rotate(u, d); else rotate(ch[u][d], d2);
    }
    rotate(u, d);
}

int find(int u, int x) {
    pushdown(u);
    if(!u) return 0;
    if(x > val[u]) return siz[ch[u][0]] + 1 + find(ch[u][1], x);
    return find(ch[u][0], x);
}

void insert(int &u, int x, int y) {
    splay(u, x + 1); splay(ch[u][0], x);
    ch[ch[u][0]][1] = y; update(ch[u][0]); update(u);
}

ll ans;
void dfs(int u) {
    if(!u) return;
    pushdown(u);
    dfs(ch[u][0]);
    if(u <= 100000) ans += 1ll * val[u] * (val[u] - 1) / 2;
    dfs(ch[u][1]);
}

int main() {
    read(n);
    for(int i = 1; i <= n; i++)
        read(a[i].h), read(a[i].gs);
    sort(a + 1, a + n + 1); int now = 1; root = 1;
    ch[root][0] = 100001; ch[root][1] = 100002;
    val[100001] = -1; val[100002] = 100002;
    update(100001); update(100002); update(root);
    for(int i = 1; i <= n; i++) {
        while(now < a[i].h) {
            ++now; update(now);
            insert(root, 1, now);
        }
        splay(root, a[i].gs + 2); splay(ch[root][0], a[i].gs + 1);
        int left = find(ch[root][0], val[ch[root][0]]), v = val[ch[root][0]], l = ch[root][0];
        ch[root][0] = 0; update(root);
        int right = find(root, v + 1);
        if(!right) {
            add_tag(l, 1);
            ch[root][0] = l;
            update(root);
        } else {
            splay(l, left + 1);
            int ll = ch[l][0]; ch[l][0] = 0; update(l);
            add_tag(ll, 1); add_tag(l, 1);
            insert(root, right, l);
            splay(root, 1); ch[root][0] = ll; update(root);
        }
    }
    dfs(root);
    cout << ans << endl;
    return 0;
}
