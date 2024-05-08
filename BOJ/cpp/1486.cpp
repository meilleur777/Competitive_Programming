#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, t, D;
    cin >> n >> m >> t >> D;
    vector<string> brdStr(n);
    for (int i=0; i<n; i++) cin >> brdStr[i];

    vector<vector<int>> brd(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (isupper(brdStr[i][j])) {
                brd[i][j]=brdStr[i][j]-'A';
            }
            else {
                brd[i][j]=brdStr[i][j]-'a'+26;
            }
        }
    }

    vector<int> dy({0, 0, 1, -1});
    vector<int> dx({1, -1, 0, 0});

    vector<vector<vector<vector<int>>>> vis(n, vector<vector<vector<int>>>(m, 
                        vector<vector<int>>(n, vector<int>(m, -1))));
    for (int sy=0; sy<n; sy++) {
        for (int sx=0; sx<m; sx++) {

            vis[sy][sx][sy][sx]=0;

            auto cpr=[&](const pair<pair<int, int>, int>& p, const pair<pair<int, int>, int>& q) {
                return p.second>q.second;
            };
            priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, decltype(cpr)> pq(cpr);
            pq.push({{sy, sx}, vis[sy][sx][sy][sx]});

            while (!pq.empty()) {
                int y=pq.top().first.first;
                int x=pq.top().first.second;
                int c=pq.top().second;
                pq.pop();

                for (int d=0; d<4; d++) {
                    int ny=y+dy[d];
                    int nx=x+dx[d];
                    if (ny>=n || ny<0 || nx>=m || nx<0) continue;
                    if (abs(brd[ny][nx]-brd[y][x])>t) continue;

                    int cost;
                    if (brd[ny][nx]<=brd[y][x]) cost=1;
                    else cost=(brd[ny][nx]-brd[y][x])*(brd[ny][nx]-brd[y][x]);

                    if (vis[sy][sx][ny][nx]!=-1 && vis[sy][sx][ny][nx]<=vis[sy][sx][y][x]+cost) continue;
                    vis[sy][sx][ny][nx]=vis[sy][sx][y][x]+cost;
                    pq.push({{ny, nx}, vis[sy][sx][ny][nx]});
                }
            }
        }
    }

    int ans=brd[0][0];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m ;j++) {
            if (vis[0][0][i][j]==-1 || vis[i][j][0][0]==-1) continue;
            if (vis[0][0][i][j]+vis[i][j][0][0]>D) continue;
            ans=max(ans, brd[i][j]);
        }
    }
    cout << ans;

    return 0;
}
