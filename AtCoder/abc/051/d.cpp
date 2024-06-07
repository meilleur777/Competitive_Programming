#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    const int inf=0x3f3f3f3f;
    vector<vector<int>> cost(n, vector<int>(n, inf));
    vector<vector<int>> edge(m);

    for (int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        cost[a][b]=c;
        cost[b][a]=c;
        edge[i]={a, b, c};
    }

    for (int p=0; p<n; p++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i==j) continue;
                cost[i][j]=min(cost[i][j], cost[i][p]+cost[p][j]);
            }
        }
    }

    int ans=0;
    for (int i=0; i<m; i++) {
        if (cost[edge[i][0]][edge[i][1]]<edge[i][2]) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}
