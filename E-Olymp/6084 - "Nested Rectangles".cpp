#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int maxn=1005;
int G[102][102],d[maxn],a[102],n,b[102];;

int dp(int i)
{
    int& ans=d[i];
    if(ans>0) return ans;
    ans=1;
    for(int j=1;j<=n;j++){
        if(G[i][j]) ans=max(ans,dp(j)+1);
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        memset(d,0,sizeof(d));
        memset(G,0,sizeof(G));
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((a[i]>a[j]&&b[i]>b[j])||(a[i]>b[j]&&b[i]>a[j]))
                    G[i][j]=1;
            }
        }
        int ans=1;
        for(int i=1;i<=n;i++)
            ans=max(dp(i),ans);
        printf("%d\n",ans);
    }
    return 0;
}
