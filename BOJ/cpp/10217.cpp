#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pint;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pint>> edge(n);
    while (k--) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;    
        u--, v--;
        edge[u].push_back({v, {c, d}});
    }   

    for (int i=0; i<n; i++) {
        sort(edge[i].begin(), edge[i].end(), [](const pint& p, const pint& q) -> bool {
            if (p.second.second==q.second.second) return p.second.first<q.second.first;
            return p.second.second<q.second.second;
        });
    }

    const int inf=0x7f7f7f7f;
    vector<vector<int>> cache(n, vector<int>(m+1, inf)); //cache[node][cost]=minimum time

    auto cpr=[&](const pint& p, const pint& q) {
        return p.second.second>q.second.second;
    };
    priority_queue<pint, vector<pint>, decltype(cpr)> pq(cpr); //node, cost, time
    pq.push({0, {0, 0}});
    cache[0][0]=0;

    while (!pq.empty()) {
        int nowNode=pq.top().first;
        int nowCost=pq.top().second.first;
        int nowTime=pq.top().second.second;
        pq.pop();

        if (cache[nowNode][nowCost]<nowTime) continue;

        for (auto nxt:edge[nowNode]) { 
            auto nxtNode=nxt.first;
            auto [cost, time]=nxt.second;
            if (cost==-1) continue;

            if (nowCost+cost>m) continue;

            if (cache[nxtNode][nowCost+cost]>nowTime+time) {
                cache[nxtNode][nowCost+cost]=nowTime+time;
                pq.push({nxtNode, {nowCost+cost, nowTime+time}});

                for (int i=nowCost+cost+1; i<=m; i++) {
                    if (cache[nxtNode][i]<=nowTime+time) break;
                    cache[nxtNode][i]=nowTime+time;
                }
            }
        }
    }

    int ans=inf;
    for (int cost=0; cost<=m; cost++) {
        ans=min(ans, cache[n-1][cost]);
    }
    if (ans>=inf) cout << "Poor KCM";
    else cout << ans;

    return 0;
}
