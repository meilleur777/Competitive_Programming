#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> dz({0, 0, 0, 0, 1, -1});
    vector<int> dy({0, 0, 1, -1, 0, 0});
    vector<int> dx({1, -1, 0 ,0 ,0 ,0});
    
    while (1) {
        int l, r, c;
        cin >> l >> r >> c;
        if (!l && !r && !c) break;

        vector<vector<string>> v(l, vector<string>(r));
        for (int i=0; i<l; i++) {
            for (int j=0; j<r; j++) {
                cin >> v[i][j];
            }
        }

        tuple<int, int, int> s, e;
        for (int i=0; i<l; i++) {
            for (int j=0; j<r; j++) {
                for (int k=0; k<c; k++) {
                    if (v[i][j][k]=='S') s={i, j, k};
                    if (v[i][j][k]=='E') e={i, j, k};
                }
            }
        }

        vector<vector<vector<int>>> vis(l, vector<vector<int>>(r, vector<int>(c, INT_MAX)));
        vis[get<0>(s)][get<1>(s)][get<2>(s)]=0;
        queue<tuple<int, int, int>> q;
        q.push(s);
        while (!q.empty()) {
            auto [z, y, x]=q.front();
            q.pop();
            for (int i=0; i<6; i++) {
                int nz=z+dz[i];
                int ny=y+dy[i];
                int nx=x+dx[i];
                if (nz>=l || nz<0 || ny>=r || ny<0 || nx>=c || nx<0) continue;
                if (vis[nz][ny][nx]!=INT_MAX || v[nz][ny][nx]=='#') continue;
                q.push({nz, ny, nx});
                vis[nz][ny][nx]=vis[z][y][x]+1;
            }
        }

        if (vis[get<0>(e)][get<1>(e)][get<2>(e)]==INT_MAX) cout << "Trapped!\n";
        else cout << "Escaped in " << vis[get<0>(e)][get<1>(e)][get<2>(e)] << " minute(s).\n";
    }

    return 0;
}
