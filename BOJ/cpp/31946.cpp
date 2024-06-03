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
    int X;
    cin >> X;

    vector<int> dy({0, 0, 1, -1});
    vector<int> dx({1, -1, 0, 0});
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));

    q.push({0, 0});
    vis[0][0]=true;
    while (!q.empty()) {
        auto [y, x]=q.front();
        q.pop();

        if (y==n-1 && x==m-1) {
            cout << "ALIVE";
            return 0;
        }

        set<pair<int, int>> cand;
        queue<vector<int>> tmpQ;
        tmpQ.push({y, x, 0});
        while (!tmpQ.empty()) {
            int y=tmpQ.front()[0];
            int x=tmpQ.front()[1];
            int cnt=tmpQ.front()[2];
            tmpQ.pop();

            cand.insert({y, x});

            for (int d=0; d<4; d++) {
                int ny=y+dy[d];
                int nx=x+dx[d];
                if (ny>=n || ny<0 || nx>=m || nx<0) continue;
                if (vis[ny][nx]) continue;

                if (cnt<X) tmpQ.push({ny, nx, cnt+1});
            }
        }

        for (auto [y, x]:cand) {
            if (vis[y][x]) continue;
            if (brd[y][x]!=brd[0][0]) continue;

            vis[y][x]=true;
            q.push({y, x});
        }
    }
    
    cout << "DEAD";

    return 0;
}
