#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> edge(n);
    for (int i=0; i<n; i++) {
        int jobn;
        cin >> jobn;
        for (int j=0; j<jobn; j++) {
            int job;
            cin >> job;
            edge[i].push_back(job-1);
        }
    }

    vector<bool> vis;
    vector<int> mem(m, -1);

    function<bool(int)> dfs=[&](int now) {
        for (auto nxt:edge[now]) {
            if (vis[nxt]) continue;
            vis[nxt]=true;
            if (mem[nxt]==-1 || dfs(mem[nxt])) {
                mem[nxt]=now;
                return true;
            }
        }

        return false;
    };

    int ans=0;
    for (int i=0; i<n; i++) {
        vis=vector<bool>(m, false);
        ans+=dfs(i);
    }
    for (int i=0; i<n; i++) {
        vis=vector<bool>(m, false);
        while (k) {
            if (dfs(i)) {
                ans++;
                k--;
            }
            else break;
        }
    }

    cout << ans;

    return 0;
}
