#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, v;
    cin >> n >> v;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    
    vector<vector<vector<char>>> cache(n, vector<vector<char>>(1001, vector<char>(1001, -1)));
    function<char(int, int, int)> sol=[&](int last, int mn, int mx) {
        if (mx-mn>=v) {
            return char(0);
        }

        char& ret=cache[last][mn][mx];
        if (ret!=-1) return ret;

        ret=51;
        if (last<n-1) ret=min(ret, char(sol(last+1, min(mn, a[last+1]), max(mx, a[last+1]))+1));
        if (last<n-2) ret=min(ret, char(sol(last+2, min(mn, a[last+2]), max(mx, a[last+2]))+1));

        return ret;
    };  
    cout << min(n, int(sol(0, a[0], a[0])+1));

    return 0;
}
