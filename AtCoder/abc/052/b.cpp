#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
        
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a=0;
    int ans=0;
    for (auto c:s) {
        if (c=='I') a++;
        else a--;
        ans=max(ans, a);
    }
    cout << ans;

    return 0;
}
