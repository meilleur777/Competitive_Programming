#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    rep(i, n) rep(j, n) {
        cin >> a[i][j];
    }

    // 0->left upper to right lower, 1->right upper to left lower
    vector<vector<vector<int>>> presum(2, vector<vector<int>>(n, vector<int>(n, 0)));
    for (int i=0; i<n; i++) {
        for (int j=0; j<2; j++) {
            presum[j][0][i]+=a[0][i];
        }
    }
    for (int i=1; i<n; i++) {
        presum[0][i][0]+=a[i][0];
        presum[1][i][n-1]+=a[i][n-1];
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i&&j) presum[0][i][j]+=presum[0][i-1][j-1]+a[i][j];
            if (i&&j!=n-1) presum[1][i][j]+=presum[1][i-1][j+1]+a[i][j];
        }
    }

    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=2; k<=n; k++) {
                if (i+k-1<n && j+k-1<n) {
                    int num0=presum[0][i+k-1][j+k-1];
                    if (i && j) num0-=presum[0][i-1][j-1];
                    int num1=num1=presum[1][i+k-1][j];
                    if (i && j+k<n) num1-=presum[1][i-1][j+k];
                    ans=max(ans, num0-num1);
                }
            }
        }
    }
    cout << ans;

    return 0;
}
