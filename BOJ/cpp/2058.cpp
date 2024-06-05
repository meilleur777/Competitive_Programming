#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    map<int, int> nodeToNum;
    map<int, int> numToNode;

    vector<int> node(n);
    for (int i=0; i<n; i++) {
        cin >> node[i];
    }

    sort(node.begin(), node.end());
    for (int i=0; i<n; i++) {
        nodeToNum[node[i]]=i;
        numToNode[i]=node[i];
    }

    vector<vector<bool>> edge(n, vector<bool>(n, false));

    for (int i=0; i<m; i++) {
        int w;
        cin >> w;
        for (int j=0; j<n; j++) {
            int node=numToNode[j];
            if (nodeToNum.find(node+w)!=nodeToNum.end()) {
                edge[j][nodeToNum[node+w]]=true;
                edge[nodeToNum[node+w]][j]=true;
            }
        }
    }

    int ans=0;
    vector<vector<int>> cache(n, vector<int>(2, -1));
    function<int(int, int, bool)> dp=[&](int now, int par, bool selected) {
        int& ret=cache[now][selected];
        if (ret!=-1) return ret;

        ret=selected*numToNode[now];
        for (int nxt=0; nxt<n; nxt++) {
            if (!edge[now][nxt]) continue;
            if (par==nxt) continue;

            if (selected) {
                ret+=dp(nxt, now, false);
            }
            else {
                ret+=max(dp(nxt, now, false), dp(nxt, now, true));
            }
        }

        return ret;
    };
    ans+=max(dp(0, -1, true), dp(0, -1, false));

    cout << ans;

    return 0;
}
