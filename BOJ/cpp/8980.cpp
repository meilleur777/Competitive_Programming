#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, c, m;
    cin >> n >> c >> m;
    vector<vector<int>> v(m);
    for (int i=0; i<m; i++) {
        for (int j=0; j<3; j++) {
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    const int inf=0x3f3f3f3f;
    sort(v.begin(), v.end(), [](const vector<int>& p, const vector<int>& q) -> bool {
        if (p[1]==q[1]) return p[0]<q[0];
        return p[1]<q[1];
    });

    int ans=0;
    vector<int> prefix(n+2, 0);
    for (int i=0; i<m; i++) {
        vector<int> sum(n+2, 0);
        for (int j=1; j<=n; j++) {
            sum[j]=sum[j-1]+prefix[j];
        }

        int toLoad=inf;
        for (int j=v[i][0]; j<=v[i][1]; j++) {
            toLoad=min({toLoad, c-sum[j], v[i][2]});
        }

        ans+=toLoad;
        prefix[v[i][0]]+=toLoad;
        prefix[v[i][1]]-=toLoad;
    }

    cout << ans;

    return 0;
}
