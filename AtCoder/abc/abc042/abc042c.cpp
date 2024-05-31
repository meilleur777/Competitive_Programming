#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> dislike(10, false);
    for (int i=0; i<k; i++) {
        int a;
        cin >> a;
        dislike[a]=true;
    }

    int ans=1e9;
    string nstr=to_string(n);
    function<void(string)> bruteforce=[&](string now) {
        if (!now.empty() && stoi(now)>=n) {
            ans=min(ans, stoi(now));
            return;
        }

        if (now.size()>nstr.size()+1) return;
 
        for (int i=0; i<10; i++) {
            if (dislike[i]) continue;
            bruteforce(now+string(1, char(i+'0')));
        }
    };

    bruteforce("");
    cout << ans;

    return 0;
}
