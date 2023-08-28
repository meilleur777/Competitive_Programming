#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    vector<ll> neg, negone, zero, posone, pos;
    for (int i=0; i<n; i++) {
        if (v[i]<0) neg.push_back(v[i]);
        else if (v[i]==0) zero.push_back(v[i]);
        else if (v[i]==1) posone.push_back(v[i]);
        else pos.push_back(v[i]);
    }

    ll ans=0;
    for (int i=0; i+1<(int)neg.size(); i+=2) {
        ans+=neg[i]*neg[i+1];
    }
    for (int i=(int)pos.size()-1; i-1>=0; i-=2) {
        ans+=pos[i]*pos[i-1];
    }
    if (((int)pos.size())%2) ans+=pos[0];
    ans+=(int)posone.size();
    if (((int)neg.size())%2) {
        if (zero.empty()) ans+=neg.back();
    }
    cout << ans;

    return 0;
}
