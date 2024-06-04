#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    while (true) {
        int n;
        cin >> n;
        if (n==0) break;
        vector<int> p(n);
        for (int i=0; i<n; i++) cin >> p[i];

        for (int i=1; i<n; i++) {
            if (p[i-1]>0) {
                p[i]+=p[i-1];
            }
        }

        cout << *max_element(p.begin(), p.end()) << '\n';
    }

    return 0;
}
