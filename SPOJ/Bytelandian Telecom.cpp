#include<iostream>
using namespace std;

int scan(){
      int t=0;
      char c;
      c=getchar_unlocked();
      while(c<'0' || c>'9')
                  c=getchar_unlocked();
      while(c>='0' && c<='9'){
                   t=(t<<3)+(t<<1)+c-'0';
      c=getchar_unlocked();
      }
      return(t);
}
 
int main() {
    int i,j,p[50000],n,m,a,b;
    i = scan();
    int ch=0;
    while(i>0) {
        ch++;
    j = scan();
    while(j--)
    p[j] = scan();
    m = scan();
    n = scan();
    while(m--){
        a = scan();
        b = scan();
    }
    cout <<"city " <<ch << " N\n";
    i--;}
return 0;
}
