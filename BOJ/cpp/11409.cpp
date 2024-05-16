#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    //src->0, dst->1, worker->2~n+1, job->n+2~n+m+1
    int siz=n+m+2;
    int src=0, dst=1;
    vector<vector<int>> edge(siz);
    vector<vector<int>> flow(siz, vector<int>(siz, 0));
    vector<vector<int>> capacity(siz, vector<int>(siz, 0));
    vector<vector<int>> weight(siz, vector<int>(siz, 0));

    for (int i=0; i<n; i++) {
        edge[src].push_back(2+i);
        edge[2+i].push_back(src);
        capacity[src][2+i]=1;
    }
    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        while (num--) {
            int jobNum, wage;
            cin >> jobNum >> wage;
            jobNum--;
            edge[2+i].push_back(n+2+jobNum);
            edge[n+2+jobNum].push_back(2+i);
            capacity[2+i][n+2+jobNum]=1;
            weight[2+i][n+2+jobNum]=-wage;
            weight[n+2+jobNum][2+i]=wage;
        }
    }
    for (int i=0; i<m; i++) {
        edge[n+2+i].push_back(dst);
        edge[dst].push_back(n+2+i);
        capacity[n+2+i][dst]=1;
    }

    const int inf=0x3f3f3f3f;

    //Edmonds-karp algorithm
    //Shortest Path Faster algorithm
    int totalFlow=0;
    int totalWeight=0;

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

            for (auto nxt:edge[now]) {
                if (dist[nxt]>dist[now]+weight[now][nxt] && capacity[now][nxt]-flow[now][nxt]>0){
                    dist[nxt]=dist[now]+weight[now][nxt];
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
            totalWeight+=weight[now][nxt]*newFlow;
        }

        totalFlow+=newFlow;
    }

    totalWeight=-totalWeight;
    cout << totalFlow << '\n' << totalWeight; 

    return 0;
}
