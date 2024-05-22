#include <bits/stdc++.h>
using namespace std;

//Max-flow min-cut problem
//Dinic's algorithm
//Initialize residual graph G as given graph.
//Do BFS of G to construct a level graph and also check if more flow is possible.
//If more flow is not possible, then return
//Send multiple flows in G using level graph until blocking flow is reached. (DFS)
//Time Complexity O(V^2*E)
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const int inf=0x3f3f3f3f;
    
    int n;
    cin >> n;
    //member->0~n-1, src->n, dst->n+1
    int siz=n+2;
    int src=n, dst=n+1;
    vector<int> team(siz);
    vector<vector<int>> edge(siz);
    vector<vector<int>> flow(siz, vector<int>(siz, 0));
    vector<vector<int>> capacity(siz, vector<int>(siz, 0));
    for (int i=0; i<n; i++) {
        cin >> team[i];
        if (team[i]==1) {
            capacity[src][i]=inf;
            edge[src].push_back(i);
            edge[i].push_back(src);
        }
        else if (team[i]==2) {
            capacity[i][dst]=inf;
            edge[i].push_back(dst);
            edge[dst].push_back(i);
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> capacity[i][j];
            if (i!=j) edge[i].push_back(j);
        }
    }


    //Make Level graph, only using nodes which more flow can be sent
    vector<int> level;
    function<bool(void)> bfs=[&]() {
        level=vector<int>(siz, -1);
        level[src]=0;
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int now=q.front();
            q.pop();

            for (auto nxt:edge[now]) {
                if (level[nxt]==-1 && capacity[now][nxt]-flow[now][nxt]>0) {
                    level[nxt]=level[now]+1;
                    q.push(nxt);
                }
            }
        }

        return (level[dst]!=-1);
    };

    //Sent new flow with using level graph
    vector<int> startSearch;
    function<int(int, int, int)> dfs=[&](int now, int end, int mxFlow) {
        if (now==dst) return mxFlow;

        for (int& i=startSearch[now]; i<(int)edge[now].size(); i++) {
            int nxt=edge[now][i];
            if (level[nxt]==level[now]+1 && capacity[now][nxt]-flow[now][nxt]>0) {
                int newFlow=dfs(nxt, end, min(mxFlow, capacity[now][nxt]-flow[now][nxt]));

                if (newFlow>0) {
                    flow[now][nxt]+=newFlow;
                    flow[nxt][now]-=newFlow;
                    return newFlow;
                }
            }
        }

        return 0;
    };

    int totalFlow=0;
    while (bfs()==true) {
        startSearch=vector<int>(siz, 0);
        while (int flow=dfs(src, dst, inf)) {
            totalFlow+=flow;
        }
    }
    cout << totalFlow << '\n';

    vector<bool> vis(n+2, false);
    vis[src]=true;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int now=q.front();
        q.pop();

        for (auto nxt:edge[now]) {
            if (!vis[nxt] && capacity[now][nxt]-flow[now][nxt]>0) {
                vis[nxt]=true;
                q.push(nxt);
            }
        }
    }

    vector<vector<int>> ans(2);
    for (int i=0; i<n; i++) {
        ans[1-vis[i]].push_back(i);
    }
    for (int i=0; i<2; i++) {
        for (auto j:ans[i]) cout << j+1 << ' ';
        cout << '\n';
    }

    return 0;
}
