#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        vector<int> presum(n, 0);
        presum[0]=a[0];
        for (int i=1; i<n; i++) {
            presum[i]=presum[i-1]+a[i];
        }
        function<int(int, int)> getsum=[&](int begin, int end) {
            int ret=presum[end-1];
            if (begin!=0) ret-=presum[begin-1];
            return ret;
        };

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        function<int(int, int)> sol=[&](int begin, int end) {
            if (begin>=end) return 0;
            int& ret=dp[begin][end];
            if (ret!=-1) return ret;
            ret=max(ret, getsum(begin, end)-sol(begin+1, end));
            ret=max(ret, getsum(begin, end)-sol(begin, end-1));
            return ret;
        };
        cout << sol(0, n) << '\n';
    }

    return 0;
}
