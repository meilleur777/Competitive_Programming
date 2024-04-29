#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> v(n), t(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }
    for (int i=0; i<n; i++) {
        cin >> t[i];
    }
    int cnt=0;
    for (int i=0; i<n-2; i++) {
        for (int j=0; j<m-2; j++) {
            if (v[i][j]!=t[i][j]) {
                cnt++;
                for (int k=0; k<3; k++) {
                    for (int l=0; l<3; l++) {
                        if (v[i+k][j+l]=='0') v[i+k][j+l]='1';
                        else v[i+k][j+l]='0';
                    }
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        cout << v[i] << '\n';
        for (int j=0; j<m; j++) {
            if (v[i][j]!=t[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }
    cout << cnt;


    return 0;
}
