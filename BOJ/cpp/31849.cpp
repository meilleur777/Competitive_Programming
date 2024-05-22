#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> dy({0, 0, 1, -1});
    vector<int> dx({1, -1, 0, 0});
    
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<vector<int>> vis(n, vector<int>(m, -1));
    vector<vector<int>> price(n, vector<int>(m, -1));
    for (int i=0; i<r; i++) {
        int a, b, p;
        cin >> a >> b >> p;
        a--, b--;
        price[a][b]=p;
    }

    queue<pair<int, int>> q;
    for (int i=0; i<c; i++) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        q.push({c, d});
        vis[c][d]=0;
    }

    while (!q.empty()) {
        auto [y, x]=q.front();
        q.pop();

        for (int d=0; d<4; d++) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=n || ny<0 || nx>=m || nx<0) continue;
            if (vis[ny][nx]!=-1) continue;

            vis[ny][nx]=vis[y][x]+1;
            q.push({ny, nx});
        }
    }

    int ans=INT_MAX;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (price[i][j]!=-1) {
                ans=min(ans, price[i][j]*vis[i][j]);
            }
        }
    }
    cout << ans;

    return 0;
}
