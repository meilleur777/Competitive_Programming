#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;

    const int bound=1e5+1;
    const int inf=0x3f3f3f3f;
    
    vector<int> vis(bound, inf);
    vis[n]=0;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int tmp;
        if ((tmp=now-1)>=0 && vis[tmp]>vis[now]+1) { 
            vis[tmp]=vis[now]+1;
            q.push(tmp);
        }
        if ((tmp=now+1)<bound && vis[tmp]>vis[now]+1) { 
            vis[tmp]=vis[now]+1;
            q.push(tmp);
        }
        if ((tmp=now*2)<bound && vis[tmp]>vis[now]) { 
            vis[tmp]=vis[now];
            q.push(tmp);
        }
    }

    cout << vis[k];

    return 0;
}
