#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int k=0;
    cin >> k;

    vector<vector<int>> cache(n, vector<int>(m, 0));
    cache[0][0]=1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (i>0) cache[i][j]+=cache[i-1][j];
            if (j>0) cache[i][j]+=cache[i][j-1];
        }
    }

    if (k) {
        k--;
        pair<int, int> kpos={k/m, k%m};
        cout << cache[kpos.first][kpos.second]*cache[n-kpos.first-1][m-kpos.second-1];
    }
    else {
        cout << cache[n-1][m-1];
    }

    return 0;
}
