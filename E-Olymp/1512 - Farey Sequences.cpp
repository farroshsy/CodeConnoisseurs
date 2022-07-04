#include <stdio.h>
int main() {
    int n, k;
    while(scanf("%d %d", &n, &k)) {
        int a0 = 0, a1 = 1, b0 = 1, b1 = n, a2, b2;
        for(int i = 1; i < k; i++){
            int c = (n + b0) / b1;
            a2 = c * a1 - a0;
            b2 = c * b1 - b0;
            a0 = a1;
            a1 = a2;
            b0 = b1;
            b1 = b2;
        }
        printf("%d/%d\n", a1, b1);
    }
}
