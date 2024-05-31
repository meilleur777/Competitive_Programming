#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long h, w, n;
    cin >> h >> w >> n;

    vector<long long> dy({-2, -2, -2, -1, -1, -1, 0, 0, 0});
    vector<long long> dx({-2, -1, 0, -2, -1, 0, -2, -1, 0});

    map<long long, long long> mp;
    for (long long i=0; i<n; i++) {
        long long y, x;
        cin >> y >> x;
        y--, x--;

        for (long long j=0; j<9; j++) {
            long long ny=y+dy[j];
            long long nx=x+dx[j];
            if (ny>=h-2 || ny<0 || nx>=w-2 || nx<0) continue;

            mp[ny*w+nx]++;
        }
    }

    vector<long long> ans;
    ans.push_back((h-2)*(w-2));
    for (long long i=0; i<9; i++) ans.push_back(0);
    for (auto [p, q]:mp) {
        ans[q]++;
        ans[0]--;
    }

    for (long long i=0; i<10; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
