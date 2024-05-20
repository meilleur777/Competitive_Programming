#include <bits/stdc++.h>
using namespace std;

//Konig's Theorem
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> dy({0, 0, -1, -1, 1, 1});
    vector<int> dx({1, -1, 1, -1, 1, -1});
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> brd(n);
        for (int i=0; i<n; i++) cin >> brd[i];

        int seatNum=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (brd[i][j]=='.') seatNum++;
            }
        }

        vector<vector<int>> edge(n*m);
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j+=2) {
                if (brd[i][j]=='x') continue;

                for (int d=0; d<(int)dy.size(); d++) {
                    int ny=i+dy[d];
                    int nx=j+dx[d];
                    if (ny>=n || ny<0 || nx>=m || nx<0) continue;
                    if (brd[ny][nx]=='x') continue;

                    edge[i*m+j].push_back({ny*m+nx});
                }
            }
        }

        //Maximum Bipartite matching
        vector<bool> vis;
        vector<int> par(n*m, -1);
        function<bool(int)> dfs=[&](int now) {
            for (auto nxt:edge[now]) {
                if (vis[nxt]) continue;
                vis[nxt]=true;

                if (par[nxt]==-1 || dfs(par[nxt])) {
                    par[nxt]=now;
                    return true;
                }
            }

            return false;
        };

        int matchCnt=0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j+=2) {
                if (brd[i][j]=='x') continue;
                vis=vector<bool>(n*m, false);
                matchCnt+=dfs(i*m+j);
            }
        }

        cout << seatNum-matchCnt << '\n';
    }

    return 0;
}
