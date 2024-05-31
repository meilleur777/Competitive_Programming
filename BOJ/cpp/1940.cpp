#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }

    vector<int> cnt(1e5+1, 0);
    for (int i=0; i<n; i++) {
        cnt[a[i]]++;
    }

    int ans=0;
    for (int i=1; i<=1e5; i++) {
        if (m-i>1e5 || m-i<1) continue;

        if (cnt[i]>0 && cnt[m-i]>0) {
            int tmp=min(cnt[i], cnt[m-i]);
            if (i*2==m) {
                tmp=cnt[i]/2;
            }
            ans+=tmp;
            cnt[i]-=tmp;
            cnt[m-i]-=tmp;
        }
    }

    cout << ans;

    return 0;
}
