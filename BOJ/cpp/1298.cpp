#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n);
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        edge[a-1].push_back(b-1);
    }

    vector<bool> vis;
    vector<int> mem(n, -1);

    function<bool(int)> dfs=[&](int now) {
        for (auto nxt:edge[now]) {
            if (vis[nxt]) continue;
            vis[nxt]=true;
            if (mem[nxt]==-1 || dfs(mem[nxt])==true) {
                mem[nxt]=now;
                return true;
            }
        }

        return false;
    };

    int ans=0;
    for (int i=0; i<n; i++) {
        vis=vector<bool>(n, false);
        ans+=dfs(i);
    }
    cout << ans;

    return 0;
}
