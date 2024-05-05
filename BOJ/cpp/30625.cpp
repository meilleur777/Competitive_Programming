#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    vector<pair<int, bool>> v;
    for (int i=0; i<n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    int cnt1=0;
    for (int i=0; i<n; i++) {
        cnt1+=v[i].second;
    }

    

    return 0;
}
