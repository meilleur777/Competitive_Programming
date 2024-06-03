#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;

    bool isIn=false;
    for (auto c:s) if (c=='?') isIn=true;

    int n=s.size();
    vector<vector<vector<int>>> cache(n, vector<vector<int>>(n, vector<int>(3, -1)));
    function<bool(int, int, int)> dp=[&](int left, int right, int used) {
        if (left>right) return false;

        int& ret=cache[left][right][used];
        if (ret!=-1) {
            if (ret==1) return true;
            return false;
        }

        ret=0;
        for (int j=0; j<2; j++) {
            for (int i=left; i<=right; i++) {
                if (s[i]=='?') {
                    if (used!=j+1) break;
                }
                else {
                    if (j!=s[i]-'0') break;
                }
                if (!dp(i+1, right, used)) ret=1;
            }
            for (int i=right; i>=left; i--) {
                if (s[i]=='?') {
                    if (used!=j+1) break;
                }
                else {
                    if (j!=s[i]-'0') break;
                }
                if (!dp(left, i-1, used)) ret=1;
            }
        }
        if (used==0 && isIn) {
            if (!dp(left, right, 1)) ret=1;
            if (!dp(left, right, 2)) ret=1;
        }

        if (ret==1) return true;
        return false;
    };

    cout << dp(0, n-1, 0);

    return 0;
}
