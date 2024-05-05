#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int ret=n;
    
    vector<vector<bool>> con(n, vector<bool>(n, false));
    for (auto i:wires) {
        con[i[0]-1][i[1]-1]=true;
        con[i[1]-1][i[0]-1]=true;
    }   
    
    for (auto edge:wires) {
        vector<bool> vis(n, false);
        function<int(int)> dfs=[&](int now) {
            vis[now]=true;
            int ret=1;
            for (int nxt=0; nxt<n; nxt++) {
                if (con[now][nxt] && !vis[nxt]) {
                    ret+=dfs(nxt);
                }
            }
            return ret;
        };
        
        con[edge[0]-1][edge[1]-1]=false;
        con[edge[1]-1][edge[0]-1]=false;
        ret=min(ret, abs(dfs(edge[0]-1)-dfs(edge[1]-1)));
        con[edge[0]-1][edge[1]-1]=true;
        con[edge[1]-1][edge[0]-1]=true;
    }
    
    return ret;
}