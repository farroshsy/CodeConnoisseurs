#include <stdio.h>

int main() {
    int mat[106][106], n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++){
            printf("%d ", mat[j][i]);
        }
        printf("\n");
    }
    return 0;
}
