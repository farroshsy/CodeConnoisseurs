#include <cstdio>
#include <algorithm>
using namespace std;

int moves_needed[1000];
int main() {
    int N,M;
    scanf("%d %d", &N, &M);
    
    moves_needed[1] = 2;
    for(int i = 2; i <= M; i++) moves_needed[i] = i*2+2;
    for(int i = 1; i <= M; i++)
        for(int o = 1; o <= i; o++)
            for(int t = 1; t*o+i <= M; t++)
                moves_needed[i+o*t] = min(moves_needed[i+o*t], moves_needed[i]+2+2*t);
    
    if(M>N) {
        printf("0\n");
        return 0;
    }
    
    int answer=moves_needed[M]+2;
    int rectangles_made=(N/M) * N + (N/M) * (N%M);
    
    if(N%M==0) printf("%d\n", answer + 2 * (rectangles_made - 1));
    else {
        int spiral = rectangles_made + N % M - (M-N%M);
        printf("%d\n", answer + 2 * (max(spiral, rectangles_made)-1)+1);
    }
    return 0;
}
        
