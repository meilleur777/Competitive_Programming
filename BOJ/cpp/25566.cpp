#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;
typedef pair<intp, int> ppp;

struct cpr {
    bool operator()(const ppp& p, const ppp& q) {
        return p.first.first>q.first.first;
    }
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<intp, int>> v(n);
    rep(i, n) cin >> v[i].first.first >> v[i].first.second >> v[i].second;

    set<int> st;
    rep(i, n) {
        st.insert(v[i].first.second);
    }
    map<int, int> mp;
    int num=1;
    ll memo=-1;
    for (auto i=st.begin(); i!=st.end(); i++) {
        if (i!=st.begin()) {
            if (memo!=*i) num++;
        }
        mp[*i]=num;
        memo=*i;
    }
    for (int i=0; i<n; i++) {
        v[i].first.second=mp[v[i].first.second];
    }

    sort(v.begin(), v.end());

    vector<ll> tree(num+1, 0);
    priority_queue<ppp, vector<ppp>, cpr> pq;

    function<void(int, ll)> update=[&](int index, ll value) {
        for (; index<=num; index+=(index&(-index))) {
            tree[index]+=value;
        }
    };
    function<ll(int)> sum=[&](int index) {
        ll ret=0;
        for (; index>0; index-=(index&(-index))) {
            ret+=tree[index];
        }
        return ret;
    };
    function<ll(int, int)> getsum=[&](int start, int end) {
        return sum(end)-sum(start-1);
    };

    for (int i=0; i<n; i++) {
        update(v[i].first.second, v[i].second);
        pq.push(v[i]);
    }
    ll ans=0;
    for (int i=0; i<n; i++) {
        while (!pq.empty() && pq.top().first.first<v[i].first.first) {
            auto t=pq.top();
            update(t.first.second, -t.second);
            pq.pop();
        }
        ans=max(ans, getsum(1, v[i].first.second));
    }

    cout << ans;

    return 0;
}
