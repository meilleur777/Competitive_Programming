#include <bits/stdc++.h>
using namespace std;

const int inf=1e4+1;
vector<int> dy({0, 0, 1, -1});
vector<int> dx({1, -1, 0, 0});

//0-1 BFS
void bfs(pair<int, int> start, const vector<string>& brd, int n, int m, vector<vector<int>>& vis) {
    deque<pair<int, int>> dq;
    vis=vector<vector<int>>(n, vector<int>(m, inf));
    vis[start.first][start.second]=0;
    dq.push_back(start);

    while (!dq.empty()) {
        auto [y, x]=dq.front();
        dq.pop_front();

        for (int d=0; d<4; d++) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=n || ny<0 || nx>=m || nx<0) continue;

            if (brd[ny][nx]=='*') continue;

            int cost=brd[ny][nx]=='#';

            if (vis[ny][nx]>vis[y][x]+cost) {
                vis[ny][nx]=vis[y][x]+cost;
                if (cost==1) dq.push_back({ny, nx});
                else dq.push_front({ny, nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        vector<string> brd;
        brd.push_back(string(w+2, 'e'));
        for (int i=0; i<h; i++) {
            string s;
            cin >> s;
            brd.push_back('e'+s+'e');
        }
        brd.push_back(string(w+2, 'e'));

        //mob->0, 1 boundary->2
        vector<pair<int, int>> pos;
        for (int i=0; i<h+2; i++) {
            for (int j=0; j<w+2; j++) {
                if (brd[i][j]=='$') {
                    pos.push_back({i, j});
                }
            }
        }
        pos.push_back({0, 0});

        //vis[startPosition][y][x]
        vector<vector<vector<int>>> vis((int)pos.size());
        for (int i=0; i<(int)pos.size(); i++) {
            bfs(pos[i], brd, h+2, w+2, vis[i]);
        }

        int ans=inf;

        //mob0 and mob1 meet at {i, j}
        for (int i=1; i<=h; i++) {
            for (int j=1; j<=w; j++) {
                if (brd[i][j]=='*') continue;

                int mob0toHere=vis[0][i][j];
                int mob1toHere=vis[1][i][j];
                int meetCost=mob0toHere+mob1toHere;

                int escapeCost=vis[2][i][j];

                int totalCost=meetCost+escapeCost;
                if (brd[i][j]=='#') totalCost-=2;

                ans=min(ans, totalCost);
            }
        }

        //mom0 and mob1 escape seperately
        vector<int> mn(2, inf);
        for (int j=0; j<2; j++) {
            mn[j]=min(mn[j], vis[j][0][0]);
        }

        ans=min(ans, mn[0]+mn[1]);

        cout << ans << '\n';
    }

    return 0;
}
