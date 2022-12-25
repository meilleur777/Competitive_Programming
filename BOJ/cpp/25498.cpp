#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    string alp;
    cin >> alp;
    vector<vector<int>> edge(n);
    rep(i, n-1) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    vector<bool> vis(n, false);
    vector<vector<int>> child(n);
    function<void(int)> maketree=[&](int now) {
        vis[now]=true;
        for (auto nxt:edge[now]) {
            if (vis[nxt]) continue;
            child[now].push_back(nxt);
            maketree(nxt);
        }
    };
    maketree(0);

    string ans;
    ans.push_back(alp[0]);
    queue<int> q;
    q.push(0);
    while (true) {
        vector<int> v;
        while (!q.empty()) {
            int now=q.front();
            q.pop();
            for (auto i:child[now]) v.push_back(i);
        }
        if (v.empty()) break;
        sort(v.begin(), v.end(), [&](const int& qqq, const int& ppp) {
            return alp[qqq]>alp[ppp];
        });
        ans.push_back(alp[v[0]]);
        int ptr=0;
        while (ptr<(int)v.size() && alp[v[0]]==alp[v[ptr]]) {
            q.push(v[ptr]);
            ptr++;
        }
    }
    cout << ans;

    return 0;
}
