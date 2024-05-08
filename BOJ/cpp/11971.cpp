#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> limit(101), speed(101);

    int now=0;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        int tmp=now;
        now+=a;
        for (int j=tmp; j<now; j++) {
            limit[j]=b;
        }
    }

    now=0;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        int tmp=now;
        now+=a;
        for (int j=tmp; j<now; j++) {
            speed[j]=b;
        }
    }

    int ans=0;
    for (int i=0; i<100; i++) {
        ans=max(ans, max(0, speed[i]-limit[i]));
    }
    cout << ans;

    return 0;
}
