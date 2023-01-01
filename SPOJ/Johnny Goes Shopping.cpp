#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main ()
{
    int n;
    cin>>n;
    int w[n];
    for(int i=0;i<n;i++)
        cin>>w[i];
    sort(w,w+n);
    
    int wl=0,wr=0;
    int mValue=(2*n)/3;
    for(int i=0;i<mValue;i++)
        cout<<i+1<<endl;
  
    return 0;
}
