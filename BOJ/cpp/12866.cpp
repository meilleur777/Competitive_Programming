#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const long long mod=1e9+7;
        
    int l;
    string s;
    cin >> l >> s;

    map<char, long long> cnt;
    for (auto c:s) cnt[c]++;

    if (cnt.size()<4) cout << 0;
    else {
        long long ans=1;
        for (auto [p, q]:cnt) {
            ans=(ans*q)%mod;
        }
        cout << ans;
    }

    return 0;
}
