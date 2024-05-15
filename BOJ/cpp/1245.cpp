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

    vector<int> dy({1, 1, 1, 0, 0, -1, -1, -1});
    vector<int> dx({1, 0, -1, 1, -1, 1, 0, -1});

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (vis[i][j]==true) continue;

            function<bool(int, int)> dfs=[&](int y, int x) {
                vis[y][x]=true;

                bool ret=true;

                for (int d=0; d<8; d++) {
                    int ny=y+dy[d];
                    int nx=x+dx[d];
                    if (ny>=n || ny<0 || nx>=m || nx<0) continue;

                    if (brd[ny][nx]==brd[y][x] && vis[ny][nx]==false) {
                        bool tmp=dfs(ny, nx);
                        if (tmp==false) ret=false;
                    }
                    else if (brd[ny][nx]>brd[y][x]) ret=false;
                }

                return ret;
            };

            ans+=dfs(i, j);
        }
    }

    cout << ans;

    return 0;
}
