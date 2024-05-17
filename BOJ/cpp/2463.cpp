#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pint;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    priority_queue<pint> pq;
    while (m--) {
        int x, y, w;
        cin >> x >> y >> w;
        x--, y--;
        pq.push({w, {x, y}});
    }

    vector<long long> componentSize(n, 1);
    vector<int> rank(n, 0);
    vector<int> par(n);
    for (int i=0; i<n; i++) par[i]=i;
    function<int(int)> find=[&](int x) {
        if (x==par[x]) return x;
        return find(par[x]);
    };
    function<void(int, int)> merge=[&](int a, int b) {
        int aa=find(a), bb=find(b);
        if (aa==bb) return;
        if (rank[aa]<rank[bb]) swap(aa, bb);
        if (rank[aa]==rank[bb]) rank[aa]++;
        par[bb]=aa;
        componentSize[aa]+=componentSize[bb];
    };

    long long ans=0;
    long long mod=1e9;
    long long possiblePair=0;
    while (!pq.empty()) {
        int cost=pq.top().first;
        auto [a, b]=pq.top().second;
        pq.pop();

        int aa=find(a);
        int bb=find(b);

        function<long long(long long)> xC2=[](long long x) {
            return x*(x-1)/2;
        };

        if (aa!=bb) {
            possiblePair-=xC2(componentSize[aa])+xC2(componentSize[bb]);
            merge(a, b);
            possiblePair+=xC2(componentSize[find(a)]);
        }

        possiblePair%=mod;
        ans=(ans+(cost*possiblePair%mod))%mod;
    }

    cout << ans;

    return 0;
}
