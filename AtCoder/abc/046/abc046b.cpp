#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    int ans=k;
    for (int i=1; i<n; i++) {
        ans*=(k-1);
    }
    cout << ans;

    return 0;
}
