#include <bits/stdc++.h>
using namespace std;

void endProgram() {
    cout << -1;
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edge(m);
    map<pair<int, int>, int> edgeToNum;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge[i]={u, v};
        edgeToNum[{u, v}]=i;
        edgeToNum[{v, u}]=i;
    }

    if (n<=2) endProgram();

    int compNum=0;
    vector<int> vis(n, -1);
    vector<bool> selected(m, false);
    for (int i=0; i<n; i++) {
        if (vis[i]!=-1) continue;

        function<void(int)> dfs=[&](int now) {
            vis[now]=compNum;

            for (auto nxt:adj[now]) {
                if (vis[nxt]!=-1) continue;
                selected[edgeToNum[{now, nxt}]]=true;
                dfs(nxt);
            }
        };

        dfs(i);
        compNum++;
    }

    if (compNum>2) endProgram();

    if (compNum==2) {
        vector<int> compCrd(2, 0);
        for (int i=0; i<n; i++) {
            compCrd[vis[i]]++;
        }

        if (compCrd[0]==compCrd[1]) endProgram();

        vector<vector<int>> ansNode(2);
        vector<vector<int>> ansEdge(2);
        for (int i=0; i<n; i++) {
            ansNode[vis[i]].push_back(i);
        }
        for (int i=0; i<m; i++) {
            if (selected[i]) {
                ansEdge[vis[edge[i].first]].push_back(i);
            }
        }

        cout << (int)ansNode[0].size() << ' ' << (int)ansNode[1].size() << '\n';
        for (int i=0; i<2; i++) {
            for (auto j:ansNode[i]) cout << j+1 << ' ';
            cout << '\n';
            for (auto j:ansEdge[i]) cout << j+1 << '\n';
            cout << '\n';
        }
    }
    else {
        vector<int> degree(n, 0);
        for (int i=0; i<m; i++) {
            if (selected[i]) {
                degree[edge[i].first]++;
                degree[edge[i].second]++;
            }
        }

        int alone=-1;
        for (int i=0; i<n; i++) {
            if (degree[i]==1) {
                alone=i;
                break;
            }   
        }

        vector<int> ansNode, ansEdge;
        vector<bool> vis(n, false);
        vis[alone]=true;

        function<void(int)> dfs=[&](int now) {
            vis[now]=true;
            ansNode.push_back(now);

            for (auto nxt:adj[now]) {
                if (vis[nxt]) continue;
                ansEdge.push_back(edgeToNum[{now, nxt}]);
                dfs(nxt);
            }
        };
        for (int i=0; i<n; i++) {
            if (vis[i]) continue;
            dfs(i);
        }

        cout << 1 << ' ' << n-1 << '\n';
        cout << alone+1 << "\n\n";
        for (auto i:ansNode) cout << i+1 << ' ';
        cout << '\n';
        for (auto i:ansEdge) cout << i+1 << ' ';
        cout << '\n';
    }

    return 0;
}
