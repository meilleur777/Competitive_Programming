#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];

    vector<int> cache(n, 1);
    cache[0]=1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<i; j++) {
            if (a[j]<a[i]) {
                cache[i]=max(cache[i], cache[j]+1);
            }
        }
    }

    cout << *max_element(cache.begin(), cache.end());

    return 0;
}
