#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    int ans=0;

    for (int i=0; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int res=0;

        if (a==b && b==c) {
            res=1e4+a*1e3;
        }
        else if (a==b || a==c) {
            res=1e3+a*100;
        }
        else if (b==c) {
            res=1e3+b*100;
        }
        else {
            res=max({a, b, c})*100;
        }

        ans=max(ans, res);
    }
    cout << ans;

    return 0;
}
