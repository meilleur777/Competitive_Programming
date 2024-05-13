#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, p;
    cin >> n >> p;
    vector<vector<int>> edge(n);
    vector<vector<int>> flow(n, vector<int>(n, 0));
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    while (p--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
        capacity[a][b]=1;
    }

    int ans=0;
    int src=0, dst=1;
    const int inf=0x3f3f3f3f;

    //Edmonds-Karp algorithm
    while (true) {
        queue<int> q;
        q.push(src);

        vector<int> parent(n, -1);

        while (!q.empty()) {
            int now=q.front();
            q.pop();

            for (auto nxt:edge[now]) {
                if (capacity[now][nxt]-flow[now][nxt]>0 && parent[nxt]==-1) {
                    q.push(nxt);
                    parent[nxt]=now;
                    if (nxt==dst) break;
                }
            }
        }

        if (parent[dst]==-1) break;

        int mnFlow=inf;
        for (int now=dst; now!=src; now=parent[now]) {
            mnFlow=min(mnFlow, capacity[parent[now]][now]-flow[parent[now]][now]);
        }
        for (int now=dst; now!=src; now=parent[now]) {
            flow[parent[now]][now]+=mnFlow;
            flow[now][parent[now]]-=mnFlow;
        }

        ans+=mnFlow;
    }

    cout << ans;

    return 0;
}
