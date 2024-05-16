#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        //src=0, dst=1, cell=2~n*m+1, operation=n*m+2~2*n*m-n-m+2
        int siz=2*n*m-n-m+2;
        int src=0, dst=1;
        vector<vector<int>> capacity(siz, vector<int>(siz, 0));
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                edge[src].push_back(2+i*m+j);
                edge[2+i*m+j].push_back(src);
                cin >> capacity[src][2+i*m+j];
            }
        }

        for (int i=0; i<2*n; i++) {
            for (int j=0; j<)
        }
    }

    return 0;
}
