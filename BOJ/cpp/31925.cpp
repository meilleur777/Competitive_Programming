#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<string, int>> v;

    for (int i=0; i<n; i++) {
        string name, a, b;
        int s, r;
        cin >> name >> a >> b >> s >> r;
        if (a=="jaehak" && b=="notyet" && (s==-1 || s>3)) {
            v.push_back({name, r});
        }
    }
    sort(v.begin(), v.end(), [&](const pair<string, int>& p, const pair<string, int>& q) -> bool {
        return p.second<q.second;
    });

    int k=min((int)v.size(), 10);
    cout << k << "\n";
    vector<string> ans;
    for (int i=0; i<k; i++) {
        ans.push_back(v[i].first);
    }
    sort(ans.begin(), ans.end());
    for (auto s:ans) cout << s << '\n';

    return 0;
}
