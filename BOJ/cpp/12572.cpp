#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    for (int caseNum=1; caseNum<=t; caseNum++) {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i=0; i<n; i++) {
            cin >> v[i].first >> v[i].second;
        }

        sort(v.begin(), v.end());

        set<int> st;
        int ans=0;
        for (int i=0; i<n; i++) {
            for (auto p:st) {
                if (p>v[i].second) ans++;
            }
            st.insert(v[i].second);
        }

        cout << "Case #" << caseNum << ": " << ans << '\n';
    }

    return 0;
}
