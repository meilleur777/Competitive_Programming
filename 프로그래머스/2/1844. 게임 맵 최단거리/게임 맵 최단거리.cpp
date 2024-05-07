#include <bits/stdc++.h>
using namespace std;

//Breath First Search
int solution(vector<vector<int>> brd) {
    
    int n=brd.size();
    int m=brd.front().size();
    vector<int> dy({0, 0, -1, 1});
    vector<int> dx({1, -1, 0, 0});

    queue<pair<int, int>> q;
    q.push({0, 0});
    vector<vector<int>> vis(n, vector<int>(m, -1));
    vis[0][0]=1;
    while (!q.empty()) {
        auto [y, x]=q.front();
        q.pop();
        for (int d=0; d<4; d++) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=n || ny<0 || nx>=m || nx<0) continue;
            if (brd[ny][nx]==0 || vis[ny][nx]!=-1) continue;
            q.push({ny, nx});
            vis[ny][nx]=vis[y][x]+1;
        }
    }

    return vis[n-1][m-1];
}