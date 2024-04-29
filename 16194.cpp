#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> p(n+1, 0);
    for (int i=0; i<n; i++) cin >> p[i+1];

    for (int i=1; i<=n; i++) {
        for (int j=0; j<i; j++) {
            p[i]=min(p[i], p[i-j]+p[j]);
        }
    }

    cout << p[n];

    return 0;
}
