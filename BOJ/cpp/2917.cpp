#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    rep(i, n) cin >> brd[i];

    intp hun, tree;
    queue<pair<intp, int>> q;
    vector<vector<int>> vis(n, vector<int>(m, -1));
    rep(i, n) {
        rep(j, m) {
            if (brd[i][j]=='+') {
                q.push({{i, j}, 0});
                vis[i][j]=0;
            }
            else if (brd[i][j]=='V') {
                hun={i, j};
            }
            else if (brd[i][j]=='J') {
                tree={i, j};
            }
        }
    }

    vector<int> dy({1, -1, 0, 0}), dx({0, 0, 1, -1});
    while (!q.empty()) {
        int y=q.front().first.first;
        int x=q.front().first.second;
        int cos=q.front().second;
        q.pop();

        rep(d, 4) {
            int ny=y+dy[d];
            int nx=x+dx[d];
            if (ny>=n || ny<0 || nx>=m || nx<0) continue;
            if (vis[ny][nx]!=-1) continue;
            vis[ny][nx]=vis[y][x]+1;
            q.push({{ny, nx}, vis[ny][nx]});
        }
    }

    int left=0, right=n+m+1;
    int ans=0;
    while (left<=right) {
        int mid=(left+right)/2;
        vector<vector<bool>> qqq(n, vector<bool>(m, false));
        function<void(int, int, int)> chk=[&](int y, int x, int val) {
            if (vis[y][x]<val) return;
            if (qqq[y][x]) return;
            qqq[y][x]=true;
            rep(d, 4) {
                int ny=y+dy[d];
                int nx=x+dx[d];
                if (ny>=n || ny<0 || nx>=m || nx<0) continue;
                chk(ny, nx, val);
            }
        };
        chk(hun.first, hun.second, mid);
        if (qqq[tree.first][tree.second]) {
            ans=max(ans, mid);
            left=mid+1;
        }
        else {
            right=mid-1;
        }
    }
    cout << ans;

    return 0;
}
