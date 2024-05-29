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
    string token;
    cin >> token;

    int len=token.size();
    vector<vector<vector<int>>> cache(n, vector<vector<int>>(m, vector<int>(len, -1)));
    function<int(int, int, int)> dp=[&](int y, int x, int now) {
        if (now==len) return 1;

        int& ret=cache[y][x][now];
        if (ret!=-1) return ret;

        ret=0;
        for (int d=0; d<4; d++) {
            int ny=y;
            int nx=x;
            for (int i=0; i<k; i++) {
                ny+=dy[d];
                nx+=dx[d];
                if (ny>=n || ny<0 || nx>=m || nx<0) break;

                if (brd[ny][nx]==token[now]) {
                    ret+=dp(ny, nx, now+1);
                }
            }
        }

        return ret;
    };

    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (token[0]==brd[i][j]) {
                ans+=dp(i, j, 1);
            }
        }
    }
    cout << ans;

    return 0;
}
