#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edge(n);
    for (int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    int x, z;
    cin >> x >> z;
    x--, z--;

    const long long linf=0x3f3f3f3f3f3f3f3f;

    auto cpr=[&](const pair<int, long long>& p, const pair<int, long long>& q) {
        return p.second>q.second;
    };
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cpr)> pq(cpr);

    vector<long long> visx(n, linf);
    visx[x]=0;
    pq.push({x, visx[x]});
    while (!pq.empty()) {
        int now=pq.top().first;
        long long cost=pq.top().second;
        pq.pop();

        if (visx[now]<cost) continue;

        for (auto nxt:edge[now]) {
            if (visx[nxt.first]>cost+nxt.second) {
                visx[nxt.first]=cost+nxt.second;
                pq.push({nxt.first, visx[nxt.first]});
            }
        }
    }

    vector<long long> visz(n, linf);
    visz[z]=0;
    pq.push({z, visz[z]});

    while (!pq.empty()) {
        int now=pq.top().first;
        long long cost=pq.top().second;
        pq.pop();

        if (visz[now]<cost) continue;

        for (auto nxt:edge[now]) {
            if (visz[nxt.first]>cost+nxt.second) {
                visz[nxt.first]=cost+nxt.second;
                pq.push({nxt.first, visz[nxt.first]});
            }
        }
    }

    int p;
    cin >> p;
    long long ans=linf;
    while (p--) {
        int y;
        cin >> y;
        y--;
        ans=min(ans, visx[y]+visz[y]);
    }
    if (ans==linf) cout << -1;
    else cout << ans;

    return 0;
}
