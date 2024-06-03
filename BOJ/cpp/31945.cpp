#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<vector<int>> v(8);
    for (int i=0; i<(1<<3); i++) {
        for (int j=2; j>=0; j--) {
            v[i].push_back((i&(1<<j)));
        }
    }
    
    int t;
    cin >> t;
    while (t--) {
        vector<int> input(4);
        for (int i=0; i<4; i++) cin >> input[i];

        bool flag=false;
        for (int j=0; j<3; j++) {
            bool flag2=true;
            for (int i=1; i<4; i++) {
                if (v[input[0]][j]!=v[input[i]][j]) {
                    flag2=false;
                }
            }
            if (flag2) {
                flag=true;
                break;
            }
        } 

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
