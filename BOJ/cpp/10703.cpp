#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];

    int fall=1e5;
    for (int i=0; i<m; i++) {
        int closest=n;
        for (int j=0; j<n; j++) {
            if (brd[j][i]=='X') closest=j;
        }
        if (closest==n) continue;

        int distance=0;
        while (brd[closest+distance+1][i]!='#') {
            distance++;
        }
        fall=min(fall, distance);
    }

    vector<string> ans(n, string(m, '.'));
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (brd[i][j]=='#') ans[i][j]='#';
            else if (brd[i][j]=='X') {
                ans[i+fall][j]='X';
            }
        }
    }

    for (auto s:ans) cout << s << '\n';


    return 0;
}
