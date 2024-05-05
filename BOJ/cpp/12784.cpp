#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
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
        int root=0;
        vector<bool> vis(n, false);
        //return smallest usage of dynamite to remove all leaf node in tree with root now
        function<int(int)> sol=[&](int now) {
            vis[now]=true;
            int ret=0;
            for (auto [nxt, d]:edge[now]) {
                if (vis[nxt]) continue;
                if ((int)edge[nxt].size()==1) {
                    ret+=d;
                }
                else ret+=min(d, sol(nxt));
            }
            return ret;
        };

        cout << sol(0) << '\n';
    }

    return 0;
}
