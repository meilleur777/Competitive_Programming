#include <bits/stdc++.h>
using namespace std;

//Minimum Vertex Cover in Bipartite Graph
//Konig's Theorem
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n);
    for (int i=0; i<n; i++) {
        int c;
        cin >> c;
        while (c--) {
            int b;
            cin >> b;
            b--;
            edge[i].push_back(b);
        }
    }

    //Bipartite Matching Using DFS
    vector<bool> vis;
    vector<int> par(m, -1);

    function<bool(int)> dfs=[&](int now){
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

    int coverSize=0;
    for (int i=0; i<n; i++) {
        vis=vector<bool>(m, false);
        coverSize+=dfs(i);
    }

    //Find all unmatched node in Left
    vector<bool> matchedL(n, false);
    for (int i=0; i<m; i++) {
        if (par[i]==-1) continue;
        matchedL[par[i]]=true;
    }

    //If node is unmateched in Left, assign cover node B in Right
    //the node in Left that matches node B should not be in vetex cover set
    //After finding all such node B,
    //all uncovered nodes in Left should be in vertex cover set
    vector<bool> inCoverL(n, false);
    vector<bool> inCoverR(m, false);

    function<void(int)> findCover=[&](int now) {
        inCoverL[now]=true;

        for (auto nxt:edge[now]) {
            if (inCoverR[nxt]==true) continue;
            inCoverR[nxt]=true;
            findCover(par[nxt]);
        }
    };

    for (int i=0; i<n; i++) {
        if (matchedL[i]) continue;
        findCover(i);
    }

    cout << coverSize << '\n';
    vector<vector<int>> ans(2);
    for (int i=0; i<n; i++) if (!inCoverL[i]) ans[0].push_back(i+1);
    for (int i=0; i<m; i++) if (inCoverR[i]) ans[1].push_back(i+1);
    for (int i=0; i<2; i++) {
        cout << ans[i].size() << ' ';
        for (auto j:ans[i]) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}
