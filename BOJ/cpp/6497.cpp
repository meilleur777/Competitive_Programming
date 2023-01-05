#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    while (true) {
        cin >> n >> m;
        if (!n && !m) break;

        int allsum=0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        rep(i, m) {
            int x, y, z;
            cin >> x >> y >> z;
            allsum+=z;
            pq.push({z, {x, y}});
        }

        int sum=0;
        vector<int> par(n);
        rep(i, n) par[i]=i;
        function<int(int)> getpar=[&](int x) {
            if (x==par[x]) return x;
            return par[x]=getpar(par[x]);
        };
        function<void(int, int)> merge=[&](int a, int b) {
            a=getpar(a);
            b=getpar(b);
            par[a]=b;
        };

        while (!pq.empty()) {
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int z=pq.top().first;
            pq.pop();
            if (getpar(x)!=getpar(y)) {
                merge(x, y);
                sum+=z;
            }
        }

        cout << allsum-sum << '\n';
    }        

    return 0;
}
