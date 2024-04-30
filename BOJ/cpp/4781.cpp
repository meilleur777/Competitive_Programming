#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    function<int(string)> stringToInt=[&](string s) {
        s.erase(s.end()-3);
        return stoi(s);
    };
    
    while (1) {
        int n, m;
        string b;
        cin >> n >> b;
        m=stringToInt(b);
        if (n==0 && m==0) return 0;

        vector<pair<int, int>> v(n);
        for (int i=0; i<n; i++) {   
            int a;
            cin >> a >> b;
            v[i]={a, stringToInt(b)};
        }

        vector<int> cache(m+1, -1);
        function<int(int)> dp=[&](int rem) {
            if (rem==0) return 0;
            int& ret=cache[rem];
            if (ret!=-1) return ret;

            bool flag=false;
            for (int i=0; i<n; i++) {
                if (rem-v[i].second>=0) {
                    flag=true;
                    ret=max(ret, dp(rem-v[i].second)+v[i].first);
                }
            }
            if (flag) return ret;
            else return ret=0;
        };
        cout << dp(m) << '\n';
    }

    return 0;
}
