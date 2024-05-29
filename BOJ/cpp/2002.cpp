#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        mp[s]=i;
    }

    vector<string> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    int ans=0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i=n-1; i>=0; i--) {
        int num=mp[v[i]];
        if (!pq.empty() && pq.top()<num) ans++;
        pq.push(num);
    }
    cout << ans;

    return 0;
}
