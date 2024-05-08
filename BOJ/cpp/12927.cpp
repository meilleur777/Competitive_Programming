#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    int n=s.size();

    int ans=0;
    for (int i=1; i<=n; i++) {
        if (s[i-1]=='Y') {
            ans++;
            for (int j=i; j<=n; j+=i) {
                if (s[j-1]=='N') s[j-1]='Y';
                else s[j-1]='N';
            }
        }
    }

    cout << ans;

    return 0;
}
