#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> cnt(m, 0); //cnt[A] := number of cow attending group A
    vector<vector<int>> grp(n); //grp[A] := groups which A attends

    for (int i=0; i<m; i++) {
        cin >> cnt[i];
        for (int j=0; j<cnt[i]; j++) {
            int b;
            cin >> b;
            b--;
            grp[b].push_back(i);
        }
    }

    //calculate willing of cow i
    vector<long long> willing(n, 0);
    for (int i=0; i<n; i++) {
        long long denominator=1;
        for (auto j:grp[i]) denominator*=cnt[j];
        long long numerator=0;
        for (auto j:grp[i]) numerator+=denominator/cnt[j];
        if (denominator!=0) willing[i]=(numerator+denominator-1)/denominator;
    }

    vector<bool> vis;
    vector<int> par(m, -1);
    function<bool(int)> dfs=[&](int now) {
        for (auto nxt:grp[now]) {
            if (vis[nxt]) continue;
            vis[nxt]=true;
            if (par[nxt]==-1 || dfs(par[nxt])) {
                par[nxt]=now;
                return true;
            }
        }

        return false;
    };

    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<willing[i]; j++) {
            vis=vector<bool>(m, false);
            ans+=dfs(i);
        }
    }

    if (ans>=m) {
        for (int i=0; i<m; i++) {
            cout << par[i]+1 << '\n';
        }
    }
    else cout << -1;

    return 0;
}
