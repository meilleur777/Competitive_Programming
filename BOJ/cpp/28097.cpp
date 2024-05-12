#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    int res=0;
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        res+=a;
    }
    res+=8*(n-1);
    cout << res/24 << ' ' << res%24;

    return 0;
}
