#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    set<int> st;
    vector<vector<int>> need(n, vector<int>(n, 0));
    vector<vector<pair<int, int>>> edge(n);
    vector<int> ind(n, 0);

    while (m--) {
        int x, y, k;
        cin >> x >> y >> k;
        x--, y--;
        edge[y].push_back({x, k});
        ind[x]++;
    }

    queue<int> q;
    for (int i=0; i<n; i++) {
        if (ind[i]==0) {
            need[i][i]=1;
            q.push(i);
            st.insert(i);
        }
    }

    while (!q.empty()) {
        int now=q.front();
        q.pop();

        for (auto [nxt, cnt]:edge[now]) {
            ind[nxt]--;
            if (ind[nxt]==0) {
                q.push(nxt);
            }
            for (int i=0; i<n; i++) {
                need[nxt][i]+=cnt*need[now][i];
            }
        }
    }

    for (int i=0; i<n; i++) {
        if (st.find(i)!=st.end()) {
            cout << i+1 << ' ' << need[n-1][i] << '\n';
        }
    }

    return 0;
}
