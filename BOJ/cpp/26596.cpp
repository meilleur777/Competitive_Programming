#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int m;
    cin >> m;
    map<string, int> mp;
    for (int i=0; i<m; i++) {
        string s;
        int a;
        cin >> s >> a;
        mp[s]+=a;
    }
    bool flag=false;
    for (auto i=mp.begin(); i!=mp.end(); i++) {
        for (auto j=mp.begin(); j!=mp.end(); j++) {
            if (i==j) continue;
            if (i->second*1618/1000==j->second) {
                flag=true;
            }
        }
    }
    if (flag) cout << "Delicious!";
    else cout << "Not Delicious...";

    return 0;
}
