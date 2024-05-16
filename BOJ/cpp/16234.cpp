#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<int>> brd(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> brd[i][j];
        }
    }

    vector<int> dy({0, 0, 1, -1});
    vector<int> dx({1, -1, 0, 0});

    int ans=0;
    while (true) {
        vector<vector<bool>> vis(n);

        //return sum of node value in component, cardinality of component
        function<pair<int, int>(int, int)> makeComponent=[&](int y, int x) {
            vis[y][x]=true;

            int sum=brd[y][x];
            int siz=1;
            for (int d=0; d<4; d++) {
                int ny=y+dy[d];
                int nx=x+dx[d];
                if (ny>=n || ny<0 || nx>=n || nx<0) continue;
                if (vis[ny][nx]) continue;

                int difference=abs(brd[y][x]-brd[ny][nx]);
                if (l<=difference && difference<=r) {
                    pair<int, int> res=makeComponent(ny, nx);
                    sum+=res.first;
                    siz+=res.second;
                }
            }

            return make_pair(sum, siz);
        };

        bool migrated=false;
        vector<vector<int>> cpybrd(n, vector<int>(n, 0));
        function<void(int, int, int)> migrate=[&](int y, int x, int population) {
            vis[y][x]=true;
            if (brd[y][x]!=population) migrated=true;
            cpybrd[y][x]=population;

            for (int d=0; d<4; d++) {
                int ny=y+dy[d];
                int nx=x+dx[d];
                if (ny>=n || ny<0 || nx>=n || nx<0) continue;
                if (vis[ny][nx]) continue;

                int difference=abs(brd[y][x]-brd[ny][nx]);
                if (l<=difference && difference<=r) {
                    migrate(ny, nx, population);
                }
            }
        };

        vis=vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (vis[i][j]) continue;

                pair<int, int> res=makeComponent(i, j);
                int population=res.first/res.second;
                cpybrd[i][j]=population;
            }
        }

        vis=vector<vector<bool>>(n, vector<bool>(n, false));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (vis[i][j]) continue;

                migrate(i, j, cpybrd[i][j]);
            }
        }

        if (migrated==false) break;

        brd=cpybrd;
        ans++;
    }

    cout << ans;

    return 0;
}
