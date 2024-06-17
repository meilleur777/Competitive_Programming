#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
vector<int> dy({0, 0, 1, -1});
vector<int> dx({1, -1, 0, 0});

void bfs(const vector<string>& brd, vector<vector<int>>& dist, int sy, int sx) {
    int n=brd.size();
    int m=brd.front().size();
    dist=vector<vector<int>>(n, vector<int>(m, inf));
    dist[sy][sx]=0;

    queue<pair<int, int>> q;
    q.push({sy, sx});
    while (!q.empty()) {
        int y=q.front().first;
        int x=q.front().second;
        q.pop();

        for (int d=0; d<4; d++) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=n || ny<0 || nx>=m || nx<0) continue;
            if (dist[ny][nx]!=inf) continue;
            if (brd[ny][nx]=='D') continue;

            dist[ny][nx]=dist[y][x]+1;
            q.push({ny, nx});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];

    int sy=-1, sx=-1;
    int hy=-1, hx=-1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]=='S') {
                sy=i;
                sx=j;
            }
            if (brd[i][j]=='H') {
                hy=i;
                hx=j;
            }
        }
    }

    vector<vector<int>> stof, htof;
    bfs(brd, stof, sy, sx);
    bfs(brd, htof, hy, hx);

    int ans=inf;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]!='F') continue;
            ans=min(ans, stof[i][j]+htof[i][j]);
        }
    }

    if (ans!=inf) cout << ans;
    else cout << -1;

    return 0;
}
