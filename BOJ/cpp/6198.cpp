#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    stack<int> sk;
    sk.push(0);
    ll ans=0;
    for (int i=1; i<n; i++) {
        while (!sk.empty() && a[sk.top()]<=a[i]) {
            sk.pop();
        }
        sk.push(i);
        ans+=(int)sk.size()-1;
    }
    cout << ans;

    return 0;
}
