#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

int t;
ll n;
const string table1[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Ninteen"};
const string table2[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string convert(int num) {
    if(num == 1000) {
        return "One Thousand";
    }
    int hundred = num / 100;
    int ten = num % 100;
    string res;
    if(hundred > 0) {
        res = table1[hundred] + " Hundred";
    }
    if(ten < 20) {
        if(ten) {
            if(res.length())
                res.push_back(' ');
            res += table1[ten];
        }
    }
    else {
        int one = ten % 10;
        if(res.length())
            res.push_back(' ');
        res += table2[ten/10];
        if(one) {
            res.push_back(' ');
            res += table1[one];
        }
    }
    return res;
}

int main() {
        scanf("%lld", &n);
        int billion = n / 1000000000;
        int million = n / 1000000 % 1000;
        int thousand = n / 1000 % 1000;
        int one = n % 1000;
        string res;
        if(billion) {
            res = convert(billion) + " Billion";
        }
        if(million) {
            if(res.length())
                res.push_back(' ');
            res += convert(million) + " Million";
        }
        if(thousand) {
            if(res.length())
                res.push_back(' ');
        res += convert(thousand) + " Thousand";
        }
        if(one) {
            if(res.length())
                res.push_back(' ');
        res += convert(one);
        }
        cout << res << endl;
    return 0;
}
