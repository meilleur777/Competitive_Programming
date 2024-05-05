#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> edges) {
    vector<vector<int>> arcs(n+1);
    for (auto edge:edges) {
        arcs[edge[0]].push_back(edge[1]);
        arcs[edge[1]].push_back(edge[0]);
    }

    vector<int> vis(n+1, -1);
    queue<int> q;
    q.push(1);
    vis[1]=0;
    while (!q.empty()) {
        int now=q.front();
        q.pop();

        for (auto nxt:arcs[now]) {
            if (vis[nxt]!=-1) continue;
            vis[nxt]=vis[now]+1;
            q.push(nxt);
        }
    }

    int ret=0;
    int mx=*max_element(vis.begin(), vis.end());
    for (int i=1; i<=n; i++) {
        if (mx==vis[i]) ret++;
    }

    return ret;
}