#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    long long n;
    cin >> n;

    vector<int> v;
    for (int i=0; i<10; i++) {
        v.push_back(i);
    }

    long long mx=LLONG_MAX;
    long long ans=0;

    do {
        long long now=0;
        for (int i=0; i<10; i++) {
            now=now*10+v[i];

            if (abs(now-n)<mx) {
                ans=now;
                mx=abs(now-n);
            }
            else if (abs(now-n)==mx) {
                ans=min(ans, now);
            }   

        }
    } while (next_permutation(v.begin(), v.end()));

    cout << ans;

    return 0;
}
