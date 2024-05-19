#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; i++) cin>> v[i];

    vector<vector<int>> cache(n, vector<int>(1e5+1, -1));
    function<int(int, int)> dp=[&](int now, int last) {
        if (now==n) return 0;

        int& ret=cache[now][last];
        if (ret!=-1) return ret;

        if (v[now]>last) ret=max(ret, v[now]+dp(now+1, v[now]));
        ret=max(ret, dp(now+1, last));

        return ret;
    };
    cout << dp(0, 0);

    return 0;
}
