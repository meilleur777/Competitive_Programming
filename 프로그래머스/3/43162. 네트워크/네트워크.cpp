#include <bits/stdc++.h>
using namespace std;

//count # of components in graph using dfs
int solution(int n, vector<vector<int>> edge) {
    
    vector<bool> vis(n, false);
    function<void(int)> dfs=[&](int now) {
        if (vis[now]) return;
        vis[now]=true;
        for (int i=0; i<n; i++) {
            if (i!=now && edge[now][i]) {
                dfs(i);
            }
        }
    };
    
    int ret=0;
    for (int i=0; i<n; i++) {
        if (!vis[i]) {
            ret++;
            dfs(i);
        }
    }
    
    return ret;
}