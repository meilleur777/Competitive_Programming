#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> brd(n);
    rep(i, n) cin >> brd[i];

    int ans=k*k;

    //BW
    //WB
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((i+j)%2==0) {
                if (brd[i][j]!='B') v[i][j]=1;
            }
            else {
                if (brd[i][j]!='W') v[i][j]=1;
            }
        }
    }

    vector<vector<int>> presum(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        presum[i][0]=v[i][0];
        for (int j=1; j<m; j++) {
            presum[i][j]=presum[i][j-1]+v[i][j];
        }
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<m; j++) {
            presum[i][j]+=presum[i-1][j];
        }
    }

    function<int(int, int)> getsum=[&](int sy, int sx) {
        int ret=presum[sy+k-1][sx+k-1];
        if (sy) {
            ret-=presum[sy-1][sx+k-1];
        }
        if (sx) {
            ret-=presum[sy+k-1][sx-1];
        }
        if (sy && sx) {
            ret+=presum[sy-1][sx-1];
        }
        return ret;
    };

    for (int i=0; i+k-1<n; i++) {
        for (int j=0; j+k-1<m; j++) {
            int tmp=getsum(i, j);
            ans=min(ans, tmp);
        }
    }

    v=vector<vector<int>>(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if ((i+j)%2==0) {
                if (brd[i][j]!='W') v[i][j]=1;
            }
            else {
                if (brd[i][j]!='B') v[i][j]=1;
            }
        }
    }

    presum=vector<vector<int>>(n, vector<int>(m, 0));
    for (int i=0; i<n; i++) {
        presum[i][0]=v[i][0];
        for (int j=1; j<m; j++) {
            presum[i][j]=presum[i][j-1]+v[i][j];
        }
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<m; j++) {
            presum[i][j]+=presum[i-1][j];
        }
    }

    for (int i=0; i+k-1<n; i++) {
        for (int j=0; j+k-1<m; j++) {
            int tmp=getsum(i, j);
            ans=min(ans, tmp);
        }
    }

    cout << ans;

    return 0;
}
