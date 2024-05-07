#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> edge(n);
    for (int i=0; i<n; i++) {
        int a;
        cin >> a;
        edge[i]=a-1;
    }

    vector<int> res(n);
    for (int i=0; i<n; i++) {
        vector<bool> vis(n, false);

        function<int(int)> dfs=[&](int now) {
            if (vis[now]) return 0;
            
            int ret=1;
            vis[now]=true;
            ret+=dfs(edge[now]);

            return ret;
        };

        res[i]=dfs(i);
    }

    int mx=*max_element(res.begin(), res.end());
    for (int i=0; i<n; i++) {
        if (mx==res[i]) {
            cout << i+1;
            break;
        }
    }

    return 0;
}
