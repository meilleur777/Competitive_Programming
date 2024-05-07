#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    for (int i=n-3; i>=0; i--) {
        if (v[i+2]<v[i+1]+v[i]) {
            cout << v[i+2]+v[i+1]+v[i];
            return 0;
        }
    }
    cout << -1;

    return 0;
}
