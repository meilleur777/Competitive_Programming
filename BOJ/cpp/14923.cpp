#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    intp s, e;
    cin >> n >> m >> s.first >> s.second >> e.first >> e.second;
    s.first--, s.second--, e.first--, e.second--;
    vector<vector<int>> a(n, vector<int>(m));
    rep(i, n) rep(j, m) cin >> a[i][j];

    vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
    queue<pair<intp, int>> q;
    q.push({s, 0});
    vector<vector<vector<int>>> vis(n, vector<vector<int>>(m, vector<int>(2, -1)));
    vis[s.first][s.second][0]=0;
    while (!q.empty()) {
        int y=q.front().first.first;
        int x=q.front().first.second;
        int use=q.front().second;
        q.pop();
        rep(d, 4) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=n || ny<0 || nx>=m || nx<0) continue;
            if (vis[ny][nx][use]!=-1) continue;
            if (use) {
                if (a[ny][nx]) continue;
                vis[ny][nx][use]=vis[y][x][use]+1;
                q.push({{ny, nx}, use});
            }
            else {
                if (a[ny][nx]) {
                    vis[ny][nx][1]=vis[y][x][0]+1;
                    q.push({{ny, nx}, 1});
                }
                else {
                    vis[ny][nx][use]=vis[y][x][use]+1;
                    q.push({{ny, nx}, 0});
                }
            }
        }
    }
    if (vis[e.first][e.second][1]==-1 && vis[e.first][e.second][0]==-1) {
        cout << -1;
    }
    else {
        cout << max(vis[e.first][e.second][1], vis[e.first][e.second][1]);
    }

    return 0;
}