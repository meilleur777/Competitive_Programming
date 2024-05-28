#include <bits/stdc++.h>
using namespace std;

bool isIn(int n, int m, int y, int x) {
    return (0<=y && y<n && 0<=x && x<m);
}

char getRoom(const vector<string>& brd, int state, int y, int x) {
    if (brd[y][x]=='A' || brd[y][x]=='B') return brd[y][x];

    string roomStr="CD";
    int tmp=(!!(state&(1<<y)))+(!!(state&(1<<((int)brd.size()+x))));
    return roomStr[(roomStr.find(brd[y][x])+tmp)%2];
}

bool chk(const char now, const char nxt, const int dir) {
    if (now=='B' || nxt=='B') return false;

    if (now=='A') {
        if (nxt=='A') return true;
        if (nxt=='C' && dir>=2) return true;
        if (nxt=='D' && dir<=1) return true;
    }
    if (now=='C') {
        if (dir<=1) return false;
        if (nxt=='A') return true;
        return now==nxt;
    }
    if (now=='D') {
        if (dir>=2) return false;
        if (nxt=='A') return true;
        return now==nxt;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];

    const int bitSize=n+m;
    const int inf=0x7f7f7f7f;
    const vector<int> dy({0, 0, 1, -1});
    const vector<int> dx({1, -1, 0, 0});

    //state -> col 0~n-1, row n~n+m-1
    queue<vector<int>> q; //y, x, state
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>((1<<bitSize), -1)));

    dist[0][0][0]=0;
    q.push({0, 0, 0});
    while (!q.empty()) {
        int y=q.front()[0];
        int x=q.front()[1];
        int state=q.front()[2];
        q.pop();

        if (y==n-1 && x==m-1) {
            cout << dist[n-1][m-1][state];
            return 0;
        }
        char nowRoom=getRoom(brd, state, y, x);

        //Not Press button
        for (int d=0; d<4; d++) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (!isIn(n, m, ny, nx)) continue;

            char nxtRoom=getRoom(brd, state, ny, nx);

            if (chk(nowRoom, nxtRoom, d)) {
                if (dist[ny][nx][state]==-1) {
                    dist[ny][nx][state]=dist[y][x][state]+1;
                    q.push({ny, nx, state});
                }
            }
        }

        //Press button
        int newState=(state^((1<<y)|(1<<(n+x))));
        if (dist[y][x][newState]==-1) {
            dist[y][x][newState]=dist[y][x][state]+1;
            q.push({y, x, newState});
        }
    }

    cout << -1;

    return 0;
}
