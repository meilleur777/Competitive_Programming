#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    v.push_back({0, 0});

    int ans=0;
    stack<int> sk;
    for (auto [x, y]:v) {
        while (!sk.empty() && sk.top()>y) {
            ans++;
            sk.pop();
        }
        if (!sk.empty() && sk.top()==y) {
            continue;
        }
        sk.push(y);
    }

    cout << ans;

    return 0;
}
