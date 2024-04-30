#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k, a, b;
    cin >> n >> k;
    
    vector<vector<int>> v(2, vector<int>(6, 0));
    while (cin >> a >> b) {
        v[a][b-1]++;
    }

    int ans=0;
    for (int i=0; i<2; i++) {
        for (int j=0; j<6; j++) {
            ans+=(v[i][j]+k-1)/k;
        }
    }
    cout << ans;

    return 0;
}
