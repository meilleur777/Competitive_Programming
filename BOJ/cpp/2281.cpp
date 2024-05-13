#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> name(n);
    for (int i=0; i<n; i++) {
        cin >> name[i];
    }

    const int inf=0x7f7f7f7f;
    vector<vector<int>> cache(m, vector<int>(n, inf));

    function<int(int, int)> dp=[&](int lastPos, int now) {
        if (now==n) {
            return 0;
        }
        if (lastPos==-1) {
            return dp(name[now]-1, now+1);
        }

        int& ret=cache[lastPos][now];
        if (ret!=inf) return ret;

        if (lastPos+2+name[now]-1<m) {
            ret=min(ret, dp(lastPos+2+name[now]-1, now+1));
        }
        ret=min(ret, ((m-1)-(lastPos+1)+1)*((m-1)-(lastPos+1)+1)+dp(-1, now));

        return ret;
    };

    cout << dp(-1, 0);

    return 0;
}
