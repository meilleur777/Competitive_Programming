#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> brd(n);
    for (int i=0; i<n; i++) cin >> brd[i];

    vector<vector<map<string, int>>> cache(n, vector<map<string, int>>(n));

    function<int(int, int, string)> dp=[&](int y, int x, string state) {
        if (y==n-1 && x==n-1) return (int)(state=="MOLA");

        if (cache[y][x].find(state)!=cache[y][x].end()) {
            return cache[y][x][state];
        }

        int isMola=(state=="MOLA");
        int ret=isMola;
        if (y+1<n) ret=max(ret, isMola+dp(y+1, x, state.substr(1)+brd[y+1][x]));
        if (x+1<n) ret=max(ret, isMola+dp(y, x+1, state.substr(1)+brd[y][x+1]));

        cache[y][x][state]=ret;
        return ret;
    };

    cout << dp(0, 0, "XXX"+string(1, brd[0][0]));

    return 0;
}
