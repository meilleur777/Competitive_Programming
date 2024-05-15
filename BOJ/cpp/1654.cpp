#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int k, n;
    cin >> k >> n;
    vector<long long> v(k);
    for (int i=0; i<k; i++) cin >> v[i];

    long long ans=0;
    long long left=0, right=*max_element(v.begin(), v.end())+1;
    
    while (left+1<right) {
        long long mid=(left+right)/2;

        long long cnt=0;
        for (int i=0; i<k; i++) {
            cnt+=v[i]/mid;
        }

        if (cnt>=n) {
            ans=mid;
            left=mid;
        }
        else right=mid;
    }

    cout << ans;

    return 0;
}
