#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];

    for (int i=0; i<n-m+1; i++) {
        for (int j=0; j<n-m+1; j++) {
            bool flag=true;

            for (int k=0; k<m; k++) {
                for (int l=0; l<m; l++) {
                    if (a[i+k][j+l]!=b[k][l]) {
                        flag=false;
                    }
                }
            }

            if (flag) {
                cout << "Yes";
                return 0;
            }
        }
    }

    cout << "No";


    return 0;
}
