#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, r;
    cin >> n >> m >> r;
    r--;
    vector<vector<int>> edge(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    for (int i=0; i<n; i++) {
        sort(edge[i].begin(), edge[i].end());
    }

    vector<long long> order(n, 0), depth(n, -1);
    depth[r]=0;
    int num=1;
    vector<bool> vis(n, false);
    function<void(int)> dfs=[&](int now) {
        vis[now]=true;
        order[now]=num;
        num++;

        for (auto nxt:edge[now]) {
            if (vis[nxt]) continue;
            depth[nxt]=depth[now]+1;
            dfs(nxt);
        }
    };
    dfs(r);

    long long ans=0;
    for (int i=0; i<n; i++) {
        ans+=depth[i]*order[i];
    }
    cout << ans;

    return 0;
}
