#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, p;
    cin >> n >> m >> p;
    vector<pair<int, int>> judge(n), tar(m), feather(p);
    for (int i=0; i<n; i++) cin >> judge[i].first >> judge[i].second;
    for (int i=0; i<m; i++) cin >> tar[i].first >> tar[i].second;
    for (int i=0; i<p; i++) cin >> feather[i].first >> feather[i].second;

    long double ans=0;
    function<void(const vector<pair<int, int>>&)> sol=[&](const vector<pair<int, int>>& v) {
        vector<pair<int, int>> cand;
        for (int i=0; i<n; i++) {
            for (int j=0; j<(int)v.size(); j++) {
                cand.push_back({i, j});
            }
        }

        sort(cand.begin(), cand.end(), [&](const pair<int, int>& p, const pair<int, int>& q) -> bool {
            int pdist=(judge[p.first].first-v[p.second].first)*(judge[p.first].first-v[p.second].first)
            +(judge[p.first].second-v[p.second].second)*(judge[p.first].second-v[p.second].second);
            int qdist=(judge[q.first].first-v[q.second].first)*(judge[q.first].first-v[q.second].first)
            +(judge[q.first].second-v[q.second].second)*(judge[q.first].second-v[q.second].second);

            if (pdist==qdist) return p.first<q.first;
            return pdist<qdist;
        });

        vector<bool> selJudge(n, false);
        vector<bool> selV((int)v.size(), false);
        for (auto [p, q]:cand) {
            if (selJudge[p] || selV[q]) continue;
            selJudge[p]=true;
            selV[q]=true;

            ans+=sqrtl((judge[p].first-v[q].first)*(judge[p].first-v[q].first)
            +(judge[p].second-v[q].second)*(judge[p].second-v[q].second));
        }
    };
    sol(tar);
    sol(feather);

    cout.precision(7);
    cout << fixed << ans;

    return 0;
}
