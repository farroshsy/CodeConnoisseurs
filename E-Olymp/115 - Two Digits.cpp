#include <stdio.h>

int main() {
    int n, a[31];
    scanf("%d", &n);
    a[0] = 2;
    a[1] = 4;
    for(int i = 2; i < 31; i++)
        a[i] = a[i - 1] + a[i - 2];
    printf("%d", a[n - 1]);
    return 0;
}
