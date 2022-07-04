#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

int d, k, c;
vector <string> v;
map <string, int> used;

ll mod(string &it) {
    int r = 0;
    for(int i = 0; i < it.length(); ++i) {
        r = r * 10 + it[i] - '0';
        r %= d;
    }
    return r;
}

void thing(int count, string it) {
    if(count == k) {
        if(mod(it) == 0)
            c++;
    }
    else if (count < k) {
        for(int i = 0; i < v.size(); ++i) {
            if(used[v[i]]) {
                used[v[i]]--;
                thing(count + 1, it + v[i]);
                used[v[i]]++;
            }
        }
    }
}
int main() {
    cin >> d >> k;
    string p;
    for(int i = 0; i < k; ++i) {
        cin >> p;
        if(!used[p]) {
            v.push_back(p);
        }
        ++used[p];
    }
    c = 0;
    thing(0, "");
    cout << c << "\n";
    return 0;
}
