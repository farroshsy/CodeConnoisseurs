#include <stdio.h>

int main() {
    int R, L, S;
    bool flag = 0;
    while(scanf("%d %d %d", &R, &L, &S) == 3) {
        if(R == 0 && L == 0 && S == 0)
            flag = 1;
        else if((L - R) == (S - L))
            printf("\nAP %d\n", S + (L - R));
        else
            printf("GP %d\n", S * L / R);
    }
    return 0;
}
