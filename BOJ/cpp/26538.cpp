#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> dy({0, 0, 1, -1});
    vector<int> dx({1, -1, 0, 0});
    
    int t;
    cin >> t;
    while (t--) {
        int w, h, q;
        cin >> w >> h >> q;
        vector<string> brd(h, string(w, '.'));

        while (q--) {
            int r, c, p;
            cin >> r >> c >> p;
            brd[r][c]='x';

            vector<vector<bool>> vis(w, vector<bool>(h, false));
            queue<vector<int>> q;
            q.push({r, c, 0});
            vis[r][c]=true;
            while (!q.empty()) {
                int y=q.front()[0];
                int x=q.front()[1];
                int dis=q.front()[2];
                q.pop();

                if (dis>=p) continue;

                for (int d=0; d<4; d++) {
                    int ny=y+dy[d];
                    int nx=x+dx[d];
                    if (ny>=w || ny<0 || nx>=h || nx<0) continue;
                    if (brd[ny][nx]=='x') continue;
                    if (vis[ny][nx]) continue;
                    brd[ny][nx]='*';
                    vis[ny][nx]=true;
                    q.push({ny, nx, dis+1});
                }
            }
        }

        for (auto s:brd) cout << s << '\n';
        cout << '\n';
    }

    return 0;
}
