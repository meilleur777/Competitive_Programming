#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m, l;
    cin >> n >> m >> l;
    vector<int> v(n+2, 0);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
    }
    v.back()=l;
    sort(v.begin(), v.end());

    int ans=0;
    int left=0, right=l+1;
    while (left+1<right) {
        int mid=(left+right)/2;
        
        int now=0;
        int ptr=1;
        int res=0;
        while (now<l) {
            while (now+mid<v[ptr]) {
                now+=mid;
                res++;
            }
            now=v[ptr];
            ptr++;
        }

        if (res<=m) {
            right=mid;
            ans=mid;
        }
        else {
            left=mid;
        }
    }
    cout << ans;

    return 0;
}
