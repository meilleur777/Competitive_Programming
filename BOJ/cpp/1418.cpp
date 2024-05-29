#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<bool> isPrime(k+1, true);
    isPrime[0]=isPrime[1]=false;
    for (int i=2; i<=k; i++) {
        if (!isPrime[i]) continue;
        for (int j=i*2; j<=k; j+=i) {
            isPrime[j]=false;
        }
    }

    int ans=0;
    for (int i=1; i<=n; i++) {
        int tmp=i;
        for (int j=2; j<=k; j++) {
            if (!isPrime[j]) continue;
            
            while (tmp%j==0) {
                tmp/=j;
            }
        }

        if (tmp==1) ans++;
    }

    cout << ans;

    return 0;
}
