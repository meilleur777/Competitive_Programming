#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> h(1e4, -1);
    for (int i=0; i<m; i++) {
        for (int j=0; j<2; j++) {
            int a;
            cin >> a;
            a--;
            h[a]=i;
        }
    }

    queue<int> q;
    for (int i=0; i<1e4; i++) {
        if (h[i]==-1) continue;
        q.push(h[i]);
    }

    while (n--) {
        int now=q.front();
        q.pop();
        q.push(now);
    }
    cout << q.back()+1;

    return 0;
}
