#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    string k;
    cin >> n >> k;

    vector<int> cnt(2, 0);
    for (int i=0; i<n; i++) {
        cnt[(k[i]-'0')%2]++;
    }

    if (cnt[0]>cnt[1]) cout << 0;
    else if (cnt[0]<cnt[1]) cout << 1;
    else cout << -1;

    return 0;
}
