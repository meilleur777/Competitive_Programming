#include <bits/stdc++.h>
using namespace std;

//Max-flow min-cut Theorem
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge(n);
    vector<vector<int>> flow(n, vector<int>(n, 0));
    vector<vector<int>> capacity(n, vector<int>(n, 0));
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
        capacity[a][b]=c;
        capacity[b][a]=c;
    }
    int src, dst;
    cin >> src >> dst;
    src--, dst--;

    int ans=0;

    //Edmonds-karp algorithm
    while (true) {
        queue<int> q;
        q.push(src);

        vector<int> par(n, -1);

        while (!q.empty()) {
            int now=q.front();
            q.pop();

            for (auto nxt:edge[now]) {
                if (capacity[now][nxt]-flow[now][nxt]>0 && par[nxt]==-1) {
                    q.push(nxt);
                    par[nxt]=now;
                }
            }
        }

        if (par[dst]==-1) break;

        int mn=0x3f3f3f3f;
        for (int now=dst; now!=src; now=par[now]) {
            mn=min(mn, capacity[par[now]][now]-flow[par[now]][now]);
        }
        for (int now=dst; now!=src; now=par[now]) {
            flow[par[now]][now]+=mn;
            flow[now][par[now]]-=mn;
        }

        ans+=mn;
    }

    cout << ans;

    return 0;
}
