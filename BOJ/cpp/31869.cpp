#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<vector<pair<string, int>>>> v(11, vector<vector<pair<string, int>>>(7));
    for (int i=0; i<n; i++) {
        int w, d, p;
        string s;
        cin >> s >> w >> d >> p;
        v[w][d].push_back({s, p});
    }
    map<string, int> money;
    for (int i=0; i<n; i++) {
        string s;
        int m;
        cin >> s >> m;
        money[s]=m;
    }

    int ans=0;
    int cnt=0;
    for (int i=1; i<=10; i++) {
        for (int j=0; j<7; j++) {
            bool flag=false;
            for (auto [s, p]:v[i][j]) {
                if (money[s]>=p) {
                    flag=true;
                }
            }
            if (flag) cnt++;
            else cnt=0;
            ans=max(ans, cnt);
        }
    }
    cout << ans;

    return 0;
}
