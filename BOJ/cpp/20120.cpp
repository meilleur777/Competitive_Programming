#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    const long long minusInf=-0x3f3f3f3f3f3f3f3f;
    vector<vector<vector<long long>>> cache(n, vector<vector<long long>>(n+1, vector<long long>(4, minusInf)));

    cache[0][1][0]=a[0];
    cache[0][0][1]=0;

    for (int i=1; i<n; i++) {
        //O->O
        for (int j=2; j<=i+1; j++) {
            cache[i][j][0]=max(cache[i][j][0], cache[i-1][j-1][0]+j*a[i]);
        }

        //X->O
        for (int k=1; k<3; k++) {
            cache[i][1][0]=max(cache[i][1][0], cache[i-1][0][k]+a[i]);
        }

        //O->X
        for (int j=1; j<=i; j++) {
            cache[i][0][1]=max(cache[i][0][1], cache[i-1][j][0]);
        }

        //X->X
        cache[i][0][2]=max(cache[i][0][2], cache[i-1][0][1]);
        if (i>=2) cache[i][0][3]=0;
    }

    long long res=minusInf;
    for (int j=0; j<=n; j++) {
        for (int k=0; k<=3; k++) {
            res=max(res, cache[n-1][j][k]);
        }
    }
    cout << res;

    return 0;
}
