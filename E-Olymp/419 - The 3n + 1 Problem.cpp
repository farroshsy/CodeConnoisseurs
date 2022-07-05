#include <stdio.h>
#include <algorithm>

long int CalculateCycle(long int N) {
    int qCycle = 1;
    
    while(N > 1 && qCycle++)
        N = (N % 2) ? N * 3 + 1 : N / 2;
    return qCycle;
}

int main() {
    long int A, B, C, MaxCycle;
    while(scanf("%ld %ld", &A, &B)) {
        C = A;
        MaxCycle = 0;
        printf("%ld %ld ", A, B);
        if(A > B) {
            A = B;
            B = C;
        }
        
        for(int i = A; i <= B; i++)
            MaxCycle = std::max(MaxCycle, CalculateCycle(i));
        
        printf("%ld\n", MaxCycle);
    }
}
