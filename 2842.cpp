#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<int> dy({0, 0, -1, -1, -1, 1, 1, 1});
    vector<int> dx({1, -1, 1, 0, -1, 1, 0, -1});
    
    int n;
    cin >> n;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];
    vector<vector<int>> height(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> height[i][j];
        }
    }

    int sy, sx;
    vector<int> v;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (brd[i][j]=='P') {
                sy=i;
                sx=j;
            }
            v.push_back(height[i][j]);
        }
    }
    sort(v.begin(), v.end());

    function<bool(int, int)> pos=[&](int low, int high) {
        queue<pair<int, int>> q;
        if (height[sy][sx]<low || high<height[sy][sx]) return false;
        q.push({sy, sx});
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[sy][sx]=true;

        while (!q.empty()) {
            auto [y, x]=q.front();
            q.pop();

            for (int d=0; d<(int)dy.size(); d++) {
                int ny=y+dy[d];
                int nx=x+dx[d];
                if (ny>=n || ny<0 || nx>=n || nx<0) continue;
                if (vis[ny][nx]==true) continue;
                if (height[ny][nx]<low || high<height[ny][nx]) continue;

                vis[ny][nx]=true;
                q.push({ny, nx});
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (brd[i][j]=='K' && !vis[i][j]) {
                    return false;
                }
            }
        }
        return true;
    };

    int ans=1e7;
    int right=0;
    for (int left=0; left<n*n; left++) {
        while (!pos(v[left], v[right]) && right<n*n-1) {
            right++;
        }
        if (pos(v[left], v[right])) ans=min(ans, v[right]-v[left]);
    }
    cout << ans;

    return 0;
}
