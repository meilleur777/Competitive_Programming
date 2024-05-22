#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    const int inf=0x3f3f3f3f;
    vector<int> dy({1, 0, -1, 0});
    vector<int> dx({0, -1, 0, 1});
    
    int h, w;
    cin >> w >> h;
    vector<string> brd(h);
    for (int i=0; i<h; i++) cin >> brd[i];

    pair<int, int> src={-1, -1}, dst={-1, -1};
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (brd[i][j]=='C') {
                if (src==make_pair(-1, -1)) {
                    src={i, j};
                }
                else {
                    dst={i, j};
                }
            }
        }
    }

    //0-1 BFS
    deque<vector<int>> dq;
    vector<vector<vector<int>>> dist(4, vector<vector<int>>(h, vector<int>(w, inf)));
    for (int i=0; i<4; i++) dist[i][src.first][src.second]=0;
    dq.push_back({src.first, src.second, 0});
    while (!dq.empty()) {
        int y=dq.front()[0];
        int x=dq.front()[1];
        int pd=dq.front()[2];
        dq.pop_front();

        for (int d=0; d<4; d++) {
            if (src!=make_pair(y, x) && d==(pd+2)%4) continue;
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=h || ny<0 || nx>=w || nx<0) continue;
            if (brd[ny][nx]=='*') continue;

            int cost=0;
            if (src!=make_pair(y, x) && d!=pd) cost=1;

            if (dist[d][ny][nx]>dist[pd][y][x]+cost) {
                dist[d][ny][nx]=dist[pd][y][x]+cost;

                if (cost==0) dq.push_front({ny, nx, d});
                else dq.push_back({ny, nx, d});
            }
        }
    }

    int ans=inf;
    for (int i=0; i<4; i++) ans=min(ans, dist[i][dst.first][dst.second]);
    cout << ans;

    return 0;
}
