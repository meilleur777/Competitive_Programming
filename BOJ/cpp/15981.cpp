#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    int k=ceil(log2(n));

    cout << k << '\n';
    for (int i=0; i<k; i++) {
        vector<int> v;
        for (int j=1; j<=n; j++) {
            if (j&(1<<i)) {
                v.push_back(j);
            }
        }

        cout << (int)v.size() << ' ';
        for (auto j:v) cout << j << ' ';
        cout << '\n';
    }

    return 0;
}
