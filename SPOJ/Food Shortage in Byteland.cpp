#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    for(int testcase = 1;testcase <= t;testcase++){
        int n, m;
        scanf("%d %d", &n, &m);
        int x[n], y[n], a[n], b[n], c[n];
        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d %d", &x[i], &y[i], &a[i], &b[i], &c[i]);
        }
        int p, q;
        scanf("%d %d", &p, &q);
        bool okay = 0;
        int distance = 2 * (abs(p - x[0]) + abs(q - y[0])) + c[0];
        if(distance <= m)
            okay = 1;
        int shops = 0;
        int minutes = c[0];
        printf("%d\n", testcase);
        if(okay)
                printf("%d %d\n", shops + 1, minutes);
        printf("0 0\n");
    }
}
