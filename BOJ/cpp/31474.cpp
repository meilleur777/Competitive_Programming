#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    long long ans=1;
    for (int i=n; i>n/2; i--) {
        ans*=i;
    }
    ans/=(1LL<<(n/2));

    cout << ans;

    return 0;
}
