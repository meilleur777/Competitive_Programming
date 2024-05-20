#include <bits/stdc++.h>
using namespace std;

const long long mod=1e9+7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int h, w, a, b;
    cin >> h >> w >> a >> b;

    vector<long long> facto(w+h);
    facto[0]=1;
    for (long long i=1; i<w+h; i++) {
        facto[i]=facto[i-1]*i%mod;
    }

    //return a^b
    function<long long(long long, long long)> power=[&](long long a, long long b) {
        if (b==1) return a;
        long long tmp=power(a, b/2);
        tmp=tmp*tmp%mod;
        if (b%2==1) return tmp*a%mod;
        return tmp;
    };

    function<long long(long long)> modinv=[&](long long x) {
        return (power(x, mod-2));
    };
 
    function<long long(int, int)> combination=[&](int n, int c) {
        return facto[n]*modinv(facto[c])%mod*modinv(facto[n-c])%mod;
    };

    long long ans=0;
    for (int i=1; i<=h-a; i++) {
        ans+=(combination(i+b-2, i-1)*combination(h-i-1+w-b, w-b-1)%mod);
        ans%=mod;
    }
    cout << (ans+mod)%mod << '\n';

    return 0;
}
