#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> dy({0, 0, 1, -1});
    vector<int> dx({1, -1, 0, 0});
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];

    const int inf=0x3f3f3f3f;
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k+1, inf)));
    dist[0][0][0]=1;
    queue<vector<int>> q;
    q.push({0, 0, 0});

    while (!q.empty()) {
        int y=q.front()[0];
        int x=q.front()[1];
        int broke=q.front()[2];
        int time=1-dist[y][x][broke]%2;
        q.pop();

        int nxtTime=1-time;

        for (int d=0; d<4; d++) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=n || ny<0 || nx>=m || nx<0) continue;

            if (brd[ny][nx]=='0') {
                if (dist[ny][nx][broke]>dist[y][x][broke]+1) {
                    dist[ny][nx][broke]=dist[y][x][broke]+1;
                    q.push({ny, nx, broke});
                }
            }
            else if (brd[ny][nx]=='1') {
                int cost=1;
                if (time!=0) cost++;
                if (broke>=k) continue;

                if (dist[ny][nx][broke+1]>dist[y][x][broke]+cost) {
                    dist[ny][nx][broke+1]=dist[y][x][broke]+cost;
                    q.push({ny, nx, broke+1});
                }
            }
        }
    }

    int ans=*min_element(dist[n-1][m-1].begin(), dist[n-1][m-1].end());
    if (ans>=inf) cout << -1;
    else cout << ans;

    return 0;
}
