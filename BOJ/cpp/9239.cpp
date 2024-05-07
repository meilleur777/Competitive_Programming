#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    const long long g10=1e4;
    string s;
    cin >> s;
    long long xx;
    if (s.find('.')!=string::npos) {
        string integer=s.substr(0, s.find('.'));
        string fractional=s.substr(s.find('.')+1);
        fractional=fractional+string((4-(int)fractional.length()), '0');
        xx=stoll(integer)*g10+stoll(fractional);
    }
    else {
        xx=stoll(s)*g10;
    }

    if (xx>=10*g10) {
        cout << "No solution";
        return 0;
    }

    int cnt=0;
    for (int k=0; k<8; k++) {
        for (int a=1; a<=9; a++) {

            long long power=(long long)pow(10, k);

            if (a*(xx*power-g10)%(10*g10-xx)==0) {
                long long b=(a*(xx*power-g10)/(10*g10-xx));
                long long m=b*10+a;
                long long n=a*power+b;

                string nn=to_string(n);
                string mm=nn.substr(1)+nn.front();
                if (to_string(m)!=mm) continue;

                cnt++;
                cout << n << '\n';
            }
        }
    }
    if (!cnt) cout << "No solution";

    return 0;
}
