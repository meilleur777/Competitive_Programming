#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    string ans=string(1, s[0]);
    for (int i=1; i<n; i++) {
        ans+=to_string((s[i-1]+s[i]-2*'0')%2);
    }
    cout << ans;

    return 0;
}
