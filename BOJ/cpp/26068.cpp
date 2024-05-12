#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    int ans=0;
    while (n--) {
        string s;
        cin >> s;
        int a=stoi(s.substr(2));
        if (a<=90) ans++;
    }
    cout << ans;

    return 0;
}
