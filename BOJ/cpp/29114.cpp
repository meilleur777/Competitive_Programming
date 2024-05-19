#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];
    const int minus=-0x3f3f3f3f;
    vector<vector<int>> cache(n, vector<int>(3, minus));
    
    for (int i=0; i<3; i++) {
        if (brd[0][i]=='W') cache[0][i]=minus;
        if (brd[0][i]=='.') cache[0][i]=0;
        if (brd[0][i]=='C') cache[0][i]=1;
    }
    for (int i=1; i<n; i++) {
        for (int j=0; j<3; j++) {
            if (brd[i][j]=='W') continue;
            int score=(brd[i][j]=='C');
            if (j>0) cache[i][j]=max(cache[i][j], score+cache[i-1][j-1]);
            cache[i][j]=max(cache[i][j], score+cache[i-1][j]);
            if (j<2) cache[i][j]=max(cache[i][j], score+cache[i-1][j+1]);
        }
    }
    int ans=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            ans=max(ans, cache[i][j]);
        }
    }
    cout << ans;

    return 0;
}
