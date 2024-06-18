#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;

    int ans=0;
    for (int i=0; i<n; i++) {
        if (s[i]=='o') ans++;
        else ans+=2;
    }

    cout << ans;

    return 0;
}
