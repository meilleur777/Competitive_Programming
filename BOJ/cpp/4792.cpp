#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while (true) {
        int n, m, k;
        cin >> n >> m >> k;
        if (n==0 && m==0 && k==0) break;

        vector<vector<pair<int, int>>> edge(n);
        while (m--) {
            char c;
            int a, b;
            cin >> c >> a >> b;
            a--, b--;
            if (c=='B') {
                edge[a].push_back({b, 1});
                edge[b].push_back({a, 1});
            }
            else {
                edge[a].push_back({b, 0});
                edge[b].push_back({a, 0});
            }
        }

        vector<bool> vis;
        function<void(int, int)> dfs=[&](int now, int cost) {
            vis[now]=true;
            for (auto nxt:edge[now]) {
                if (vis[nxt.first]) continue;
                if (nxt.second!=cost) continue;
                dfs(nxt.first, cost);
            }
        };

        vector<int> num(2, 0);
        for (int i=0; i<2; i++) {
            vis=vector<bool>(n, false);
            for (int j=0; j<n; j++) {
                if (vis[j]) continue;
                num[i]++;
                dfs(j, i);
            }
        }

        //minimum number of blue edge to make spanning tree
        num[0]=num[0]-1;
        //maximum number of blue edge to make spanning tree
        num[1]=n-num[1];

        if (num[0]<=k && k<=num[1]) cout << 1 << '\n';
        else cout << 0 << '\n';
    }

    return 0;
}
