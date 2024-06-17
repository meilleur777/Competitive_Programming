#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    long long k;
    cin >> n >> k;
    vector<int> d(n), s(n);
    for (int i=0; i<n; i++) cin >> s[i];
    for (int i=0; i<n; i++) cin >> d[i];

    int lgn=ceil(log2(k));
    vector<vector<int>> go(lgn+1, vector<int>(n));
    for (int i=0; i<n; i++) {
        go[0][d[i]-1]=i;
    }
    for (int i=1; i<=lgn; i++) {
        for (int j=0; j<n; j++) {
            go[i][j]=go[i-1][go[i-1][j]];
        }
    }

    for (int i=0; i<n; i++) {
        long long now=k;
        int res=i;
        for (int j=0; j<=lgn; j++) {
            if (now&(1LL<<j)) {
                res=go[j][res];
            }
        }
        cout << s[res] << ' '; 
    }

    return 0;
}
