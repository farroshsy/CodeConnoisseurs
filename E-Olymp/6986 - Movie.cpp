#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

typedef double db;
using namespace std;
const db eps = 1e-9;

db a, b, ans;
int k;

struct RLS {
    double x, y;
    int R;
}p[8];

void solve(int i) {
    db x = p[i].x, y = p[i].y;
    db mtpl = min(x / a, y / b);
    db nx = (int)(a * mtpl + eps), ny = (int)(b * mtpl + eps);
    db rl = (nx * ny) / (x * y);
    
    if(rl > ans && fabs(ans - rl) > eps) {
        ans = rl;
        k = i;
    }
    else if(fabs(ans - rl) <= eps) {
        if(p[k].R > p[i].R)
            k = i;
    }
}

void solves(int i) {
    db x = p[i].x, y = p[i].y;
    db mtpl = min(x / a, y / b);
    db nx = (int)(a * mtpl + eps), ny = (int)(b * mtpl + eps);
    db rll = (nx * ny) / (x * y);
    
    if(rll > ans && fabs(ans - rll) > eps) {
        ans = rll;
        k = i;
    }
    else if(fabs(ans - rll) <= eps) {
        if(p[k].R > p[i].R)
            k = i;
    }
}

int main() {
    p[0].x = 1024, p[0].y = 768, p[0].R = 319;
    p[1].x = 1024, p[1].y = 600, p[1].R = 419;
    p[2].x = 960, p[2].y = 640, p[2].R = 450;
    p[3].x = 2048, p[3].y = 1536, p[3].R = 519;
    p[4].x = 1136, p[4].y = 640, p[4].R = 599;
    p[5].x = 1280, p[5].y = 800, p[5].R = 600;
    p[6].x = 1080, p[6].y = 1920, p[6].R = 630;
    p[7].x = 1136, p[7].y = 640, p[7].R = 719;
    while(cin>>a>>b) {
        if(a == 0 && b == 0)
            break;
        ans = 0;
        for(int i = 0; i < 8; ++i) {
            solve(i);
        }
        for(int i = 0; i < 8; ++i) {
            solves(i);
        }
        cout<<p[k].R<<endl;
    }
    return 0;
}
