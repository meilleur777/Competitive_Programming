#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        string to, from;
        cin >> to >> from;

        int n=to.size(), m=from.size();
        vector<int> cnt(26, 0);
        for (int i=0; i<m; i++) cnt[from[i]-'a']++;        

        vector<vector<int>> presum(n, vector<int>(26, 0));
        presum[0][to[0]-'a']++;
        for (int i=1; i<n; i++) {
            presum[i][to[i]-'a']++;
            for (int j=0; j<26; j++) {
                presum[i][j]+=presum[i-1][j];
            }
        }

        function<vector<int>(int, int)> getsum=[&](int a, int b) {
            if (a==0) return presum[b];
            vector<int> ret(26, 0);
            ret=presum[b];
            for (int i=0; i<26; i++) {
                ret[i]-=presum[a-1][i];
            }
            return ret;
        };

        bool flag=false;
        for (int i=0; i+m-1<n; i++) {
            if (getsum(i, i+m-1)==cnt) {
                flag=true;
                break;
            }
        }

        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
