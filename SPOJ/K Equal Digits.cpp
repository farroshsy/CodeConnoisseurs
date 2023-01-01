#include <map>
#include <iostream>

using namespace std;

typedef long long LL;

map< pair<LL, LL>, LL> periodmem;

LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a%b); }
LL lcm(LL a, LL b) { return (a == 0 || b == 0) ? 0 : a/gcd(a,b)*b; }

LL period(LL modulus, LL dig) {
  LL v = 0;
  if (periodmem.find(make_pair(modulus, dig)) != periodmem.end()) return periodmem[make_pair(modulus, dig)];
  for (LL per=1; per <= modulus; per++) {
    v = (10*v+dig)%modulus;
    if (v == 0) return periodmem[make_pair(modulus, dig)] = per;
  }
  return periodmem[make_pair(modulus, dig)] = 0;
}

int main() {
  LL t;
  cin >> t;
  while(t--) {
    LL bcnt=1, bdig=0;
    LL k,r;

    cin >> k >> r;
    while(r--) {
      LL a, tperiod[10];
      cin >> a;
      for (LL d=1; d<=9; d++) tperiod[d] = 1;
      for (LL f=2; f*f <= a; f++) {
        if ((a%f) != 0) continue;
        LL m = 1;
        while((a%f) == 0) {
          m *= f;
          a /= f;
        }
        for (LL d=1; d<=9; d++) tperiod[d] = lcm(tperiod[d], period(m, d));
      }
      for (LL d=1; d<=9; d++) {
        tperiod[d] = lcm(tperiod[d], period(a, d));
        if (tperiod[d] == 0) continue;
        if (k - (k%tperiod[d]) >= bcnt) {
          bcnt = k - (k%tperiod[d]);
          bdig = d;
        }
      }
    }
    cout << bcnt << " " << bdig << endl;
  }
  return 0;
}
