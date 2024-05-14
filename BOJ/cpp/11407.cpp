#include <bits/stdc++.h>
using namespace std;

//Minimum-cost Maximum-flow
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    //src->0, dst->1, worker->2~n+1, job->n+2~n+m+1
    int siz=n+m+2;
    int src=0, dst=1;
    const int inf=0x3f3f3f3f;
    vector<vector<int>> edge(siz);
    vector<vector<int>> capacity(siz, vector<int>(siz, 0));
    vector<vector<int>> flow(siz, vector<int>(siz, 0));
    vector<vector<int>> cost(siz, vector<int>(siz, 0));
    for (int i=0; i<n; i++) {
        edge[src].push_back(2+i);
        edge[2+i].push_back(src);

        int a;
        cin >> a;
        capacity[src][2+i]=a;
    }
    for (int i=0; i<m; i++) {
        edge[n+2+i].push_back(dst);
        edge[dst].push_back(n+2+i);

        int b;
        cin >> b;
        capacity[n+2+i][dst]=b;
    }
    for (int store=0; store<m; store++) {
        for (int customer=0; customer<n; customer++) {
            edge[2+customer].push_back(n+2+store);
            edge[n+2+store].push_back(2+customer);
        }
    }
    for (int store=0; store<m; store++) {
        for (int customer=0; customer<n; customer++) {
            int c;
            cin >> c;
            capacity[2+customer][n+2+store]=c;
        }
    }
    for (int store=0; store<m; store++) {
        for (int customer=0; customer<n; customer++) {
            int d;
            cin >> d;
            cost[2+customer][n+2+store]=d;
            cost[n+2+store][2+customer]=-d;
        }
    }

    //Edmonds-karp algorithm
    //Shortest path faster algorithm
    int totalBook=0;
    int totalCost=0;
    while (true) {
        queue<int> q;
        q.push(src);
        vector<int> parent(siz, -1);
        vector<int> distance(siz, inf);
        vector<bool> inQueue(siz, false);
        inQueue[src]=true;
        distance[src]=0;

        while (!q.empty()) {
            int now=q.front();
            q.pop();
            inQueue[now]=false;

            for (auto nxt:edge[now]) {
                if (capacity[now][nxt]-flow[now][nxt]>0 && 
                    distance[nxt]>distance[now]+cost[now][nxt]) {
                    distance[nxt]=distance[now]+cost[now][nxt];
                    parent[nxt]=now;
                    if (!inQueue[nxt]) {
                        inQueue[nxt]=true;
                        q.push(nxt);
                    }
                }
            }
        }

        if (parent[dst]==-1) break;

        int newFlow=inf;
        for (int nxt=dst; nxt!=src; nxt=parent[nxt]) {
            int now=parent[nxt];
            newFlow=min(newFlow, capacity[now][nxt]-flow[now][nxt]);
        }
        for (int nxt=dst; nxt!=src; nxt=parent[nxt]) {
            int now=parent[nxt];
            totalCost+=cost[now][nxt]*newFlow;
            flow[now][nxt]+=newFlow;
            flow[nxt][now]-=newFlow;
        }
        totalBook+=newFlow;
    }
    
    cout << totalBook << '\n' << totalCost;

    return 0;
}
