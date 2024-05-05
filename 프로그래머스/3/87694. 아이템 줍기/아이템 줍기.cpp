#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> rec, int sx, int sy, int ex, int ey) {
    const int n=rec.size();
    set<pair<int, int>> point;
    for (int i=0; i<n; i++) {
        for (int j=rec[i][0]*2; j<=rec[i][2]*2; j++) {
            for (int k=rec[i][1]*2; k<=rec[i][3]*2; k++) {
                point.insert({j, k});
            }
        }
    }

    vector<int> dx({0, 0, 1, -1, 1, 1, -1, -1});
    vector<int> dy({1, -1, 0, 0, -1, 1, 1, -1});

    queue<pair<int, int>> q;
    q.push({sx*2, sy*2});
    map<pair<int, int>, int> vis;
    vis[{sx*2, sy*2}]=0;
    while (!q.empty()) {
        auto [x, y]=q.front();
        q.pop();

        if (ex*2==x && ey*2==y) {
            return vis[{ex*2, ey*2}]/2;
        }

        for (int d=0; d<4; d++) {
            int nx=x+dx[d];
            int ny=y+dy[d];
            if (point.find({nx, ny})==point.end()) continue;
            if (vis.find({nx, ny})!=vis.end()) continue;

            int cnt=0;
            for (int pd=0; pd<8; pd++) {
                int pnx=nx+dx[pd];
                int pny=ny+dy[pd];
                if (point.find({pnx, pny})!=point.end()) cnt++;
            }
            if (cnt==8) continue;

            vis[{nx, ny}]=vis[{x, y}]+1;
            q.push({nx, ny});
        }
    }
    return -1;
}