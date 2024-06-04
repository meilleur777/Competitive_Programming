#include <bits/stdc++.h>
using namespace std;

int find(int x, const vector<int>& par) {
    if (x==par[x]) return x;
    return find(par[x], par);
}

bool merge(int a, int b, vector<int>& par, vector<int>& rank) {
    int aa=find(a, par), bb=find(b, par);
    if (aa==bb) return false;

    if (rank[aa]<rank[bb]) swap(aa, bb);
    if (rank[aa]==rank[bb]) rank[aa]++;
    par[bb]=aa;

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k, l;
    cin >> n >> k >> l;
    vector<vector<int>> road(n);
    vector<vector<int>> rail(n);

    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    for (int i=0; i<l; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        rail[a].push_back(b);
        rail[b].push_back(a);
    }

    vector<int> par(n);
    vector<int> rank(n, 0);
    for (int i=0; i<n; i++) par[i]=i;

    for (int now=0; now<n; now++) {
        for (auto nxt:road[now]) {
            merge(now, nxt, par, rank);
        }
    }

    int num=0;
    map<pair<int, int>, int> cnt;
    vector<int> vis(n, -1);
    for (int i=0; i<n; i++) {
        if (vis[i]!=-1) continue;

        function<void(int)> dfs=[&](int now) {
            vis[now]=num;
            cnt[{find(now, par), vis[now]}]++;

            for (auto nxt:rail[now]) {
                if (vis[nxt]!=-1) continue;
                dfs(nxt);
            }
        };

        dfs(i);
        num++;
    }

    for (int i=0; i<n; i++) {
        cout << cnt[{find(i, par), vis[i]}] << ' ';
    }

    return 0;
}
