#include <bits/stdc++.h>
using namespace std;

int height(char c) {
    if (c=='.' || c=='P' || c=='B') return 0;
    if (c=='1') return 1;
    return 2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];
    int sy, sx;
    cin >> sy >> sx;
    sy--, sx--;

    string rampStr="NESW";
    vector<int> dy({-1, 0, 1, 0});
    vector<int> dx({0, 1, 0, -1});

    int compNum=0;
    vector<vector<int>> comp(n, vector<int>(m, -1));
    function<void(int, int)> makeComp=[&](int y, int x) {
        comp[y][x]=compNum;

        for (int d=0; d<4; d++) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=n || ny<0 || nx>=m || nx<0) continue;
            if (height(brd[y][x])!=height(brd[ny][nx])) continue;
            if (comp[ny][nx]!=-1) continue;

            makeComp(ny, nx);
        }
    };
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (comp[i][j]!=-1) continue;
            if (height(brd[i][j])>=2) continue;
            makeComp(i, j);
            compNum++;
        }
    }

    vector<vector<vector<int>>> adjRamp(compNum);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]!='?') continue;

            for (int d=0; d<4; d++) {
                int ny=i+dy[d];
                int nx=j+dx[d];
                if (ny>=n || ny<0 || nx>=m || nx<0) continue;

                if (height(brd[ny][nx])<=1) {
                    adjRamp[comp[ny][nx]].push_back({ny, nx, (d+2)%4});
                }
            }   
        }
    }

    int Pcomp=-1, Bcomp=-1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]=='P') Pcomp=comp[i][j];
            if (brd[i][j]=='B') Bcomp=comp[i][j];
        }
    }

    vector<bool> vis(compNum, false);
    function<void(int)> sol=[&](int nowComp) {
        if (nowComp==Pcomp || nowComp==Bcomp) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) {
                    if (brd[i][j]=='?') cout << 'N';
                    else cout << brd[i][j];
                }
                cout << '\n';
            }
            exit(0);
        }

        vis[nowComp]=true;

        for (auto edge:adjRamp[nowComp]) {
            int y=edge[0];
            int x=edge[1];
            int d=edge[2];
            int ny=y+dy[d];
            int nx=x+dx[d];
            int nny=ny+dy[d];
            int nnx=nx+dx[d];

            if (brd[ny][nx]!='?') continue;
            if (nny>=n || nny<0 || nnx>=m || nnx<0) continue;
            if (height(brd[nny][nnx])>=2) continue;
            if (height(brd[nny][nnx])==height(brd[y][x])) continue;
            if (comp[nny][nnx]==comp[y][x]) continue;
            if (comp[nny][nnx]==-1) continue;
            if (vis[comp[nny][nnx]]==true) continue;

            if (height(brd[y][x])==1) d=(d+2)%4;

            brd[ny][nx]=rampStr[d];
            sol(comp[nny][nnx]);
            brd[ny][nx]='?';
        }

        vis[nowComp]=false;
    };

    sol(comp[sy][sx]);
    cout << -1;

    return 0;
}
