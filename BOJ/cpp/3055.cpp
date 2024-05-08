#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int r, c;
    cin >> r >> c;
    vector<string> brd(r);
    for (int i=0; i<r; i++) {
        cin >> brd[i];
    }

    vector<int> dy({0, 0, -1, 1});
    vector<int> dx({1, -1, 0, 0});
    vector<vector<int>> vis(r, vector<int>(c, -1));
    queue<pair<int, int>> q;

    for (int i=0; i<r; i++) {
        for (int j=0; j<c; j++) {
            if (brd[i][j]=='S') {
                q.push({i, j});
                vis[i][j]=0;
            }
        }
    }


    while (!q.empty()) {

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (brd[i][j]!='*') continue;

                for (int d=0;d<4; d++) {
                    int ny=i+dy[d];
                    int nx=j+dx[d];
                    if (ny>=r || ny<0 || nx>=c || nx<0) continue;
                    if (brd[ny][nx]!='.') continue;
                    brd[ny][nx]='&';
                }
            }
        }

        for (int i=0; i<r; i++) {
            for (int j=0; j<c; j++) {
                if (brd[i][j]=='&') brd[i][j]='*';
            }
        }

        queue<pair<int, int>> nxtq;
        while (!q.empty()) {
            int y=q.front().first;
            int x=q.front().second;
            if (brd[y][x]=='D') {
                cout << vis[y][x];
                return 0;
            }
            q.pop();

            for (int d=0; d<4; d++) {
                int ny=y+dy[d];
                int nx=x+dx[d];
                if (ny>=r || ny<0 || nx>=c || nx<0) continue;
                if (brd[ny][nx]=='X' || brd[ny][nx]=='*') continue;
                if (vis[ny][nx]!=-1) continue;

                vis[ny][nx]=vis[y][x]+1;
                nxtq.push({ny, nx});
            }
        }

        q=nxtq;
    }

    cout << "KAKTUS";

    return 0;
}
