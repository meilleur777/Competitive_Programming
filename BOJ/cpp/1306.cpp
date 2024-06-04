#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];

    map<int, int> mp;
    for (int i=0; i<2*m-2; i++) {
        mp[v[i]]++;
    }
    for (int i=0; i+2*m-2<n; i++) {
        mp[v[i+2*m-2]]++;
        cout << mp.rbegin()->first << ' ';
        mp[v[i]]--;
        if (mp[v[i]]==0) {
            mp.erase(v[i]);
        }
    }

    return 0;
}
