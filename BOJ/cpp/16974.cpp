#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    vector<long long> siz(51, 1), p(51, 1);
    for (int i=1; i<=50; i++) siz[i]=siz[i-1]*2+3;
    for (int i=1; i<=50; i++) p[i]=p[i-1]*2+1;
    
    int n;
    long long x;
    cin >> n >> x;

    long long ans=0;
    function<void(int, long long)> sol=[&](int n, long long x) {
        if (n==0) {
            ans++;
            return;
        }
        if (x==1) return;

        if (x>=2 && x<=siz[n-1]+1) {
            sol(n-1, x-1);
        }
        else if (x==siz[n-1]+2) {
            ans+=p[n-1]+1;
        }
        else if (x>=siz[n-1]+3 && x<=siz[n-1]*2+2) {
            ans+=p[n-1]+1;
            sol(n-1, x-(siz[n-1]+2));
        }
        else if (x==siz[n]) {
            ans+=p[n];
        }
    };
    sol(n, x);

    cout << ans;

    return 0;
}
