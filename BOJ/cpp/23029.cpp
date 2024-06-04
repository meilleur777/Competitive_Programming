#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<vector<int>> cache(n, vector<int>(3, 0));
    cache[0][1]=a[0];
    for (int i=1; i<n; i++) {
        cache[i][0]=*max_element(cache[i-1].begin(), cache[i-1].end());
        cache[i][1]=cache[i-1][0]+a[i];
        cache[i][2]=cache[i-1][1]+a[i]/2;
    }

    cout << *max_element(cache.back().begin(), cache.back().end());

    return 0;
}
