#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    ll ans=0;
    for (int i=1; i<=n; i++) {
        ans+=2*i-1;
    }
    for (int i=1; i<n; i++) {
        for (int j=1; j<=i; j++) {
            ans+=j;
        }
    }
    if (n%2) {
        for (int i=1; i<n/2; i++) {
            for (int j=1; j<=i*2; j++) {
                ans+=j;
            }
        }
    }
    else {
        for (int i=1; i<n/2; i++) {
            for (int j=1; j<i*2; j++) {
                ans+=j;
            }
        }
    }
    cout << ans;

    return 0;
}
