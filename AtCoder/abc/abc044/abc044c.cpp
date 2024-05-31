#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, a;
    cin >> n >> a;
    vector<int> x(n);
    for (int i=0; i<n; i++) cin >> x[i];

    int sum=0;
    for (int i=0; i<n; i++) sum+=x[i];

    // //number of card, sum
    // vector<vector<vector<long long>>> cache(n+1, vector<vector<long long>>(n, vector<long long>(n*a+1, 0)));
    // for (int j=0; j<n; j++) {
    //     for (int i=1; i<=j+1; i++) {
    //         for (int k=x[j]; k<=n*a; k++) {
    //             cache[i][j][k]+=cache[i-1][j][k-x[j]];
    //         }
    //     }
    // }

    // long long ans=0;
    // for (int i=1; i<=n; i++) {
    //     ans+=cache[i][n-1][i*a];
    // }
    // cout << ans;

    vector<vector<vector<long long>>> cache(n, vector<vector<long long>>(n+1, vector<long long>(sum+1, -1)));
    function<long long(int, int, int)> dp=[&](int now, int used, int sum) {
        if (now==n) {
            if (used!=0 && used*a==sum) return 1LL;
            return 0LL;
        }

        long long &ret=cache[now][used][sum];
        if (ret!=-1) return ret;

        ret=0;
        ret+=dp(now+1, used+1, sum+x[now]);
        ret+=dp(now+1, used, sum);

        return ret;
    };

    cout << dp(0, 0, 0);

    return 0;
}
