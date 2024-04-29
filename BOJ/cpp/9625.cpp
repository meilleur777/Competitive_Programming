#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> v(n+1, {1, 0});
    for (int i=1; i<=n; i++) {
        v[i].first=v[i-1].second;
        v[i].second=v[i-1].first+v[i-1].second;
    }
    cout << v[n].first << ' ' << v[n].second;

    return 0;
}
