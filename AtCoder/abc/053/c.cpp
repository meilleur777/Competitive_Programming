#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long x;
    cin >> x;

    long long ans=0;
    ans=x/11*2;
    x%=11;
    if (x!=0) {
        if (x<=6) ans++;
        else ans+=2;
    }

    cout << ans;

    return 0;
}
