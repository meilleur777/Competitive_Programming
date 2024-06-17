#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    vector<int> r(n);
    for (int i=0; i<n; i++) cin >> r[i];

    while (t--) {
        int mx=*max_element(r.begin(), r.end());

        int ind=-1;
        for (int i=0; i<n; i++) {
            if (mx==r[i]) {
                cout << i+1 << '\n';
                ind=i;
                r[i]=0;
                break;
            }
        }

        int ptr=-1;
        while (mx--) {
            ptr++;
            int tgt=ptr%n;
            if (ind==tgt) {
                mx++;
                continue;
            }

            r[tgt]++;
        }
    }   

    return 0;
}
