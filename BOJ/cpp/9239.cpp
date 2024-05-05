#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long double x;
    cin >> x;
    long long xx=10000*x;

    if (xx>=100000) {
        cout << "No solution";
        return 0;
    }

    int cnt=0;
    for (int k=0; k<8; k++) {
        for (int a=1; a<=9; a++) {

            long long power=(long long)pow(10, k);

            if (!(a*(xx*power-10000)%(100000-xx))) {
                long long b=(a*(xx*power-10000)/(100000-xx));
                long long m=b*10+a;
                long long n=a*power+b;
                string nn=to_string(n);
                string mm=nn.substr(1)+nn.front();
                // cout << n << ' ' << m << '\n';
                // cout << nn << ' ' << mm << '\n';
                if (to_string(m)!=mm) continue;
                // if ((int)to_string(b).length()<k) continue;
                // if (b<(long long)pow(10, k-1) || b>=(long long)pow(10, k)) continue;
                cnt++;
                cout << n << '\n';
            }
        }
    }
    if (!cnt) cout << "No solution";

    return 0;
}
