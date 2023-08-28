#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    ll d, p, q;
    cin >> d >> p >> q;
    if (p<q) swap(p, q);
    ll ans=LLONG_MAX;
    for (ll i=0; i<=min(q, (d+p-1)/p); i++) {
        ans=min(ans, p*i+(d-p*i+q-1)/q*q);
    }
    cout << ans;

    return 0;
}
