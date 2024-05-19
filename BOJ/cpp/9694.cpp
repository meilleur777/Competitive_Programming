#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);   
    
    const int inf=0x3f3f3f3f;
    int t;
    cin >> t;
    for (int caseNum=1; caseNum<=t; caseNum++) {
        int n, m;
        cin >> n >> m;
        vector<vector<pair<int, int>>> edge(m);
        for (int i=0; i<n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            edge[a].push_back({b, c});
            edge[b].push_back({a, c});
        }

        queue<int> q;
        vector<int> dist(m, inf);
        vector<bool> inQ(m, false);
        vector<int> par(m, -1);
        q.push(0);
        inQ[0]=true;
        dist[0]=0;
        while (!q.empty()) {
            int now=q.front();
            q.pop();
            inQ[now]=false;

            for (auto [nxt, cost]:edge[now]) {
                if (dist[nxt]>dist[now]+cost) {
                    dist[nxt]=dist[now]+cost;
                    par[nxt]=now;
                    if (inQ[nxt]==false) {
                        inQ[nxt]=true;
                        q.push(nxt);
                    }
                }
            }
        }

        cout << "Case #" << caseNum << ": ";
        if (par[m-1]!=-1) {
            vector<int> ans;
            for (int nxt=m-1; nxt!=0; nxt=par[nxt]) {
                ans.push_back(nxt);
            }
            ans.push_back(0);
            reverse(ans.begin(), ans.end());
            for (auto i:ans) cout << i << ' ';
            cout << '\n';
        }
        else cout << "-1\n";
    }

    return 0;
}
