#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int ans=0;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        int cnt=0;
        for (auto c:s) {
            cnt+=c=='O';
        }

        if (cnt>m/2) ans++;
    }
    cout << ans;

    return 0;
}
