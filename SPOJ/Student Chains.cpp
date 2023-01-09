#include<cstdio>
using namespace std;
typedef long long LL;
int main(){
    int t;
    LL a[33], pow2, n;
    scanf("%d", &t);
    pow2 = 4ll;
    for(int i = 2; i <= 31; i++){
        a[i - 1] = (LL)i * pow2 - 1ll;
        pow2 = pow2 * 2ll;
    }
    while(t--){
        scanf("%lld", &n);
        for(int i = 1; i <= 30; i++){
            if(n <= a[i]) { printf("%d\n", i); i = 33; }
        }
    }
    return 0;
}
