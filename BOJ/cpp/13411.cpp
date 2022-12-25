#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<intp, intp>> v(n);
    rep(i, n) {
        v[i].first.first=i;
        cin >> v[i].second.first >> v[i].second.second >> v[i].first.second;
    }

    sort(v.begin(), v.end(), [&](const pair<intp, intp>& a, const pair<intp, intp>& b) {
        ll aa=((ll)a.second.first*a.second.first+a.second.second*a.second.second)*b.first.second*b.first.second;
        ll bb=((ll)b.second.first*b.second.first+b.second.second*b.second.second)*a.first.second*a.first.second;
        if (aa==bb) return a.first.first<b.first.first;
        return aa<bb;
    });

    for (auto i:v) {
        cout << i.first.first+1 << '\n';
    }

    return 0;
}
