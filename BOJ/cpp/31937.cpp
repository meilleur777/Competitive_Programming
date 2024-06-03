#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> infected(n, false);
    while (k--) {
        int a;
        cin >> a;
        a--;
        infected[a]=true;
    }

    vector<vector<int>> log(m, vector<int>(3));
    for (int i=0; i<m; i++) {
        for (int j=0; j<3; j++) {
            cin >> log[i][j];
            log[i][j]--;
        }
    }

    sort(log.begin(), log.end());

    for (int i=0; i<n; i++) {
        vector<bool> tmpInf(n, false);
        tmpInf[i]=true;

        for (int i=0; i<m; i++) {
            if (tmpInf[log[i][1]]) {
                tmpInf[log[i][2]]=true;
            }
        }

        if (tmpInf==infected) {
            cout << i+1;
            break;
        }
    }

    return 0;
}
