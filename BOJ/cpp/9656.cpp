#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> dp(n+1, -1);
    dp[1]=dp[3]=dp[4]=1;

    function<int(int)> sol=[&](int num) {
        if (dp[num]!=-1) return dp[num];

        int& ret=dp[num];
        ret=0;
        if (num>=1 && sol(num-1)==0) ret=1;
        if (num>=3 && sol(num-3)==0) ret=1;
        if (num>=4 && sol(num-4)==0) ret=1;
        return ret;
    };

    if (sol(n)==1) cout << "SK";
    else cout << "CY";

    return 0;
}
