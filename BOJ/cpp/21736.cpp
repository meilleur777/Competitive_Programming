#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    rep(i, n) cin >> brd[i];

    vector<int> dy({0, 0, 1, -1});
    vector<int> dx({1, -1, 0, 0});
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]=='I') {
                int ans=0;
                vector<vector<bool>> vis(n, vector<bool>(m, false));
                function<void(int, int)> dfs=[&](int y, int x) {
                    if (vis[y][x]) return;
                    vis[y][x]=true;
                    ans+=brd[y][x]=='P';
                    rep(d, 4) {
                        int ny=y+dy[d];
                        int nx=x+dx[d];
                        if (ny>=n || ny<0 || nx>=m || nx<0) continue;
                        if (brd[ny][nx]=='X') continue;
                        dfs(ny, nx);
                    }
                };
                dfs(i, j);
                if (ans) cout << ans;
                else cout << "TT";
            }
        }
    }

    return 0;
}
