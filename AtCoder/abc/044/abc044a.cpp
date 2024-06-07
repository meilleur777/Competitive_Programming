#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k, x, y;
    cin >> n >> k >> x >> y;
    int ans=0;
    for (int i=0; i<min(k, n); i++) ans+=x;
    for (int j=k; j<n; j++) ans+=y;
    cout << ans;

    return 0;
}
