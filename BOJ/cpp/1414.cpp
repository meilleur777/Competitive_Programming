#include <bits/stdc++.h>
using namespace std;

int find(int x, const vector<int>& par) {
    if (x==par[x]) return x;
    return find(par[x], par);
}

bool merge(int a, int b, vector<int>& par) {
    int aa=find(a, par), bb=find(b, par);
    if (aa==bb) return false;
    par[bb]=aa;
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;

    auto cpr=[&](const vector<int>& p, const vector<int>& q) {
        return p[2]>q[2];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cpr)> pq(cpr);
    int weightSum=0;
    for (int i=0; i<n; i++) {
        string s;
        cin >> s;
        for (int j=0; j<n; j++) {
            int weight=0;
            if (isupper(s[j])) weight=s[j]-'A'+27;
            else if (islower(s[j])) weight=s[j]-'a'+1;
            else continue;

            weightSum+=weight;
            pq.push({i, j, weight});
            pq.push({j, i, weight});
        }
    }

    vector<int> par(n, -1);
    for (int i=0; i<n; i++) par[i]=i;

    while (!pq.empty()) {
        int a=pq.top()[0];
        int b=pq.top()[1];
        int weight=pq.top()[2];
        pq.pop();
        if (merge(a, b, par)) weightSum-=weight;
    }

    bool flag=true;
    for (int i=1; i<n; i++) {
        if (find(i, par)!=find(0, par)) flag=false;
    }

    if (flag) cout << weightSum;
    else cout << -1;

    return 0;
}
