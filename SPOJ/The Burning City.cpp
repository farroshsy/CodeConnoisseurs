#include <stdio.h>
using namespace std;
 
int main() {
    int T;
    scanf("%d", &T);
    int n, c, h, sx, sy, i,j;
    char temp, Buffer[2];
    for (int t=0; t<T; t++) {
        scanf("%d %d %d %d %d", &n, &c, &h, &sx, &sy);
        for (i=0; i<n; i++) {
            for (j=0; j<n; j++) {
                scanf("%s", &temp);
            }
            scanf("%s", &Buffer[2]);
        }
        printf("city %d Y\n", t + 1);
        for (i=0; i<h; i++) {
            printf("-");
        }
        printf("\n");
    }
    return 0;
}
