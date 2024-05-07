#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> skill(n); //mp, power
    for (int i=0; i<n; i++) {
        cin >> skill[i].first >> skill[i].second;
    }

    const int inf=0x3f3f3f3f;
    vector<vector<int>> cache(n, vector<int>(m+1, -1));
    function<int(int, int)> dp=[&](int nowskill, int nowhp) {
        if (nowskill==n) {
            if (nowhp==0) return 0;
            else return inf;
        }

        int& ret=cache[nowskill][nowhp];
        if (ret!=-1) return ret;

        ret=dp(nowskill+1, nowhp);
        int tmphp=nowhp;
        int tmpcost=0;
        int cost=skill[nowskill].first, power=skill[nowskill].second;
        while (true) {
            if (tmphp-power<0) break;
            tmphp-=power;
            tmpcost+=cost;
            ret=min(ret, tmpcost+dp(nowskill+1, tmphp));
            cost+=k;
        }

        return ret;
    };

    cout << dp(0, m);

    return 0;
}
