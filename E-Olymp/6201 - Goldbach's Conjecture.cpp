#include <stdio.h>
#include <math.h>
#define N 32000
#define GC 16000

struct pos{
    int x;
    int y;
};

int main() {
    struct pos gc[GC];
    int arr[N] = {0}, i, t, j, n;
    arr[1] = 1;
    for(i = 2; i < sqrt(N); i++) {
        if(arr[i] == 0) {
            for(j = i * 2; j < N; j = j + i) {
                arr[j] = 1;
            }
        }
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int p = 0;
        for(i = 2; i <= (n / 2); i++){
            j = n - i;
            if(arr[i] == 0 && arr[j] == 0) {
                gc[p].x = i;
                gc[p].y = j;
                p++;
            }
        }
        printf("%d has %d representation(s)\n", n, p);
        for(i = 0; i < p; i++) {
            printf("%d+%d\n", gc[i].x, gc[i].y);
        }
    }
    return 0;
}
