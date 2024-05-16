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
    int k;
    cin >> k;
    map<int, int> mp;
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        a--;
        mp[a]=i;
    }

    int newSize=k+2;
    const long long linf=0x3f3f3f3f3f3f3f3f;

    //dijkstra x->0, z->1, p->2~k+1
    vector<vector<long long>> newEdge(newSize, vector<long long>(newSize, linf));

    auto cpr=[&](const pair<int, long long>& p, const pair<int, long long>& q) {
        return p.second>q.second;
    };
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, decltype(cpr)> pq(cpr);

    auto dijkstra=[&](int start, vector<long long>& res) {
        res=vector<long long>(n, linf);
        res[start]=0;
        pq.push({start, res[start]});

        while (!pq.empty()) {
            int now=pq.top().first;
            long long cost=pq.top().second;
            pq.pop();

            if (cost>res[now]) continue;

            for (auto nxt:edge[now]) {
                if (res[nxt.first]<=nxt.second+cost) continue;
                res[nxt.first]=nxt.second+cost;
                pq.push({nxt.first, res[nxt.first]});
            }
        }
    };

    int src=0, dst=1;
    for (int i=0; i<newSize; i++) {
        newEdge[i][i]=0;
    }
    vector<long long> res;
    dijkstra(x, res);
    newEdge[src][dst]=res[z];
    for (auto [p, q]:mp) {
        newEdge[src][q+2]=res[p];
    }
    dijkstra(z, res);
    newEdge[dst][src]=res[x];
    for (auto [p, q]:mp) {
        newEdge[dst][q+2]=res[p];
    }
    for (auto [p, q]:mp) {
        dijkstra(p, res);

        newEdge[q+2][src]=res[x];
        newEdge[q+2][dst]=res[z];
        for (auto [pp, qq]:mp) {
            newEdge[q+2][qq+2]=res[pp];
        }
    }

    vector<vector<long long>> cache(newSize, vector<long long>((1<<k), -1));
    function<long long(int, int)> dp=[&](int now, int state) {
        if (state==((1<<k)-1)) {
            return newEdge[now][dst];
        }

        long long& ret=cache[now][state];
        if (ret!=-1) return ret;

        ret=linf;
        for (int nxt=2; nxt<newSize; nxt++) { 
            if (state&(1<<(nxt-2))) continue;
            if (newEdge[now][nxt]>=linf) continue;
            ret=min(ret, newEdge[now][nxt]+dp(nxt, (state|(1<<(nxt-2)))));
        }

        return ret;
    };

    long long ans=dp(src, 0);
    if (ans>=linf) cout << -1;
    else cout << ans;

    return 0;
}
