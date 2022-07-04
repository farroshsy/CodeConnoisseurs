#include <cstdio>
#include <cstdlib>
#include <cstdbool>
#include <cstring>
#include <vector>
using namespace std;
typedef unsigned long long ull;

bool found = 0;
double chosen[100];
int inx;
vector<double> vec;
char* angkaa;
char* angkaaa;
double d1,d2;

void bf(int deep = 0, int choose = 0, double a = 1, double b = 1) {
   if(vec.size() == deep) {
       if(vec.size() / 2 == choose) {
           if(a == b) {
               found = 1;
               for(int i = 0; i < choose; i++) {
                   if(i == 0)printf("%.f",chosen[i]);
                   else printf(" %.f",chosen[i]);
               }
               printf("\n");
               return;
           }
           else return;
       }
       else return;
   }

   if(found) return;
   inx++;
   chosen[inx] = vec[deep];
   bf(deep + 1, choose + 1, a * (double)vec[deep], b);
   inx--;
   bf(deep + 1, choose, a, b * (double)vec[deep]);
}
int main ()
{
    char uangka[999];
    bool aman = true;
    while(scanf("%[^\n]%*c",uangka) != EOF && aman) {
        bool coba1 = false;
        inx = -1;
        d1 = strtod(uangka,&angkaaa);
        if(d1 == 0)break;
        vec.push_back(d1);
        d2 = d1;
        while(d2 != 0){
            if(!coba1){
                d2 = strtod(angkaaa,&angkaa);
                coba1 = true;
            }
            else if(coba1){
                d2 = strtod(angkaa, &angkaaa);
                coba1 = false;
            }
            if(d2 != 0)vec.push_back(d2);
        }
        d2 = d1;
        if(d2 == 0)break;
        bf();
        vec.clear();
        found = 0;
    }
}
