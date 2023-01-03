#include <stdio.h>
int main() {
    int T, a;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        if(i)
            printf("\n");
        scanf("%d", &a);
        if(a % 6)
            printf("N");
        else
            printf("Y");
    }
    return 0;
}
