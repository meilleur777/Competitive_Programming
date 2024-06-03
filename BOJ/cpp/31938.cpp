#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edge(n);
    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    const long long inf=0x7f7f7f7f7f7f7f7f;
    vector<long long> dist(n, inf);
    dist[0]=0;
    auto cpr=[&](const pair<int, long long>& p, const pair<int, long long>& q) {
        return p.second>q.second;
    };
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cpr)> pq(cpr);
    pq.push({0, dist[0]});
    vector<pair<int, int>> par(n, {-1, -1});

    while (!pq.empty()) {
        int now=pq.top().first;
        long long used=pq.top().second;
        pq.pop();

        if (used>dist[now]) continue;

        for (auto [nxt, cost]:edge[now]) {
            if (dist[nxt]>dist[now]+cost) {
                dist[nxt]=dist[now]+cost;
                par[nxt]={now, cost};
                pq.push({nxt, dist[nxt]});
            }
            else if (dist[nxt]==dist[now]+cost) {
                if (par[nxt].second>cost) {
                    par[nxt]={now, cost};
                }
            }
        }
    }

    long long ans=0;
    for (int i=1; i<n; i++) {
        ans+=dist[par[i].first]*9/10+par[i].second;
    }
    cout << ans;

    return 0;
}
