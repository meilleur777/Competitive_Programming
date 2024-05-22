#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<bool> isSoft(n, false);
    for (int i=0; i<n; i++) {
        int a;
        char c;
        cin >> a >> c;
        if (c=='s') isSoft[a-1]=true;
    }

    vector<vector<int>> edge(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        if (isSoft[a]) edge[a].push_back(b);
        else edge[b].push_back(a);
    }

    vector<bool> vis;
    vector<int> par(n, -1);
    function<bool(int)> dfs=[&](int now) {
        for (auto nxt:edge[now]) {
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
        if (!isSoft[i]) continue;
        vis=vector<bool>(n, false);
        ans+=dfs(i);
    }
    cout << n-ans;

    return 0;
}
