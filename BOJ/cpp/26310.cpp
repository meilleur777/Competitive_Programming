#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<string, vector<int>>> v;
    for (int i=0; i<6; i++) {
        string s;
        int a, b, c, d, e;
        cin >> s >> a >> b >> c >> d >> e;
        v.push_back({s, {a, b, c, d, e}});
    }
    function<int(pair<string, vector<int>>)> score=[&](pair<string, vector<int>> p) {
        return 56*p.second[0]+24*p.second[1]+14*p.second[2]+6*p.second[3]+30*p.second[4];
    };
    sort(v.begin(), v.end(), [&](pair<string, vector<int>>p, pair<string, vector<int>> q) -> bool {
        return score(p)>score(q);
    });

    int mem=-1;
    for (int i=0; i<6; i++) {
        if (v[i].first=="Taiwan") {
            mem=i;
        }
    }

    cout << n/6+(n%6>mem);

    return 0;
}
