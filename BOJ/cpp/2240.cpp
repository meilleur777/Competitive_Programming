#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t, w;
    cin >> t >> w;
    vector<int> plum(t);
    for (int i=0; i<t; i++) {
        cin >> plum[i];
        plum[i]--;
    }

    vector<vector<vector<int>>> cache(t, vector<vector<int>>(2, vector<int>(w+1, -1)));
    function<int(int, int, int)> dp=[&](int now, int pos, int used) {
        if (now>=t) return 0;

        int& ret=cache[now][pos][used];
        if (ret!=-1) return ret;

        ret=0;
        ret=max(ret, dp(now+1, pos, used)+(pos==plum[now]));
        if (used<w) ret=max(ret, dp(now+1, (pos==1?0:1), used+1)+(pos!=plum[now]));

        return ret;
    };
    cout << dp(0, 0, 0);

    return 0;
}
