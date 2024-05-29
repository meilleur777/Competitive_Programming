#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<tuple<int, int, string>> v(n);
    for (int i=0; i<n; i++) {
        auto& [a, b, c]=v[i];
        a=i;
        cin >> b >> c;
    }

    sort(v.begin(), v.end(), 
        [](const tuple<int, int, string>& p, const tuple<int, int, string>& q) -> bool {
        auto& [pa, pb, pc]=p;
        auto& [qa, qb, qc]=q;
        if (pb==qb) return pa<qa;
        return pb<qb;
    });

    for (auto [a, b, c]:v) cout << b << ' ' << c << '\n';

    return 0;
}
