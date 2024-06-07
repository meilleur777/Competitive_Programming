#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    vector<vector<pair<int, int>>> edge(1e4+1);
    int a, b, c;
    while (cin >> a >> b >> c) {
        a--, b--;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }

    vector<int> dist;
    function<void(int)> tree=[&](int now) {
        for (auto [nxt, cost]:edge[now]) {
            if (dist[nxt]!=-1) continue;
            dist[nxt]=dist[now]+cost;
            tree(nxt);
        }
    };

    dist=vector<int>(1e4+1, -1);
    dist[0]=0;
    tree(0);

    int ind=max_element(dist.begin(), dist.end())-dist.begin();

    dist=vector<int>(1e4+1, -1);
    dist[ind]=0;
    tree(ind);

    cout << *max_element(dist.begin(), dist.end());

    return 0;
}
