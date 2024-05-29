#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> dy({0, 0, -1, 1});
    vector<int> dx({1, -1, 0, 0});
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];

    int sy, sx;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]=='0') {
                sy=i;
                sx=j;
            }
        }
    }

    const int inf=0x3f3f3f3f;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>((1<<6), inf)));
    queue<vector<int>> q;

    dist[sy][sx][0]=0;
    q.push({sy, sx, 0});
    while (!q.empty()) {
        int y=q.front()[0];
        int x=q.front()[1];
        int state=q.front()[2];
        q.pop();

        if (brd[y][x]=='1') {
            cout << dist[y][x][state];
            return 0;
        }

        for (int d=0; d<4; d++) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=n || ny<0 || nx>=m || nx<0) continue;
            if (brd[ny][nx]=='#') continue;

            function<void(int, int, int)> go=[&](int ny, int nx, int newState) {
                if (dist[ny][nx][newState]==inf) {
                    dist[ny][nx][newState]=dist[y][x][state]+1;
                    q.push({ny, nx, newState});
                }
            };

            if ((isupper(brd[ny][nx]) && (state&(1<<(brd[ny][nx]-'A')))) ||
                brd[ny][nx]=='1' || brd[ny][nx]=='0' || brd[ny][nx]=='.') {
                go(ny, nx, state);
            }
            else if (islower(brd[ny][nx])) {
                int newState=state|(1<<(brd[ny][nx]-'a'));
                go(ny, nx, newState);
            }
        }
    }

    cout << -1;

    return 0;
}
