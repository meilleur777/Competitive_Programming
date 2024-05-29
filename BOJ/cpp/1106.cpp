#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int c, n;
    cin >> c >> n;
    vector<int> cost(n), reward(n);
    for (int i=0; i<n; i++) {
        cin >> cost[i] >> reward[i];
    }

    const int inf=0x3f3f3f3f;
    vector<int> cache(c+101, inf);
    cache[0]=0;
    for (int i=0; i<n; i++) {
        for (int j=c+100; j>=0; j--) {
            for (int k=j/reward[i]; k>0; k--) {
                cache[j]=min(cache[j], cache[j-reward[i]*k]+cost[i]*k);
            }
        }
    }

    cout << *min_element(cache.begin()+c, cache.end());

    return 0;
}
