#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vector<vector<int>> v(n, vector<int>(3));
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            cin >> v[i][j];
        }
    }

    const int inf=0x3f3f3f3f;
    vector<vector<vector<int>>> cache(n, vector<vector<int>>(401, vector<int>(401, inf)));
    cache[0][0][0]=0;
    cache[0][v[0][0]][v[0][1]]=v[0][2];

    for (int i=1; i<n; i++) {
        for (int j=0; j<=400; j++) {
            for (int k=0; k<=400; k++) {
                cache[i][j][k]=min(cache[i][j][k], cache[i-1][j][k]);
                if (j-v[i][0]>=0 && k-v[i][1]>=0) {
                    cache[i][j][k]=min(cache[i][j][k], cache[i-1][j-v[i][0]][k-v[i][1]]+v[i][2]);
                }
            }
        }
    }

    int ans=inf;
    int tma=ma, tmb=mb;

    while (tma<=400 && tmb<=400) {
        for (int i=0; i<n; i++) {
            ans=min(ans, cache[i][tma][tmb]);
        }
        tma+=ma, tmb+=mb;
    }

    if (ans>=inf) cout << -1;
    else cout << ans;
    
    return 0;
}
