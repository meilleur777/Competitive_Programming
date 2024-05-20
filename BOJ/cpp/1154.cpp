#include <bits/stdc++.h>
using namespace std;

//Two Clique problem
//Check if Graph can be devided into two Cliques
//Clique := subgraph of graph such that
//          all vertices in subgraph are completely connected with each other
//Check if complement of Graph is Bipartite
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<vector<bool>> edge(n, vector<bool>(n, false));
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a==-1 && b==-1) break;
        a--, b--;
        edge[a][b]=true;   
        edge[b][a]=true;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            edge[i][j]=!edge[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        edge[i][i]=false;
    }

    vector<int> color(n, -1);
    function<void(int, int)> makeBipartite=[&](int now, int toColor) {
        color[now]=toColor;

        for (int nxt=0; nxt<n; nxt++) {
            if (edge[now][nxt]==false) continue;

            if (color[nxt]==-1) makeBipartite(nxt, 1-toColor);
            else if (color[nxt]!=toColor) continue;
            else if (color[nxt]==toColor) {
                cout << -1;
                exit(0);
            }
        }
    };  
    for (int i=0; i<n; i++) {
        if (color[i]==-1) {
            makeBipartite(i, 0);
        }
    }

    cout << 1 << '\n';
    vector<vector<int>> ans(2);
    for (int i=0; i<n; i++) {
        ans[color[i]].push_back(i+1);
    }
    for (auto v:ans) {
        for (auto i:v) cout << i << ' ';
        cout << -1 << '\n';
    }


    return 0;
}
