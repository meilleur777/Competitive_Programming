#include <bits/stdc++.h>
using namespace std;

//Depth First Search, Greedy
int solution(vector<vector<int>> brd, vector<vector<int>> tab) {

    vector<vector<int>> copy=brd;

    int n=tab.size();
    //  0
    //3   1
    //  2
    vector<int> dy({-1, 0, 1, 0});
    vector<int> dx({0, 1, 0, -1});

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    vector<pair<pair<int, int>, bool>> roots;
    vector<vector<vector<int>>> edge(n, vector<vector<int>>(n)); //tree using path(0~3) as edge
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (tab[i][j]==1 && vis[i][j]==false) {

                function<void(int, int)> dfs=[&](int y, int x) {
                    vis[y][x]=true;

                    for (int d=0; d<4; d++) {
                        int ny=y+dy[d];
                        int nx=x+dx[d];
                        if (ny>=n || ny<0 || nx>=n || nx<0) continue;
                        if (tab[ny][nx]==0 || vis[ny][nx]==true) continue;

                        edge[y][x].push_back(d);
                        dfs(ny, nx);
                    }
                };

                dfs(i, j);
                roots.push_back({{i, j}, false});
            }
        }
    }

    //offset := block rotated by offset(0~3)

    function<bool(int, int, int, int, int)> 
    placeBlock=[&](int y, int x, int offset, int ty, int tx) {
        if (y>=n || y<0 || x>=n || x<0) return false;
        if (brd[y][x]==1) return false;

        brd[y][x]=2;

        for (auto move:edge[ty][tx]) {
            int rotatedMove=(move+offset)%4;
            int ny=y+dy[rotatedMove];
            int nx=x+dx[rotatedMove];
            int nty=ty+dy[move];
            int ntx=tx+dx[move];

            if (placeBlock(ny, nx, offset, nty, ntx)==false) return false;
        }

        return true;
    };

    function<bool()> checkBlock=[&]() {

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (brd[i][j]!=2) continue;

                for (int d=0; d<4; d++) {
                    int ny=i+dy[d];
                    int nx=j+dx[d];
                    if (ny>=n || ny<0 || nx>=n || nx<0) continue;
                    if (brd[ny][nx]==0) return false;
                }
            }
        }

        return true;
    };
    
    function<void(int, int, int, int, int)> 
    eraseBlock=[&](int y, int x, int offset, int ty, int tx) {
        if (y>=n || y<0 || x>=n || x<0) return;
        if (brd[y][x]!=2) return;

        brd[y][x]=0;

        for (auto move:edge[ty][tx]) {
            int rotatedMove=(move+offset)%4;
            int ny=y+dy[rotatedMove];
            int nx=x+dx[rotatedMove];
            int nty=ty+dy[move];
            int ntx=tx+dx[move];

            eraseBlock(ny, nx, offset, nty, ntx);
        }
    };

    for (int y=0; y<n; y++) {
        for (int x=0; x<n; x++) {
            if (brd[y][x]!=0)  continue;

            bool flag=false;
            for (auto& root:roots) {
                if (flag==true || root.second==true) continue;

                for (int offset=0; offset<4; offset++) {
                    if (placeBlock(y, x, offset, root.first.first, root.first.second) && checkBlock()) {
                        root.second=true;
                        flag=true;
                        break;
                    }
                    else eraseBlock(y, x, offset, root.first.first, root.first.second);
                }
            }
        }
    }

    int ret=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (brd[i][j]!=copy[i][j]) {
                ret++;
            }
        }
    }

    return ret;
}
