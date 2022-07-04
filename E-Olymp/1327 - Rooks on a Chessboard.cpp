#include <stdio.h>
#define MAXN 3000
int temp[MAXN];
int main() {
    temp[0] = 1;
    int l = 1, n, flag = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < l; j++){
            int T = temp[j] * i + flag;
            temp[j] = T % 10;
            flag = T / 10;
        }
        while(flag){
            temp[l++] = flag % 10;
            flag /= 10;
        }
    }
    for(int k = l - 1; k >= 0; k--)
        printf("%d", temp[k]);
}
