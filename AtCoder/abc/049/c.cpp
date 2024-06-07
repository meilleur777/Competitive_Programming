#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    string s;
    cin >> s;
    int n=s.size();

    vector<int> cache(n+1, false);
    vector<string> cand({"dream", "dreamer", "erase", "eraser"});
    for (int i=0; i<n; i++) {
        if (i!=0 && cache[i]==false) continue;

        for (auto c:cand) {
            int cc=(int)c.size();
            if (i+cc<=n && c==s.substr(i, cc)) {
                cache[i+cc]=true;
            }
        }
    }

    if (cache.back()) cout << "YES";
    else cout << "NO";

    return 0;
}
