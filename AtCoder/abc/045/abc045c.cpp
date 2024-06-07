#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    int n=s.size();

    long long ans=0;
    function<void(int, int)> bruteforce=[&](int now, int state) {
        if (now==n-1) {
            long long res=0;
            long long tmp=0;
            for (int i=0; i<n; i++) {
                tmp*=10;
                tmp+=s[i]-'0';
                if ((state&(1<<i))) {
                    res+=tmp;
                    tmp=0;
                }
            }
            res+=tmp;
            ans+=res;
            return;
        }

        bruteforce(now+1, (state|(1<<now)));
        bruteforce(now+1, state);
    };
    bruteforce(0, 0);

    cout << ans;


    return 0;
}
