#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string brd, ans="";
    cin >> brd;
    int n=brd.size();

    int ptr=0;
    while (ptr<n) {
        while (ptr<n && brd[ptr]=='.') {
            ptr++;
            ans+=".";
        }

        int cnt=0;
        while (ptr<n && brd[ptr]=='X') {
            ptr++;
            cnt++;
        }

        while (cnt>=4) {
            ans+="AAAA";
            cnt-=4;
        }
        while (cnt>=2) {
            ans+="BB";
            cnt-=2;
        }
        if (cnt!=0) {
            cout << -1;
            return 0;
        }
    }

    cout << ans;

    return 0;
}
