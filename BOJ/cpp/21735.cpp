#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    int ans=0;
    function<void(int, int, int)> dfs=[&](int now, int tim, int val) {
        if (now==n || tim==m) {
            ans=max(ans, val);
            return;
        }
        dfs(now+1, tim+1, val+a[now+1]);
        if (now+2<n) {
            dfs(now+2, tim+1, val/2+a[now+2]);
        }
    };
    dfs(-1, 0, 1);
    cout << ans;

    return 0;
}
