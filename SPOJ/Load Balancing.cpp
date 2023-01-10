#include <stdio.h>
#include <cmath>
#include <algorithm>

int arr[10000];
int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        if(n < 0)
            return 0;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        if(ceil((double)sum / (double)n) != floor((double)sum / (double)n)) {
            puts("-1");
            continue;
        }
        int temp = sum / n;
        int c = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            arr[i] += c;
            c = arr[i] - temp;
            ans = fmax(abs(c), ans);
        }
        printf("%d\n", ans);
    }
}
