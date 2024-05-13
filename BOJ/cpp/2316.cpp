#include <bits/stdc++.h>
using namespace std;

//Network Flow
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, p;
    cin >> n >> p;

    //nodeIn -> node*2, nodeOut -> node*2+1
    int srcIn=0, srcOut=1, dstIn=2, dstOut=3;
    vector<vector<int>> edge(n*2);
    vector<vector<int>> capacity(n*2, vector<int>(n*2, 0));
    vector<vector<int>> flow(n*2, vector<int>(n*2, 0));

    const int inf=0x3f3f3f3f;
    //For each nodeIn to nodeOut, capacity is 1    
    for (int i=0; i<n; i++) {
        edge[i*2].push_back(i*2+1);
        edge[i*2+1].push_back(i*2);
        capacity[i*2][i*2+1]=1;
    }
    while (p--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a*2+1].push_back(b*2);
        edge[b*2].push_back(a*2+1);
        edge[b*2+1].push_back(a*2);
        edge[a*2].push_back(b*2+1);
        capacity[a*2+1][b*2]=inf;
        capacity[b*2+1][a*2]=inf;
    }

    long long ans=0;

    //Edmonds-Karp algorithm
    while (true) {
        queue<int> q;
        q.push(srcOut);

        vector<int> parent(2*n, -1);
        parent[srcOut]=srcOut;

        while (!q.empty()) {
            int now=q.front();
            q.pop();

            for (auto nxt:edge[now]) {
                if (capacity[now][nxt]-flow[now][nxt]>0 && parent[nxt]==-1) {
                    parent[nxt]=now;
                    q.push(nxt);
                    if (nxt==dstIn) break;
                }
            }
        }

        if (parent[dstIn]==-1) break;

        int mn=inf;
        for (int now=dstIn; now!=srcOut; now=parent[now]) {
            mn=min(mn, capacity[parent[now]][now]-flow[parent[now]][now]);
        }
        for (int now=dstIn; now!=srcOut; now=parent[now]) {
            flow[parent[now]][now]+=mn;
            flow[now][parent[now]]-=mn;
        }

        ans+=mn;
    }

    cout << ans;

    return 0;
}
