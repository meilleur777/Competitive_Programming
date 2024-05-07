#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> e) {
    const int inf=1e5;

    //topological sort using floyd-warshall algorithm
    vector<vector<int>> v(n+1, vector<int>(n+1, inf));
    for (int i=1; i<=n; i++) v[i][i]=0;
    for (auto i:e) {
        int a=i[0], b=i[1];
        v[a][b]=1;
        v[b][a]=-1;
    }

    //fivot : k
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (i==j || j==k || i==k) continue;
                if (v[i][k]==inf || v[k][j]==inf) continue;
                if (v[i][k]==v[k][j]) {
                    v[i][j]=v[i][k];
                }
            }
        }
    }

    int ret=0;
    for (int i=1; i<=n; i++) {
        bool flag=true;
        for (int j=1; j<=n; j++) {
            if (v[i][j]==inf) flag=false;
        }
        if (flag) ret++;
    }

    return ret;
}