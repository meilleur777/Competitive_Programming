#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> brd(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> brd[i][j];
        }
    }

    vector<int> dy({0, 1, 0, -1});
    vector<int> dx({1, 0, -1, 0});

    int cnt=2;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            function<void(int, int, int)> dfs=[&](int y, int x, int val) {
                if (brd[y][x]!=1) return;
                brd[y][x]=val;
                for (int k=0; k<4; k++) {
                    int ny=y+dy[k];
                    int nx=x+dx[k];
                    if (ny>=n || ny<0 || nx>=n || nx<0) continue;
                    dfs(ny, nx, val);
                }
            };
            dfs(i, j, cnt);
            cnt++;
        }
    }

    int ans=INT_MAX;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!brd[i][j]) continue;

            queue<pair<pair<int, int>, int>> q;
            vector<vector<int>> vis(n, vector<int>(n, INT_MAX));
            int sy=i, sx=j, sv=brd[i][j];
            vis[sy][sx]=0;
            q.push({{sy, sx}, 0});

            int res=INT_MAX;
            while (!q.empty()) {
                auto [d, c]=q.front();
                q.pop();
                auto [y, x]=d;
                for (int k=0; k<4; k++) {
                    int ny=y+dy[k];
                    int nx=x+dx[k];
                    if (ny>=n || ny<0 || nx>=n || nx<0) continue;
                    if (brd[ny][nx]==sv) continue;
                    if (vis[ny][nx]==INT_MAX) {
                        vis[ny][nx]=c+1;
                        q.push({{ny, nx}, c+1});
                        if (brd[ny][nx]) res=min(res, c);
                    }
                }
            }
            ans=min(ans, res);
        }
    }

    cout << ans;

    return 0;
}
