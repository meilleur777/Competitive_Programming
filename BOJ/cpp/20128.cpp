#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edge(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    const long long inf=0x7f7f7f7f7f7f7f7f;
    vector<vector<long long>> dist(2, vector<long long>(n, inf));
    auto cpr=[&](const pair<int, long long>& p, const pair<int, long long>& q) {
        return p.second>q.second;
    };
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cpr)> pq(cpr);
    int src=0;
    dist[0][src]=0;
    pq.push({src, dist[0][src]});
    while (!pq.empty()) {
        int now=pq.top().first;
        long long used=pq.top().second;
        pq.pop();

        if (dist[used%2][now]<used) continue;

        for (auto [nxt, weight]:edge[now]) {
            if (dist[(used+weight)%2][nxt]>dist[used%2][now]+weight) {
                dist[(used+weight)%2][nxt]=dist[used%2][now]+weight;
                pq.push({nxt, dist[(used+weight)%2][nxt]});
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=1; j>=0; j--) {
            long long ans=dist[j][i];
            if (ans>=inf) cout << -1 << ' ';
            else cout << ans << ' ';
        }
        cout << '\n';
    }

    return 0;
}
