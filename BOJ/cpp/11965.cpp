#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> brd(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> brd[i][j];
        }
    }

    const int inf=0x3f3f3f3f;
    vector<int> dy({1, 0, 0, -1});
    vector<int> dx({0, 1, -1, 0});
    vector<vector<vector<vector<int>>>> dist(2,
        vector<vector<vector<int>>>(4,
            vector<vector<int>>(n,
                vector<int>(m, inf))));

    queue<vector<int>> q;
    dist[0][0][0][0]=dist[0][1][0][0]=0;
    q.push({0, 0, 0, 0});
    q.push({0, 1, 0, 0});

    while (!q.empty()) {
        bool smell=q.front()[0];
        int pastDir=q.front()[1];
        int y=q.front()[2];
        int x=q.front()[3];
        q.pop();

        function<void(int, int, int, int)> go=[&](int a, int b, int c, int d) {
            if (dist[a][b][c][d]==inf) {
                dist[a][b][c][d]=dist[smell][pastDir][y][x]+1;
                q.push({a, b, c, d});
            }
        };

        if (brd[y][x]==4) {
            int ny=y+dy[pastDir];
            int nx=x+dx[pastDir];
            if (ny>=n || ny<0 || nx>=m || nx<0 || brd[ny][nx]==0 || brd[ny][nx]==3) {
                for (int d=0; d<4; d++) {
                int ny=y+dy[d];
                int nx=x+dx[d];
                if (ny>=n || ny<0 || nx>=m || nx<0) continue;

                if (brd[ny][nx]==0) continue;
                else if (brd[ny][nx]==1) {
                    go(smell, d, ny, nx);
                }
                else if (brd[ny][nx]==2) {
                    go(1, d, ny, nx);
                }
                else if (brd[ny][nx]==3) {
                    if (smell!=1) continue;

                    go(1, d, ny, nx);
                }
                else if (brd[ny][nx]==4) {
                    go(0, d, ny, nx);
                }
            }
            }
            else {
                if (brd[ny][nx]==1) {
                    go(smell, pastDir, ny, nx);
                }
                else if (brd[ny][nx]==2) {
                    go(1, pastDir, ny, nx);
                }
                else if (brd[ny][nx]==4) {
                    go(0, pastDir, ny, nx);
                }
            }
        }
        else {
            for (int d=0; d<4; d++) {
                int ny=y+dy[d];
                int nx=x+dx[d];
                if (ny>=n || ny<0 || nx>=m || nx<0) continue;

                if (brd[ny][nx]==0) continue;
                else if (brd[ny][nx]==1) {
                    go(smell, d, ny, nx);
                }
                else if (brd[ny][nx]==2) {
                    go(1, d, ny, nx);
                }
                else if (brd[ny][nx]==3) {
                    if (smell!=1) continue;

                    go(1, d, ny, nx);
                }
                else if (brd[ny][nx]==4) {
                    go(0, d, ny, nx);
                }
            }
        }
    }

    int ans=inf;
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
            ans=min(ans, dist[i][j][n-1][m-1]);
        }
    }
    if (ans>=inf) cout << -1;
    else cout << ans;

    return 0;
}
