#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> brd(n, vector<int>(m));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> brd[i][j];
        }
    }   

    long long mod=1e9+7;
    vector<vector<long long>> cache(n, vector<long long>(m, -1));
    vector<int> dx({-1, 0, 1});

    function<long long(int, int)> dp=[&](int y, int x) {
        if (!y) return 1LL;
        long long& ret=cache[y][x];
        if (ret!=-1) return ret;
        ret=0;

        for (int i=0; i<3; i++) {
            int ny=y-1;
            int nx=x+dx[i];
            if (nx>=m || nx<0) continue;
            if (!brd[ny][nx]) continue;
            ret=(ret+dp(ny, nx))%mod;
        }
        return ret;
    };

    long long ans=0;
    for (int i=0; i<m; i++) {
        if (brd[n-1][i]) ans=(ans+dp(n-1, i))%mod;
    }
    cout << ans;

    return 0;
}
