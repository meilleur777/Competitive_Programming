#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const int inf=0x3f3f3f3f;
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edge(n);
        vector<int> nodeColor(n), coinColor(n);
        vector<vector<int>> weight(n, vector<int>(n, inf));
        for (int i=0; i<m; i++) {
            int a, b;
            cin >> a >> b;
            a--, b--;
            edge[a].push_back(b);
            edge[b].push_back(a);
            weight[a][b]=1;
            weight[b][a]=1;
        }
        for (int i=0; i<n; i++) cin >> nodeColor[i];
        for (int i=0; i<n; i++) cin >> coinColor[i];

        for (int i=0; i<n; i++) weight[i][i]=0;
        for (int p=0; p<n; p++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    weight[i][j]=min(weight[i][j], weight[i][p]+weight[p][j]);
                }
            }
        }

        int siz=n+2;
        int src=n, dst=n+1;
        vector<vector<int>> newEdge(siz);
        vector<vector<int>> flow(siz, vector<int>(siz, 0));
        vector<vector<int>> capacity(siz, vector<int>(siz, 0));
        vector<vector<int>> cost(siz, vector<int>(siz, inf));

        for (int i=0; i<n; i++) {
            if (nodeColor[i]==0 && coinColor[i]==1) {
                newEdge[src].push_back(i);
                newEdge[i].push_back(src);
                capacity[src][i]=1;
                cost[src][i]=0;
                cost[i][src]=0;

                for (int j=0; j<n; j++) {
                    if (nodeColor[j]==1 && coinColor[j]==0) {
                        newEdge[i].push_back(j);
                        newEdge[j].push_back(i);
                        capacity[i][j]=inf;
                        cost[i][j]=weight[i][j];
                        cost[j][i]=-weight[i][j];
                    }
                }
            }
            else if (nodeColor[i]==1 && coinColor[i]==0) {
                newEdge[i].push_back(dst);
                newEdge[dst].push_back(i);
                capacity[i][dst]=1;
                cost[i][dst]=0;
                cost[dst][i]=0;
            }
        }

        //Edmonds-karp algorithm
        //Shortest Path Faster algorithm
        int ans=0;
        while (true) {
            queue<int> q;
            vector<int> par(siz, -1);
            vector<int> dist(siz, inf);
            vector<bool> inQ(siz, false);
            q.push(src);
            dist[src]=0;
            inQ[src]=true;

            while (!q.empty()) {
                int now=q.front();
                q.pop();
                inQ[now]=false;

                for (auto nxt:newEdge[now]) {
                    if (dist[nxt]>dist[now]+cost[now][nxt] &&
                        capacity[now][nxt]-flow[now][nxt]>0) {
                        dist[nxt]=dist[now]+cost[now][nxt];
                        par[nxt]=now;
                        if (!inQ[nxt]) {
                            inQ[nxt]=true;
                            q.push(nxt);
                        }
                    }
                }
            }

            if (par[dst]==-1) break;

            int newFlow=inf;
            for (int nxt=dst; nxt!=src; nxt=par[nxt]) {
                int now=par[nxt];
                newFlow=min(newFlow, capacity[now][nxt]-flow[now][nxt]);
            }
            for (int nxt=dst; nxt!=src; nxt=par[nxt]) {
                int now=par[nxt];
                flow[now][nxt]+=newFlow;
                flow[nxt][now]-=newFlow;
                ans+=newFlow*cost[now][nxt];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
