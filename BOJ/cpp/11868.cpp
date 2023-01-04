#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll k=0;
    for (int i=0; i<n; i++) k^=a[i];

    if (k) cout << "koosaga";
    else cout << "cubelover";

    return 0;
}
