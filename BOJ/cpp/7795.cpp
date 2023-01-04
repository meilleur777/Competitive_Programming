#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        rep(i, n) cin >> a[i];
        rep(i, m) cin >> b[i];

        ll ans=0;
        sort(b.begin(), b.end());
        for (int i=0; i<n; i++) {
            ans+=lower_bound(b.begin(), b.end(), a[i])-b.begin();
        }

        cout << ans << '\n';
    }

    return 0;
}
