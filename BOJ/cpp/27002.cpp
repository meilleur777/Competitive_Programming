#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<bool> isprime(2e5+1, 1);
    isprime[0]=false, isprime[1]=false;
    for (int i=2; i<=2e5; i++) {
        if (!isprime[i]) continue;
        for (int j=i*2; j<=2e5; j+=i) {
            isprime[j]=false;
        }
    }
    
    int n;
    cin >> n;

    int ans=1;
    int amx=0;
    while (n--) {
        int a;
        cin >> a;

        int t=a;
        int mx=0;
        for (int i=2; i*i<=t; i++) {
            if (!isprime[i]) continue;
            while (a%i==0) {
                a/=i;
                mx=max(mx, i);
            }
        }
        if (a!=1) mx=max(mx, a);

        if (amx<mx) {
            amx=mx;
            ans=t;
        }
    }
    cout << ans;

    return 0;
}
