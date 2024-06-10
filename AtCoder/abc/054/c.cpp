#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> edge(n, vector<bool>(n, false));
    while (m--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a][b]=true;
        edge[b][a]=true;
    }

    vector<int> tmp;
    for (int i=0; i<n; i++) tmp.push_back(i);

    int ans=0;
    do {
        bool flag=true;
        for (int i=0; i<n-1; i++) {
            if (edge[tmp[i]][tmp[i+1]]==false) {
                flag=false;
                break;
            }
        }
        ans+=flag;
    } while (next_permutation(tmp.begin()+1, tmp.end()));

    cout << ans;
 
    return 0;
}
