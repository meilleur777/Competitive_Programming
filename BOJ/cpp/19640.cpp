#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    auto cpr=[&](const vector<int>& p, const vector<int>& q) {
        if (p[1]==q[1]) {
            if (p[2]==q[2]) {
                int pp=p[0];
                int qq=q[0];
                pp%=m;
                qq%=m;
                return pp>qq;
            }
            return p[2]<q[2];
        }
        return p[1]<q[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cpr)> pq(cpr);

    vector<vector<int>> v(n, vector<int>(3));
    for (int i=0; i<n; i++) {
        v[i][0]=i;
        cin >> v[i][1] >> v[i][2];

        if (i<m) pq.push(v[i]);
    }

    int cnt=0;
    while (true) {
        int now=pq.top()[0];

        if (now==k) {
            cout << cnt;
            return 0;
        }

        pq.pop();
        cnt++;

        int nxt=(now/m+1)*m+now%m;
        if (nxt<n) {
            pq.push(v[nxt]);
        }
    }

    return 0;
}
