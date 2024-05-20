#include <bits/stdc++.h>
using namespace std;

int capacity[51][51][51][51];
int flow[51][51][51][51];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const int inf=0x3f3f3f3f;
    vector<int> dy({0, 0, 1, -1});
    vector<int> dx({1, -1, 0, 0});
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> brd(n, vector<int>(m));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                cin >> brd[i][j];
            }
        }

        pair<int, int> src={n, 0}, dst={n, 1};
        vector<pair<int, int>> edge[51][51];

        int sum0=0, sum1=0;
        for (int i=0; i<n; i++) {
            for (int j=(i%2==1); j<m; j+=2) {
                capacity[src.first][src.second][i][j]=brd[i][j];
                capacity[i][j][src.first][src.second]=0;
                flow[src.first][src.second][i][j]=0;
                flow[i][j][src.first][src.second]=0;
                edge[src.first][src.second].push_back({i, j});
                edge[i][j].push_back(src);
                sum0+=brd[i][j];

                for (int d=0; d<4; d++) {
                    int ny=i+dy[d];
                    int nx=j+dx[d];
                    if (ny>=n || ny<0 || nx>=m || nx<0) continue;

                    capacity[i][j][ny][nx]=inf;
                    capacity[ny][nx][i][j]=0;
                    flow[i][j][ny][nx]=0;
                    flow[ny][nx][i][j]=0;
                    edge[i][j].push_back({ny, nx});
                    edge[ny][nx].push_back({i, j});
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=(i%2==0); j<m; j+=2) {
                capacity[i][j][dst.first][dst.second]=brd[i][j];
                capacity[dst.first][dst.second][i][j]=0;
                flow[i][j][dst.first][dst.second]=0;
                flow[dst.first][dst.second][i][j]=0;
                edge[i][j].push_back(dst);
                edge[dst.first][dst.second].push_back({i, j});
                sum1+=brd[i][j];
            }
        }

        //Edmonds-karp algorithm
        int totalFlow=0;
        while (true) {
            queue<pair<int, int>> q;
            q.push(src);
            pair<int, int> empty={-1, -1};
            vector<vector<pair<int, int>>> par(n+1, vector<pair<int, int>>(m, empty));

            while (!q.empty()) {
                auto [y, x]=q.front();
                q.pop();

                for (auto [ny, nx]:edge[y][x]) {
                    if (capacity[y][x][ny][nx]-flow[y][x][ny][nx]>0 && par[ny][nx]==empty) {
                        par[ny][nx]={y, x};
                        q.push({ny, nx});
                    }
                }
            }

            if (par[dst.first][dst.second]==empty) break;

            int mnFlow=inf;
            for (auto nxt=dst; nxt!=src; nxt=par[nxt.first][nxt.second]) {
                auto now=par[nxt.first][nxt.second];
                mnFlow=min(mnFlow, capacity[now.first][now.second][nxt.first][nxt.second]
                                   -flow[now.first][now.second][nxt.first][nxt.second]);
            }
            for (auto nxt=dst; nxt!=src; nxt=par[nxt.first][nxt.second]) {
                auto now=par[nxt.first][nxt.second];
                flow[now.first][now.second][nxt.first][nxt.second]+=mnFlow;
                flow[nxt.first][nxt.second][now.first][now.second]-=mnFlow;
            }
            totalFlow+=mnFlow;
        }
        cout << sum0+sum1-totalFlow << '\n';
    }

    return 0;
}
