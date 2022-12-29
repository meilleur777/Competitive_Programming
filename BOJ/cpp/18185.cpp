#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, 2) a.push_back(0);

    int ans=0;
    for (int i=0; i<n+2; i++) {
        function<void()> three=[&]() {
            int t=min({a[i], a[i+1], a[i+2]});
            a[i]-=t;
            a[i+1]-=t;
            a[i+2]-=t;
            ans+=t*7;
        };
        function<void(int, int)> two=[&](int aaa, int bbb) {
            int t=min(aaa, bbb);
            a[i]-=t;
            a[i+1]-=t;
            ans+=t*5;
        };
        if (a[i+1]>a[i+2]) {
            two(a[i], a[i+1]-a[i+2]);
            three();
        }
        else {
            three();
            two(a[i], a[i+1]);
        }
        ans+=a[i]*3;
    }
    cout << ans;

    return 0;
}
