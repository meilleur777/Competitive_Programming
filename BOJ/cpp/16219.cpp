#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;

    int cnt=0;
    vector<int> v(n);
    for (int i=0; i<n; i++) {
        cin >> v[i];
        cnt+=v[i]!=i;
    }

    int m;
    cin >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;

        if (a!=b) {
            if (v[a]!=a) cnt--;
            if (v[b]!=b) cnt--;
        }
        swap(v[a], v[b]);
        if (a!=b) {
            if (v[a]!=a) cnt++;
            if (v[b]!=b) cnt++;
        }

        int ans=-1;
        if (n==1) ans=0;
        else if (n==2) {
            if (cnt==0) ans=0;
            else ans=1;
        }
        else {
            if (cnt==0) ans=0;
            else ans=-1;
        }

        cout << ans << ' ';
    } 

    return 0;
}
