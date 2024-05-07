#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<long long, long long>> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i].first;
    }
    for (int i=0; i<n; i++) {
        cin >> v[i].second;
    }

    auto vcpr=[&](pair<int, int> p, pair<int, int> q) { return p.second < q.second; };
    sort(v.begin(), v.end(), vcpr);

    long long last=0;
    int ptr=0;
    long long ans=0;
    while (ptr<n) {
        auto pqcpr=[&](int p, int q) { return v[p].first>v[q].first; };
        priority_queue<int, vector<int>, decltype(pqcpr)> pq(pqcpr);
        int tmp=ptr;
        while (v[tmp].second==v[ptr].second) {
            pq.push(ptr);
            ptr++;
        }

        while (v[pq.top()].first<last) {
            auto pqtmp=pq.top();
            pq.pop();
            int tttt=v[pqtmp].first;
            v[pqtmp].first=tttt+(last-tttt+29)/30*30;
            ans+=(last-tttt+29)/30;
            pq.push(pqtmp);
        }
        while (v[pq.top()].first<v[tmp].second) {
            auto pqtmp=pq.top();
            pq.pop();
            int tttt=v[pqtmp].first;
            v[pqtmp].first=tttt+(v[tmp].second-tttt+29)/30*30;
            ans+=(v[tmp].second-tttt+29)/30;
            pq.push(pqtmp);
        }

        while (!pq.empty()) {
            last=max(last, v[pq.top()].first);
            pq.pop();
        }
    }  
    cout << ans;

    return 0;
}
