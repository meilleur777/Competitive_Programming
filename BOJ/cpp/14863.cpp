#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(4));
    for (int i=0; i<n; i++) {
        for (int j=0; j<4; j++) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> cache(n, vector<int>(k+1, -1));
    cache[0][v[0][0]]=max(cache[0][v[0][0]], v[0][1]);
    cache[0][v[0][2]]=max(cache[0][v[0][2]], v[0][3]);

    for (int i=1; i<n; i++) {
        for (int j=k; j>=0; j--) {
            for (int l=0; l<2; l++) {
                if (j-v[i][l*2]>=0 && cache[i-1][j-v[i][l*2]]!=-1) {
                    cache[i][j]=max(cache[i][j], cache[i-1][j-v[i][l*2]]+v[i][l*2+1]);
                }
            }
        }
    }
    
    cout << *max_element(cache[n-1].begin(), cache[n-1].end());

    return 0;
}
